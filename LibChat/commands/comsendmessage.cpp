#include "comsendmessage.h"

chat::ComSendMessage::ComSendMessage(const QString &message) : ChatCommand()
{
    this->message = message;
}

chat::ComSendMessage::ComSendMessage(const QString &message, const QString &userId)
{

}

chat::ComSendMessage::ComSendMessage(const QString &message, const QStringList &usersId)
{

}

void chat::ComSendMessage::execute()
{
    ChatRequest req;
    ChatRequest com;
    req.addProperty(chat::USER_ID, client->chatClientParameters()->personalData().userName());
    com.addProperty(chat::COMMAND_ID, chat::C_SEND_MESSAGE);
    ChatRequest mess(chat::MESSAGE_BODY, message);
    req.addChildObj(chat::COMMAND_OBJ, com);
    req.addChildObj(chat::MESSAGE_OBJ, mess);
    if(!users.empty()){
        QJsonArray arr;
        for(QString item: users){
            QJsonObject user;
            user[chat::USER_ID] = item;
            QJsonObject user_obj;
            user_obj.insert(chat::USER_OBJ, user);
            arr.append(user_obj);
        }
        req.addArray(chat::USERS_LIST, arr);
    }
    client->getNetworkManager()->execute(&req);
}
