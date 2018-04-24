#include "chatclient.h"
#include "common_consts.h"

chat::ChatClient::ChatClient(QObject *parent) : QObject(parent)
{
    chat::AUTH_SUCCESS;
}

void chat::ChatClient::updateChat(const QJsonObject &obj)
{

}
