#include <QCoreApplication>
#include "chatrequest.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    ChatRequest req;
    req.clear();
    return a.exec();
}
