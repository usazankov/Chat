#include "server.h"

Server::Server(QObject *parent) : QObject(parent)
{
    m_ptcpServer.reset(new QTcpServer);
}

void Server::onNewConnection()
{
    Client *client = new Client(this, m_ptcpServer->nextPendingConnection());
    connect(client,SIGNAL(authenticated(QString, Client*)),SLOT(onAuthenticated(QString,Client*)));
    connect(client,SIGNAL(disconnected(QString)),SLOT(onDisconnected(QString)));
}

void Server::startServer(const QHostAddress &address, quint16 port)
{
    connect(m_ptcpServer.data(), SIGNAL(newConnection()),this, SLOT(onNewConnection()));
    if(!m_ptcpServer->listen(address, port)){
        m_ptcpServer->close();
        throw m_ptcpServer->errorString();
    }
}

void Server::onAuthenticated(const QString &idUser, Client *client)
{
    m_sockets[idUser] = client->getSocket();
    //GlobalStorage::instance()
    connect(client,SIGNAL(sendToClients(QString,QVariantMap,QByteArray)),SLOT(onSendToClients(QString,QVariantMap,QByteArray)));
}

void Server::onSendToClients(const QString &from, const QVariantMap &params, const QByteArray &request)
{

}

void Server::onDisconnected(const QString &idUser)
{
    m_sockets.remove(idUser);
}
