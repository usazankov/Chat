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
    QJsonDocument doc = QJsonDocument::fromBinaryData(data);
    if(!doc.isObject()){
        ClientCommand com;
        com.result = ClientCommand::ErrorParseRequest;
        emit result(com);
        return;
    }
    parser_ptr->setJsonDocument(doc);

}

void Worker::process_event()
{

}

void Worker::run()
{
    if(!data.isEmpty())
        process_data();
    else if(event.type != ServerEvent::UndefinedEvent){
        process_event();
    }
}
