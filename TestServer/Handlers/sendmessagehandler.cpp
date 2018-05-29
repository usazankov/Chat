#include "sendmessagehandler.h"

SendMessageHandler::SendMessageHandler()
{

}

SendMessageHandler::SendMessageHandler(QJsonDocument *doc) : SendDataHandler(doc)
{
    this->doc = doc;
}

ClientCommandPtr SendMessageHandler::data() const
{
    ClientCommandPtr com(new ClientCommand);

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
    if(userId.isEmpty()){
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

        //Остальных клиентов оповещаем о новом сообщении
        chat::ChatRequest req;
        req.addChildObj(chat::EVENT_OBJ, chat::ChatRequest(chat::EVENT_ID, chat::E_MESSAGE));
        req.addChildObj(chat::USER_OBJ, chat::ChatRequest(chat::USER_ID, userId));
        req.addChildObj(chat::MESSAGE_OBJ, chat::ChatRequest(chat::MESSAGE_BODY, message));
        com->data = req;
        com->type = server_consts::SendToAllClient;
        com->result = server_consts::SUCCESS;

        //Клиенту, который создал запрос, отсылаем, что сообщение доставлено
        ClientCommandPtr comSuccess(new ClientCommand);
        comSuccess->type = server_consts::SendToThisClient;
        comSuccess->result = server_consts::SUCCESS;
        com->com_onSuccess = comSuccess;

        //В случае ошибки
        ClientCommandPtr comError(new ClientCommand);
        comError->type = server_consts::SendToThisClient;
        comError->result = server_consts::UndefinedError;
        com->com_onError = comError;
    }
    return com;
}
