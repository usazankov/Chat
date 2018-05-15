#include "worker.h"

Worker::Worker(const QByteArray &arr, QObject *parent) : QObject(parent)
{
    data = arr;
    auth_ptr.reset(new Authorizator(this));
    parser_ptr.reset(new ParserRequest(this));
}

Worker::Worker(const ServerEvent &event, QObject *parent)
{
    this->event = event;
}

Worker::~Worker()
{

}

void Worker::process_data()
{
    QJsonParseError error;
    QJsonDocument doc;
    doc.fromJson(data, &error);
    if(!doc.isObject()){
        qDebug()<<"error:"<< error.errorString();
        ClientCommand com;
        com.result = server_consts::ErrorParseRequest;
        emit result(com);
        return;
    }
    parser_ptr->setJsonDocument(&doc);
    parser_ptr->process();
    if(parser_ptr->typeCommand() == server_consts::AuthenticationClient){
        authorization();
    }
}

void Worker::process_event()
{

}

void Worker::authorization()
{
    QVariantMap map;
    ClientCommand com;
    chat::ChatRequest req;
    qDebug() << "authorization()";
    QString userID = parser_ptr->data(server_consts::USER_ID).toString();
    com.type = server_consts::AuthenticationClient;
    if(userID.isNull()){
        qDebug() << "UserId is NULL";
        com.result = server_consts::MissingUserID;
        req.addProperty(chat::CODE_RESP, chat::C_ERROR);
        com.data = req.toRequest();
        emit result(com);
        return;
    }
    qDebug() << "userId: " << userID;
    map[server_consts::USER_ID] = userID;
    if(auth_ptr->isValidData(map)){
        com.result = server_consts::SUCCESS;
        qDebug() << "data is valid";
        req.addChildObj(chat::COMMAND_OBJ, chat::ChatRequest(chat::COMMAND_ID, chat::C_AUTH_REQ));
        req.addProperty(chat::USER_ID, userID);
        req.addProperty(chat::CODE_RESP, chat::AUTH_SUCCESS);
        com.data = req.toRequest();
    }else{
        qDebug() << "data is not valid";
        com.result = server_consts::UndefinedError;
        req.addProperty(chat::CODE_RESP, chat::C_ERROR);
        com.data = req.toRequest();
    }
    emit result(com);
}

void Worker::run()
{
    if(!data.isEmpty())
        process_data();
    else if(event.type != ServerEvent::UndefinedEvent){
        process_event();
    }
}
