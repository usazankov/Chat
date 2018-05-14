#include "parserrequest.h"

ParserRequest::ParserRequest(QObject *parent) : QObject(parent)
{

}

ParserRequest::ParserRequest(QJsonDocument *doc, QObject *parent) : QObject(parent)
{
    this->doc = doc;
}

server_consts::CommandType ParserRequest::typeCommand() const
{
    return type;
}

QVariant ParserRequest::data(const QString &key)
{

}
