#include "chatnetworkmanager.h"

ChatNetworkManager::ChatNetworkManager(int socketDescriptor, QObject *parent) : QObject(parent)
{
    socket = new QTcpSocket(this);
    if(socketDescriptor){
        socket->setSocketDescriptor(socketDescriptor);
    }
    initChat();
}

ChatResponse * ChatNetworkManager::execute(ChatRequest * request)
{

    sendData(request);
}

void ChatNetworkManager::connectToChat(const QHostAddress &address, quint16 port)
{
    this->address = address;
    this->port = port;
    socket->connectToHost(address, port);
}

void ChatNetworkManager::disconnectChat()
{
    socket->disconnectFromHost();
}

void ChatNetworkManager::onSocketConnected()
{

}

void ChatNetworkManager::onSocketDisconnected()
{

}

void ChatNetworkManager::onSocketReadyRead()
{

}

void ChatNetworkManager::onSocketDisplayError(QAbstractSocket::SocketError socketError)
{

}

void ChatNetworkManager::initChat()
{
    if(socket->state() != QAbstractSocket::ConnectedState){ //Заменить на более правильное условие проверки есть ли соединение по сокету
        socket->connectToHost(address, port);
    }

}

void ChatNetworkManager::sendData(ChatRequest *request)
{

}
