#include "chattcpmanager.h"

chat::ChatTCPManager::ChatTCPManager(qintptr socketDescriptor, QObject *parent) : IChatNetworkManager(parent)
{
    socket = new QTcpSocket(this);
    if(socketDescriptor){
        socket->setSocketDescriptor(socketDescriptor);
    }
    initChat();
}

chat::ChatTCPManager::ChatTCPManager(QObject *parent) : IChatNetworkManager(parent)
{
    socket = new QTcpSocket(this);
    initChat();
}

bool chat::ChatTCPManager::execute(ChatRequest *request)
{
    QByteArray array = request->toRequest();
    int size = array.size();
    if(socket->write(array) == size){
        return true;
    }
    return false;
}

void chat::ChatTCPManager::connectToHost(const QHostAddress &address, quint16 port)
{
    this->address = address;
    this->port = port;
    emit stateChanged(Connecting);
    socket->connectToHost(address, port);
}

void chat::ChatTCPManager::disconnectHost()
{
    socket->disconnectFromHost();
}

void chat::ChatTCPManager::onSocketConnected()
{
    emit stateChanged(Online);
}

void chat::ChatTCPManager::onSocketDisconnected()
{
    emit stateChanged(Offline);
}

void chat::ChatTCPManager::onSocketReadyRead()
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

void chat::ChatTCPManager::onSocketError(QAbstractSocket::SocketError err)
{
    qDebug() << err;
    emit error(chat::ChatTCPManager::CommunicationError);
}

void chat::ChatTCPManager::initChat()
{
    connect(socket, SIGNAL(connected()),this, SLOT(onSocketConnected()));
    connect(socket, SIGNAL(readyRead()), this, SLOT(onSocketReadyRead()));
    connect(socket, SIGNAL(disconnected()), this, SLOT(onSocketDisconnected()));
    connect(socket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(onSocketError(QAbstractSocket::SocketError)));
}
