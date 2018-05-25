#include "libchat.h"


chat::LibChat::LibChat()
{
    params = new ChatClientParameters;
    client = new ChatClient(new ChatTCPManager, params);

}

void chat::LibChat::connectToChat(const QHostAddress &address, quint16 port)
{
    client->getNetworkManager()->connectToHost(address, port);
}

void chat::LibChat::authorization(const chat::PersonalData &data)
{
    client->executeCommand(new ComAuthUser(data));
}

void chat::LibChat::disconnectFromChat()
{
    client->getNetworkManager()->disconnectHost();
}

void chat::LibChat::getUsers()
{
    client->executeCommand(new ComGetUsers);
}

void chat::LibChat::sendMessage(const QString &message)
{
    client->executeCommand(new ComSendMessage(message));
}

chat::IChatModel *chat::LibChat::model()
{
    return client->getModel();
}

void chat::LibChat::deleteChat()
{
    params->deleteLater();
    client->deleteLater();
}

chat::ChatClient *chat::LibChat::getChatClient()
{
    return client;
}

