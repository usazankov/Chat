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

bool Client::isAuthenticated(const ClientCommand &com)
{
    if(com.type == server_consts::AuthenticationClient){
        if(com.result == server_consts::SUCCESS){
            d_ptr->isAuth = true;
            QString userId = com.params[chat::USER_ID].toString();
            if(!userId.isNull())
                d_ptr->server->addClient(userId, this);
        }
        writeToSocket(com.data);
    }
    return d_ptr->isAuth;
}

void Client::writeToSocket(const QByteArray &req)
{
    socket->write(req);
}

Client::Client(ClientPrivate &dd, QObject *parent):QObject(parent),d_ptr(&dd)
{

}

void Client::onServerEvent(const ServerEvent &event)
{
    QFutureWatcher<ClientCommand> *watcher = new QFutureWatcher<ClientCommand>;
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
            qDebug() << "Readed:";
            qDebug() << arr;
            m_msgSize = -1;
            QFutureWatcher<ClientCommand> *watcher = new QFutureWatcher<ClientCommand>;
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
    QFutureWatcher<ClientCommand> *watcher = static_cast<QFutureWatcher<ClientCommand>*>(sender());
     Q_ASSERT(watcher);
    ClientCommand com = watcher->result();
    if(!isAuthenticated(com))
        return;
    if(com.type == server_consts::SendToThisClient){
        writeToSocket(com.data);
        return;
    }
    d_ptr->server->executeCommand(com);
}
