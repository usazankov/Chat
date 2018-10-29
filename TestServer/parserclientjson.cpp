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

ClientCommandPtr ParserClientJson::response()
{
    if(error.error != QJsonParseError::NoError){
        ClientCommandPtr com(new ClientCommand);
        com->result = server_consts::ErrorParseRequest;
        handler = new ErrorDecoratorHandler(handler);
        return com;
    }
    QString type = server_consts::getTypeCommand(doc.object());
    if(type == chat::C_AUTH_REQ){
        handler = new AuthHandler(&doc);
    }else if(type == chat::C_SEND_MESSAGE){
        handler = new SendMessageHandler(&doc);
    }else if(type == chat::C_GET_ALL_USERS){
        handler = new GetListUsersHandler(&doc);
    }else if(type == chat::C_CHECK_CONNECT){
        handler = new CheckConnectHandler(&doc);
    }
    //Добавляем зеркально идентификатор команды
    handler = new CommandDecoratorHandler(type, handler);

    //Добавляем время к запросу
    handler = new TimeDecoratorHandler(handler);

    //Добавляем результат выполнения
    handler = new ErrorDecoratorHandler(handler);

    //Добавляем идентификатор сообщения
    handler = new MessageIdHandler(handler, &doc);

    return handler->data();
}
