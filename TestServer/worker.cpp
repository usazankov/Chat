#include "worker.h"

Worker::Worker(const QByteArray &arr, QObject *parent) : QObject(parent)
{
    parser_ptr.reset(new ParserClientJson(arr, this));
}

Worker::Worker(const ServerEvent &event, QObject *parent) : QObject(parent)
{
    parser_ptr.reset(new ParserServerEvent(event, this));
}

Worker::~Worker()
{

}

void Worker::run()
{
    emit result(parser_ptr->response());
}
