#include "chatnetworkmanager.h"

chat::ChatNetworkManager::ChatNetworkManager(qintptr socketDescriptor, QObject *parent) : QObject(parent)
{
    socket = new QTcpSocket(this);
    if(socketDescriptor){
        socket->setSocketDescriptor(socketDescriptor);
    }
    initChat();
    currentReq = nullptr;
}

bool chat::ChatNetworkManager::execute(ChatRequest *request)
{
    QByteArray array = request->toRequest();
    int size = array.size();
    if(socket->write(array) == size){
        return true;
    }
    return false;
}

void chat::ChatNetworkManager::connectToChat(const QHostAddress &address, quint16 port)
{
    this->address = address;
    this->port = port;
    socket->connectToHost(address, port);
}

void chat::ChatNetworkManager::disconnectChat()
{
    socket->disconnectFromHost();
}

void chat::ChatNetworkManager::onSocketConnected()
{

}

void chat::ChatNetworkManager::onSocketDisconnected()
{

}

void chat::ChatNetworkManager::onSocketReadyRead()
{
    QDataStream in(socket);
    int size = 0;
    //если считываем новый блок первые 4 байта это его размер
    if (blockSize == 0) {
        //если пришло меньше 4 байт ждем пока будет 4 байта
        if (socket->bytesAvailable() < (int)sizeof(quint32))
            return;
        //считываем размер (4 байта)
        in >> blockSize;
        qDebug() << "_blockSize now " << blockSize;
    }
    //ждем пока блок придет полностью
    if (socket->bytesAvailable() < blockSize + chat::sizeHash)
        return;
    else{
        size = blockSize;
        //можно принимать новый блок
        blockSize = 0;
    }
    QByteArray array(size, Qt::Uninitialized);
    in >> array;
    QByteArray hash(chat::sizeHash, Qt::Uninitialized);
    in >> hash;
    // Вычисляем хэш и сравниваем
    //...
    // Если все в порядке, то оповещаем о приеме новых данных
    emit dataReceived(QJsonDocument::fromBinaryData(array).object());
}

void chat::ChatNetworkManager::onSocketDisplayError(QAbstractSocket::SocketError socketError)
{

}

void chat::ChatNetworkManager::initChat()
{
    if(socket->state() != QAbstractSocket::ConnectedState){ //Заменить на более правильное условие проверки есть ли соединение по сокету
        socket->connectToHost(address, port);
    }

}
