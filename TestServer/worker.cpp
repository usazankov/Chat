#include "worker.h"

Worker::Worker(const QByteArray &arr, QObject *parent) : QObject(parent)
{
    data = arr;
}

void Worker::run()
{

}
