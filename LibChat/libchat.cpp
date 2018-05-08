#include "libchat.h"


chat::LibChat::LibChat()
{
    client = new ChatClient(new ChatTCPManager);
}

void chat::LibChat::connectToChat(const QHostAddress &address, quint16 port)
{
    client->getNetworkManager()->connectToHost(address, port);
}

void chat::LibChat::disconnectFromChat()
{
    client->getNetworkManager()->disconnectHost();
}

void chat::LibChat::getUsers()
{
    ComGetUsers com;
    client->executeCommand(&com);
}

void chat::LibChat::sendMessage(const QString &message)
{
    ComSendMessage com;
    client->executeCommand(&com);
}

chat::IChatModel *chat::LibChat::model()
{
    return client->getModel();
}

void chat::LibChat::deleteChat()
{
    client->deleteLater();
}

chat::ChatClient *chat::LibChat::getChatClient()
{
    return client;
}

