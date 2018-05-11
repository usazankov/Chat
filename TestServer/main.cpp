#include <QCoreApplication>
#include "server.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Server serv;
    QHostAddress adr(QHostAddress::LocalHost);
    serv.startServer(adr, 1024);
    return a.exec();
}
