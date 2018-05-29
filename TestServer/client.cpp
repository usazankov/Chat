#include "client.h"

Client::Client(Server *server, QTcpSocket *sock) : QObject(server), socket(sock), d_ptr(new ClientPrivate())
{
    d_ptr->q_ptr = this;
    d_ptr->server = server;
    d_ptr->isAuth = false;
    connect(socket,SIGNAL(readyRead()),this,SLOT(onReadyRead()));
    connect(socket,SIGNAL(disconnected()),this,SLOT(onDisconnected()));
    m_msgSize = -1;
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
    if(!isAuthenticated(*com)){
        writeToSocket(Worker::createRespToNotAuth().toRequest());
        return;
    }
    if(com->type == server_consts::SendToThisClient){
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

bool Client::isAuthenticated(const ClientCommand &com)
{
    if(com.type == server_consts::AuthenticationClient){
        if(com.result == server_consts::SUCCESS){
            QString userId = com.params[chat::USER_ID].toString();
            if(userId.isNull())
                return false;
            d_ptr->isAuth = true;
            d_ptr->idUser = userId;
            d_ptr->server->addClient(userId, this);

            //После успешной авторизации возвращаем список пользователей
            getUsersList();
        }
        writeToSocket(com.data.toRequest());
    }
    return d_ptr->isAuth;
}

void Client::writeToSocket(const QByteArray &req)
{
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

Client::Client(ClientPrivate &dd, QObject *parent):QObject(parent),d_ptr(&dd)
{

}

void Client::onServerEvent(const ServerEvent &event)
{
    if(!filterEvent(event))
        return;
    QFutureWatcher<ClientCommandPtr> *watcher = new QFutureWatcher<ClientCommandPtr>;
    connect(watcher, SIGNAL(finished()), this, SLOT(onResultReady()));
    watcher->setFuture(QtConcurrent::run(Worker::executeServerEvent, event));
}

void Client::onReadyRead()
{
    QDataStream stream(socket);
    while(true) {
        if (m_msgSize < 0) {
            if (socket->bytesAvailable() < sizeof(int))
                return;
            stream >> m_msgSize;
        }
        else {
            if (socket->bytesAvailable() < m_msgSize)
                return;
            QByteArray arr = socket->read(m_msgSize);
            QDateTime dt = QDateTime::currentDateTime();

            std::cout << "Time: "<<dt.toString(Qt::SystemLocaleDate).toStdString() <<" Received request " << m_msgSize <<" Byte:\n";
            std::cout << arr.toStdString() << "\n";
            m_msgSize = -1;
            QFutureWatcher<ClientCommandPtr> *watcher = new QFutureWatcher<ClientCommandPtr>;
            connect(watcher, SIGNAL(finished()), this, SLOT(onResultReady()));
            watcher->setFuture(QtConcurrent::run(Worker::executeClientRequest, arr));
        }
    }
}

void Client::onDisconnected()
{
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
