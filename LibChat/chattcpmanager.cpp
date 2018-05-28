#include "chattcpmanager.h"

chat::ChatTCPManager::ChatTCPManager(qintptr socketDescriptor, QObject *parent) : IChatNetworkManager(parent)
{
    socket = new QTcpSocket(this);
    if(socketDescriptor){
        socket->setSocketDescriptor(socketDescriptor);
    }
    m_msgSize = -1;
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
            QByteArray arr = socket->read(m_msgSize);
            std::cout << "\nReceived " << m_msgSize <<" Byte:\n";
            std::cout << arr.toStdString() << "\n";
            m_msgSize = -1;
            QJsonParseError error;
            QJsonDocument doc = QJsonDocument::fromJson(arr, &error);
            if(!doc.isObject()){
                qDebug()<<"error:"<< error.errorString();
            }else{
                emit dataReceived(doc.object());
            }
        }
    }


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
