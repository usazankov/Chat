#include "sendmessagehandler.h"

SendMessageHandler::SendMessageHandler()
{

}

SendMessageHandler::SendMessageHandler(QJsonDocument *doc) : SendDataHandler(doc)
{

}

ClientCommandPtr SendMessageHandler::data() const
{
    ClientCommandPtr com(new ClientCommand);
    chat::ChatRequest req;
    com->result = server_consts::UndefinedError;
    com->type = server_consts::SendToThisClient;
    QJsonObject obj = doc->object();
    QString userId;
    QString message;
    if(obj.contains(chat::USER_ID)){
        userId = obj.value(chat::USER_ID).toString();
    }else{
        com->result = server_consts::MissingUserID;
        return com;
    }
    if(obj.contains(chat::MESSAGE_OBJ) && obj.value(chat::MESSAGE_OBJ).isObject()){
        QJsonObject mes = obj.value(chat::MESSAGE_OBJ).toObject();
        if(mes.contains(chat::MESSAGE_BODY)){
            message = mes.value(chat::MESSAGE_BODY).toString();
        }
    }
    if(message.isEmpty()){
        com->result = server_consts::EmptyMessage;
        return com;
    }else{
        com->type = server_consts::SendToAllClient;
        chat::ChatRequest temp;
        chat::ChatRequest mes(chat::MESSAGE_BODY, message);
        mes.addProperty(chat::USER_ID, userId);
        req.addChildObj(chat::MESSAGE_OBJ, mes);
    }
    com->data = req;
    return com;
}
