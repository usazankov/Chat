#include "server.h"

Server::Server(QObject *parent) : QObject(parent)
{
    m_ptcpServer.reset(new QTcpServer);
    qRegisterMetaType<ClientCommand>();
#ifdef TEST
    GlobalStorage::instance().addUser("user1");
    GlobalStorage::instance().addUser("user2");
    GlobalStorage::instance().addUser("user3");
#endif
}

Server::~Server()
{

}

void Server::onNewConnection()
{
    new Client(this, m_ptcpServer->nextPendingConnection()); // Удалять клиент будет сам себя при дисконекте
}

void Server::startServer(const QHostAddress &address, quint16 port)
{
    connect(m_ptcpServer.data(), SIGNAL(newConnection()),this, SLOT(onNewConnection()));
    if(!m_ptcpServer->listen(address, port)){
        m_ptcpServer->close();
        throw m_ptcpServer->errorString();
    }
}

void Server::addClient(const QString &idUser, Client *client)
{
    GlobalStorage::instance().addUser(idUser.toStdString());
    connect(this,SIGNAL(serverEvent(ServerEvent)),client,SLOT(onServerEvent(ServerEvent)));
    m_sockets[idUser] = client->getSocket();
    ServerEvent event;
    event.type = ServerEvent::ConnectedUser;
    event.data[chat::USER_ID] = QVariant(idUser);
    emit serverEvent(event);
}

void Server::removeClient(const QString &idUser)
{
    if(!m_sockets.contains(idUser)){
        return;
    }
    GlobalStorage::instance().removeUser(idUser.toStdString());
    m_sockets.remove(idUser);
    ServerEvent event;
    event.type = ServerEvent::DisconnectedUser;
    event.data[chat::USER_ID] = QVariant(idUser);
    emit serverEvent(event);
}

bool Server::executeCommand(const QString &idUser, const ClientCommand &com)
{
    if(com.type == server_consts::SendToAllClient){
        QByteArray arr = com.data.toRequest();
        for(auto iter = m_sockets.begin(); iter != m_sockets.end(); iter++){
            if(iter.key() != idUser){
                iter.value()->write(arr);
            }
        }
    }
    return true; //Пока всегда возвращаем успех
}
