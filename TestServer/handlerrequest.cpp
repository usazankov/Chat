#include "handlerrequest.h"

HandlerRequest::HandlerRequest()
{
    type = server_consts::Undefined;
}

HandlerRequest::HandlerRequest(QJsonDocument *doc)
{
    this->doc = doc;
    type = server_consts::Undefined;
}

void HandlerRequest::setJsonDocument(QJsonDocument *doc)
{
    this->doc = doc;
}

QJsonDocument *HandlerRequest::getJsonDocument() const
{
    return doc;
}

HandlerRequest::~HandlerRequest()
{

}

QString server_consts::getTypeCommand(const QJsonObject &obj)
{
    QJsonObject com_obj = obj.value(chat::COMMAND_OBJ).toObject();
    return com_obj.value(chat::COMMAND_ID).toString();
}
