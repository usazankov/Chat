#include <QCoreApplication>
#include "server.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Server serv;
    QHostAddress adr(QHostAddress::Any);
    serv.startServer(adr, 1977);
    return a.exec();
}
