#include "server.h"

Server::Server(QObject *parent) : QObject(parent)
{
    m_ptcpServer.reset(new QTcpServer);
}

void Server::onNewConnection()
{
    Client *client = new Client(m_ptcpServer->nextPendingConnection());
    connect(client,SIGNAL(authenticated(QString, Client*)),SLOT(onAuthenticated(QString,Client*)));
    connect(client,SIGNAL(disconnected(QString)),SLOT(onDisconnected(QString)));
}

void Server::startServer(const QHostAddress &address, quint16 port)
{
    connect(m_ptcpServer, SIGNAL(newConnection()), SLOT(onNewConnection()));
    if(!m_ptcpServer->listen(address, port)){
        m_ptcpServer->close();
        throw m_ptcpServer->errorString();
    }
}

void Server::onAuthenticated(const QString &idUser, Client *client)
{
    m_sockets[idUser] = client->getSocket();
    connect(client,SIGNAL(sendToAll(QByteArray)),SLOT(onSendToAllUsers(QByteArray)));
    connect(client,SIGNAL(sendToUser(QString,QByteArray)),SLOT(onSendToUser(QString,QByteArray)));
    connect(client,SIGNAL(sendToListUsers(QStringList,QByteArray)),SLOT(onSendToListUsers(QStringList,QByteArray)));
}

void Server::onSendToAllUsers(const QByteArray &request)
{

}

void Server::onSendToUser(const QString &idUser, const QByteArray &request)
{

}

void Server::onSendToListUsers(const QStringList &listIdUsers, const QByteArray &request)
{

}

void Server::onDisconnected(const QString &idUser)
{

}
