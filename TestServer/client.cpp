#include "client.h"

Client::Client(QObject *parent, QTcpSocket *sock) : QObject(parent), socket(sock), d_ptr(new ClientPrivate())
{
    d_ptr->q_ptr = this;
}

QTcpSocket *Client::getSocket()
{
    return socket;
}

void Client::serUsersList(const QStringList &list)
{
    d_ptr->users = list;
}

Client::~Client()
{
    delete d_ptr;
}

Client::Client(ClientPrivate &dd, QObject *parent):QObject(parent),d_ptr(&dd)
{

}

void Client::onUserLeft(const QString &idUser)
{

}

void Client::onUserConnect(const QString &idUser)
{

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
            connect(worker, SIGNAL(result(QByteArray,QVariantMap)),this,SLOT(onResultReady(QByteArray,QVariantMap)));
            QThreadPool::globalInstance()->start(worker);
        }
    }
}

void Client::onDisconnected()
{
    emit disconnected(d_ptr->idUser);
}

void Client::onResultReady(const QByteArray &arr, const QVariantMap &params)
{
    if(!d_ptr->isAuth){
        return;
    }
    emit sendToClients(d_ptr->idUser, params, arr);
}
