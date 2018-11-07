#include "client.h"

Client::Client(Server *server, QTcpSocket *sock) : QObject(server), socket(sock), d_ptr(new ClientPrivate())
{
    d_ptr->q_ptr = this;
    d_ptr->server = server;
    d_ptr->isAuth = false;
    d_ptr->filter = new RequestFilter;
    d_ptr->filter->setExceededTick(0);
    d_ptr->filter->setExceededLimitFailReq(5);
    connect(socket,SIGNAL(readyRead()),this,SLOT(onReadyRead()), Qt::QueuedConnection);
    connect(socket,SIGNAL(disconnected()),this,SLOT(onDisconnected()));
    m_msgSize = -1;
#ifdef TEST
    d_ptr->isAuth = true;
    d_ptr->idUser = "Test_user";
    d_ptr->server->addClient("Test_user", this);
#endif
}

QTcpSocket *Client::getSocket()
{
    return socket;
}

Client::~Client()
{
    delete d_ptr;
}

void Client::execute(ClientCommandPtr com)
{
    if(com.isNull())
        return;
    if(!isAuthenticated()){
        if(com->type != server_consts::AuthenticationClient){
            writeToSocket(Worker::createRespToNotAuth().toRequest());
            return;
        }
    }
    if(com->type == server_consts::AuthenticationClient){
        authHandle(*com);
    }else if(com->type == server_consts::SendToThisClient){
        writeToSocket(com->data.toRequest());
    }else if(com->type == server_consts::SendToAllClient ||
             com->type == server_consts::SendToListClient){
        if(d_ptr->server->executeCommand(d_ptr->idUser, *com)){
            //В случае успеха выполнения команду успеха
            if(!com->com_onSuccess.isNull()){
                if(com->com_onSuccess->type == server_consts::SendToThisClient){
                    writeToSocket(com->com_onSuccess->data.toRequest());
                }else{
                    d_ptr->server->executeCommand(d_ptr->idUser, *com->com_onSuccess);
                }
            }
        }else{
            //В случае ошибки - команду ошибки
            if(!com->com_onError.isNull()){
                if(com->com_onError->type == server_consts::SendToThisClient){
                    writeToSocket(com->com_onError->data.toRequest());
                }else{
                    d_ptr->server->executeCommand(d_ptr->idUser, *com->com_onError);
                }
            }
        }
    }
}

bool Client::isAuthenticated()
{
    return d_ptr->isAuth;
}

void Client::writeToSocket(const QByteArray &req)
{
    std::cout << "Time: "<<QDateTime::currentDateTime().toString(Qt::SystemLocaleDate).toStdString() <<" Send response " << req.size() <<" Byte:\n";
    std::cout << req.toStdString() << "\n";
    socket->write(req);
}

bool Client::filterEvent(const ServerEvent &event)
{
    if(d_ptr->idUser.isEmpty())
        return false;
    if(event.data[chat::USER_ID] == d_ptr->idUser && (
                event.type == ServerEvent::ConnectedUser || event.type == ServerEvent::DisconnectedUser)) //Информацию о самом себе не отправляем
        return false;
    return true;
}

void Client::getUsersList()
{
    ServerEvent event;
    event.type = ServerEvent::GetListUsers;
    event.data[chat::USER_ID] = d_ptr->idUser;
    onServerEvent(event);
}

void Client::authHandle(const ClientCommand &com)
{
    if(com.type == server_consts::AuthenticationClient){
        if(com.result == server_consts::SUCCESS){
            QString userId = com.params[chat::USER_ID].toString();
            d_ptr->isAuth = true;
            d_ptr->idUser = userId;
            d_ptr->server->addClient(userId, this);
            getUsersList();
        }
        writeToSocket(com.data.toRequest());
    }
}

Client::Client(ClientPrivate &dd, QObject *parent):QObject(parent),d_ptr(&dd)
{

}

void Client::onServerEvent(const ServerEvent &event)
{
    if(!filterEvent(event))
        return;
    QFutureWatcher<ClientCommandPtr> *watcher = new QFutureWatcher<ClientCommandPtr>;
    connect(watcher, SIGNAL(finished()), this, SLOT(onResultReady()));
    watcher->setFuture(QtConcurrent::run(QThreadPool::globalInstance(), Worker::executeServerEvent, event));
}

void Client::onReadyRead()
{
    QDataStream stream(socket);
    static bool isRunning = true;
    if(!isRunning)return;
    while(true) {
        if (m_msgSize < 0) {
            if (socket->bytesAvailable() < sizeof(int))
                return;
            RequestFilter::CheckResult res = d_ptr->filter->check();
            if(res == RequestFilter::SEND_FAIL){
                writeToSocket(Worker::createRespToTimeout().toRequest());
            }else if(res == RequestFilter::NEED_DISCONNECT){
                socket->close();
                isRunning = false;
                return;
            }
            stream >> m_msgSize;
        }
        else {
            std::cout<< "bytesAvailable: " << socket->bytesAvailable() <<"\n";
            std::cout<< "m_msgSize: " << m_msgSize <<"\n";
            if (socket->bytesAvailable() < m_msgSize)
                return;
            QByteArray arr = socket->read(m_msgSize);
            d_ptr->filter->updateStatus(RequestFilter::Request);
            QDateTime dt = QDateTime::currentDateTime();

            std::cout << "Time: "<<dt.toString(Qt::SystemLocaleDate).toStdString() <<" Received request " << m_msgSize <<" Byte:\n";
            std::cout << arr.toStdString() << "\n";

            m_msgSize = -1;
            QFutureWatcher<ClientCommandPtr> *watcher = new QFutureWatcher<ClientCommandPtr>;
            connect(watcher, SIGNAL(finished()), this, SLOT(onResultReady()), Qt::QueuedConnection);
            watcher->setFuture(QtConcurrent::run(Worker::executeClientRequest, arr));
        }
    }
}

void Client::onDisconnected()
{
    std::cout<< "client disconnected\n";
    if(isAuthenticated()){
        d_ptr->server->removeClient(d_ptr->idUser);
    }
    deleteLater();
}

void Client::onResultReady()
{
    QFutureWatcher<ClientCommandPtr> *watcher = static_cast<QFutureWatcher<ClientCommandPtr>*>(sender());
    Q_ASSERT(watcher);
    if(!watcher)
        return;
    if(!watcher->result())
        return;
    execute(watcher->result());
    watcher->deleteLater();
}
