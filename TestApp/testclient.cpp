#include "testclient.h"

TestClient::TestClient(QObject *parent) : QObject(parent)
{
    connect(chat::LibChat::instance().getChatClient()->getNetworkManager(),SIGNAL(error(chat::IChatNetworkManager::ErrorNetwork)),this,SLOT(printError(chat::IChatNetworkManager::ErrorNetwork)));
    QHostAddress adr(QHostAddress::LocalHost);
    chat::PersonalData data;
    int seed = QTime::currentTime().msecsSinceStartOfDay();
    srand(seed);
    int x = rand() % 1000000;
    QString name("User_");
    data.setUserName(name + QString::number(x));
    chat::LibChat::instance().connectToChat(adr, 1024);
    chat::LibChat::instance().authorization(data);
    chat::LibChat::instance().sendMessage("Hello Govno!");
}

void TestClient::print(const QString &str)
{
    std::cout << str.toStdString() << std::endl;
}

TestClient::printError(chat::IChatNetworkManager::ErrorNetwork err)
{
    if(err == chat::IChatNetworkManager::CommunicationError)
        print("Communication Error!");
    else
        print("Unkwoin error!");
}
