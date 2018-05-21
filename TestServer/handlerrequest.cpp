#include "handlerrequest.h"

HandlerRequest::HandlerRequest(QObject *parent) : QObject(parent)
{
    type = server_consts::Undefined;
}

HandlerRequest::HandlerRequest(QJsonDocument *doc, QObject *parent) : QObject(parent)
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
