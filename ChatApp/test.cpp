#include "test.h"

Test::Test(QObject *parent) : QObject(parent)
{
    QHostAddress adr(QHostAddress::LocalHost);
    chat::PersonalData data;
    int seed = QTime::currentTime().msecsSinceStartOfDay();
    srand(seed);
    int x = rand() % 1000000;
    QString name("User_");
    data.setUserName(name + QString::number(x));
    chat::LibChat::instance().setPersonalData(data);
    chat::LibChat::instance().connectToChat(adr, 1024);
    chat::LibChat::instance().sendMessage("Hello Govno!");
}
