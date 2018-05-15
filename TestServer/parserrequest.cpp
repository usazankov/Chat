#include "parserrequest.h"

ParserRequest::ParserRequest(QObject *parent) : QObject(parent)
{

}

ParserRequest::ParserRequest(QJsonDocument *doc, QObject *parent) : QObject(parent)
{
    this->doc = doc;
}

void ParserRequest::process()
{
    if(!doc)
        return;
    QJsonObject obj = doc->object();
    QJsonValue com = obj.take(chat::COMMAND_OBJ);
    map = obj.toVariantMap();

}

server_consts::CommandType ParserRequest::typeCommand() const
{
    return type;
}

void ParserRequest::setJsonDocument(QJsonDocument *doc)
{
    this->doc = doc;
}

QVariant ParserRequest::data(const QString &key)
{

}
