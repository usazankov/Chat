#include "client.h"

Client::Client(QObject *parent, QTcpSocket *sock) : QObject(parent), socket(sock)
{
    connect(socket, SIGNAL(readyRead()), this, SLOT(onReadyRead()));
    connect(socket, SIGNAL(disconnected()), this, SLOT(onDisconnected()));
}

QTcpSocket *Client::getSocket()
{
    return socket;
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
    emit disconnected(idUser);
}

void Client::onResultReady(const QByteArray &arr, const QVariantMap &params)
{
    emit sendToClients(idUser, params, arr);
}
