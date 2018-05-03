#include "server.h"

Server::Server(QObject *parent) : IServer(parent)
{
    m_ptcpServer.reset(new QTcpServer);
}

void Server::onNewConnection()
{

}

void Server::startServer(const QHostAddress &address, quint16 port)
{
    connect(m_ptcpServer, SIGNAL(newConnection()), SLOT(onNewConnection()));
    if(!m_ptcpServer->listen(address, port)){
        m_ptcpServer->close();
        throw m_ptcpServer->errorString();
    }
}

QList<QTcpSocket *> Server::listSockets()
{

}

void Server::sendToAllSockets(const QByteArray &request)
{

}

void Server::sendToSocket(QTcpSocket *socket, const QByteArray &request)
{

}

void Server::sendToListSockets(QList<QTcpSocket *>, const QByteArray &request)
{

}
