#include "parserclientjson.h"
#include <QFile>
#include <QDataStream>

ParserClientJson::ParserClientJson(const QByteArray &arr) : IParserRequest()
{
    handler = nullptr;
    doc = QJsonDocument::fromJson(arr, &error);
    if(!doc.isObject()){
        qDebug()<<"error:"<< error.errorString();
    }
}

ParserClientJson::~ParserClientJson()
{
    if(!handler)
        delete handler;
}

ClientCommand ParserClientJson::response()
{
    if(error.error != QJsonParseError::NoError){
        ClientCommand com;
        com.result = server_consts::ErrorParseRequest;
        return com;
    }
    QString type = server_consts::getTypeCommand(doc.object());
    if(type == chat::C_AUTH_REQ){
        handler = new AuthHandler(&doc);
    }
    return handler->data();
}