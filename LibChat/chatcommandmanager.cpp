#include "chatcommandmanager.h"

chat::ChatCommandManager::ChatCommandManager(QObject *parent) : QObject(parent)
{
    timer = new QTimer;
    connect(timer,SIGNAL(timeout()),this,SLOT(onTimeOut()));
    timer->setInterval(1000);
}

void chat::ChatCommandManager::start()
{
    timer->start();
}

void chat::ChatCommandManager::stop()
{
    timer->stop();
}

void chat::ChatCommandManager::setInterval(int interval)
{
    timer->setInterval(interval);
}

void chat::ChatCommandManager::executePostpone(chat::ChatCommand *com)
{
    q_coms.push_back(com);
}

void chat::ChatCommandManager::onTimeOut()
{
    if(q_coms.empty())
        return;
    ChatCommand *temp = q_coms.front();
    if(temp){
        temp->execute();
        delete temp;
    }
    q_coms.pop_front();
}
