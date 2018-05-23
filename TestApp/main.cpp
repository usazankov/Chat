#include <QCoreApplication>
#include "../Common/chatrequest.h"
#include "../Common/common_consts.h"
#include <iostream>
#include <QStringList>
#include "testclient.h"

using namespace std;
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    TestClient cl;
    return a.exec();
}
