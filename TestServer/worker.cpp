#include "worker.h"

Worker::Worker(const QByteArray &arr, QObject *parent) : QObject(parent)
{
    data = arr;
    auth_ptr.reset(new Authorizator(this));
}

Worker::~Worker()
{

}

void Worker::process()
{
    QJsonDocument doc = QJsonDocument::fromBinaryData(data);
    if(!doc.isObject()){
        return;
    }
    parser_ptr.reset(new ParserRequest(&doc, this));
}

void Worker::run()
{
    process();
}
