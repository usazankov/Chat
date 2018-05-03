#include "client.h"

Client::Client(QTcpSocket *sock) : socket(sock)
{
    connect(socket,SIGNAL(disconnected()))
}

QTcpSocket *Client::getSocket()
{
    return socket;
}
