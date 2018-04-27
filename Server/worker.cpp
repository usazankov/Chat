#include "worker.h"
#include "Client.h"

void Worker::addClient(qintptr socketDescriptor)
{
    new Client(socketDescriptor, this);
}

