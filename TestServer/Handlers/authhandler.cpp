#include "authhandler.h"

AuthHandler::AuthHandler() : HandlerRequest()
{

}

AuthHandler::AuthHandler(QJsonDocument *doc) : HandlerRequest(doc)
{

}

AuthRequest AuthHandler::convertToAuthRequest() const
{
    AuthRequest req;
    QJsonObject obj = doc->object();
    if(obj.contains(chat::USER_ID)){
        req.userId = obj.value(chat::USER_ID).toString();
    }
    return req;
}

ClientCommand AuthHandler::data() const
{
    ClientCommand com;
    chat::ChatRequest req;
    qDebug() << "authorization()";
    AuthRequest authData = convertToAuthRequest();
    QString userID = authData.userId;
    com.type = server_consts::AuthenticationClient;
    if(userID.isNull()){
        qDebug() << "UserId is NULL";
        com.result = server_consts::MissingUserID;
        req.addProperty(chat::CODE_RESP, chat::C_ERROR);
        com.data = req;
        return com;
    }
    qDebug() << "userId: " << userID;
    if(1){//Проверка данных на валидацию
        com.result = server_consts::SUCCESS;
        qDebug() << "data is valid";
        req.addChildObj(chat::COMMAND_OBJ, chat::ChatRequest(chat::COMMAND_ID, chat::C_AUTH_REQ));
        req.addProperty(chat::USER_ID, userID);
        req.addProperty(chat::CODE_RESP, chat::AUTH_SUCCESS);
        com.params[chat::USER_ID] = QVariant(userID);
        com.data = req;
    }else{
        qDebug() << "data is not valid";
        com.result = server_consts::UndefinedError;
        req.addProperty(chat::CODE_RESP, chat::C_ERROR);
        com.data = req;
    }
    return com;
}

AuthRequest::AuthRequest()
{
    userId = QString();
}

AuthRequest::AuthRequest(const AuthRequest &req) : userId(req.userId)
{

}

AuthRequest::AuthRequest(AuthRequest &&req) : userId(std::move(req.userId))
{

}

AuthRequest &AuthRequest::operator=(AuthRequest &&req)
{
    userId = std::move(req.userId);
    return *this;
}

AuthRequest &AuthRequest::operator=(const AuthRequest &req)
{
    userId = req.userId;
    return *this;
}
