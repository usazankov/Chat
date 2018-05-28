#include "chatcommandmanager.h"

chat::ChatCommandManager::ChatCommandManager(QObject *parent) : QObject(parent)
{
    timer = new QTimer;
    connect(timer,SIGNAL(timeout()),this,SLOT(onTimeOut()));
    timer->setInterval(500);
    m_isAuthed = false;
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

bool chat::ChatCommandManager::isAuthed() const
{
    return m_isAuthed;
}

void chat::ChatCommandManager::setIsAuthed(bool isAuthed)
{
    m_isAuthed = isAuthed;
}

void chat::ChatCommandManager::onTimeOut()
{
    if(q_coms.empty())
        return;
    ChatCommand *temp = q_coms.front();
    if( m_isAuthed || typeid(*temp) == typeid(ComAuthUser)){
        if(temp){
            temp->execute();
            delete temp;
        }
        q_coms.pop_front();
    }
}
