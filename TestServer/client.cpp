#include "client.h"

Client::Client(QObject *parent, QTcpSocket *sock) : QObject(parent), socket(sock)
{
    \
}

QTcpSocket *Client::getSocket()
{
    return socket;
}
