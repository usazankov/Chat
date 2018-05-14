#include "server.h"

Server::Server(QObject *parent) : QObject(parent)
{
    m_ptcpServer.reset(new QTcpServer);
}

void Server::onNewConnection()
{
    Client *client = new Client(this, m_ptcpServer->nextPendingConnection());
    connect(this,SIGNAL(serverEvent(ServerEvent)),client,SLOT(onServerEvent(ServerEvent)));
}

void Server::startServer(const QHostAddress &address, quint16 port)
{
    connect(m_ptcpServer.data(), SIGNAL(newConnection()),this, SLOT(onNewConnection()));
    if(!m_ptcpServer->listen(address, port)){
        m_ptcpServer->close();
        throw m_ptcpServer->errorString();
    }
}

void Server::addClient(const QString &idUser, Client *client)
{
    m_sockets[idUser] = client->getSocket();
    ServerEvent event;
    event.type = ServerEvent::ConnectedUser;
    event.data[server_consts::ID_USER] = QVariant(idUser);
    emit serverEvent(event);
}

void Server::removeClient(const QString &idUser)
{
    m_sockets.remove(idUser);
    ServerEvent event;
    event.type = ServerEvent::DisconnectedUser;
    event.data[server_consts::ID_USER] = QVariant(idUser);
    emit serverEvent(event);
}

void Server::executeCommand(const ClientCommand &com)
{

}
