#include "parserclientjson.h"

ParserClientJson::ParserClientJson(const QByteArray &arr, QObject *parent) : IParserRequest(parent)
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
        handler = new AuthHandler(&doc, this);
    }
    return handler->data();
}
