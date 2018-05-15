#include "client.h"

Client::Client(Server *server, QTcpSocket *sock) : QObject(server), socket(sock), d_ptr(new ClientPrivate())
{
    d_ptr->q_ptr = this;
    d_ptr->server = server;
    d_ptr->isAuth = false;
}

QTcpSocket *Client::getSocket()
{
    return socket;
}

Client::~Client()
{
    delete d_ptr;
}

void Client::runWorker(Worker *worker)
{
    connect(worker, SIGNAL(result(ClientCommand)),this,SLOT(onResultReady(ClientCommand)));
    QThreadPool::globalInstance()->start(worker);
}

bool Client::isAuthenticated(const ClientCommand &com)
{
    if(com.type == server_consts::AuthenticationClient){
        if(com.result == server_consts::SUCCESS){
            d_ptr->isAuth = true;
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
    Worker *worker = new Worker(event, this);
    runWorker(worker);
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
            QByteArray arr = socket->readAll();
            m_msgSize = -1;
            Worker *worker = new Worker(arr,this);
            runWorker(worker);
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

void Client::onResultReady(const ClientCommand &com)
{
    if(!isAuthenticated(com))
        return;
    if(com.type == server_consts::SendToThisClient){
        writeToSocket(com.data);
        return;
    }
    d_ptr->server->executeCommand(com);
}
