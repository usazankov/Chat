#include "libchat.h"


chat::LibChat::LibChat()
{
    client = new ChatClient(new ChatTCPManager);
}

chat::LibChat::connectToChat(const QHostAddress &address, quint16 port)
{
    client->getNetworkManager()->connectToHost(address, port);
}

chat::LibChat::disconnectFromChat()
{
    client->getNetworkManager()->disconnectHost();
}

chat::LibChat::getUsers()
{
    ComGetUsers com;
    client->executeCommand(&com);
}

chat::LibChat::sendMessage(const QString &message)
{
    ComSendMessage com;
    client->executeCommand(&com);
}

chat::IChatModel *chat::LibChat::model()
{
    return client->getModel();
}

chat::LibChat::deleteChat()
{
    client->deleteLater();
}
