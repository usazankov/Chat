#include "parserrequest.h"

ParserRequest::ParserRequest(QObject *parent) : QObject(parent)
{
    type = server_consts::Undefined;
}

ParserRequest::ParserRequest(QJsonDocument *doc, QObject *parent) : QObject(parent)
{
    this->doc = doc;
    type = server_consts::Undefined;
}

void ParserRequest::process()
{
    if(!doc)
        return;
    QJsonObject obj = doc->object();
    QJsonObject com_obj = obj.value(chat::COMMAND_OBJ).toObject();
    QString com_id = com_obj.value(chat::COMMAND_ID).toString();
    if( com_id == chat::C_AUTH_REQ){
        type = server_consts::AuthenticationClient;
    }

}

server_consts::CommandType ParserRequest::typeCommand() const
{
    return type;
}

void ParserRequest::setJsonDocument(QJsonDocument *doc)
{
    this->doc = doc;
}

QJsonDocument *ParserRequest::getJsonDocument() const
{
    return doc;
}

QVariant ParserRequest::data() const
{
    QVariant temp;
    switch (type) {
    case server_consts::AuthenticationClient:
    {
        AuthRequest req = convertToAuthRequest();
        temp = QVariant::fromValue<AuthRequest>(req);
        return temp;
    }
    default:
        return QVariant();
    }
}

AuthRequest ParserRequest::convertToAuthRequest() const
{
    AuthRequest req;
    QJsonObject obj = doc->object();
    if(obj.contains(chat::USER_ID)){
        req.userId = obj.value(chat::USER_ID).toString();
    }
    return req;
}
