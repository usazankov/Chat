#ifndef CHATCOMMANDMANAGER_H
#define CHATCOMMANDMANAGER_H

#include <QObject>
#include "commands/chatcommand.h"
#include "commands/comauthuser.h"
#include <QTimer>
#include <QQueue>
#include <deque>

namespace chat {

class ChatCommandManager : public QObject
{
    Q_OBJECT
public:
    explicit ChatCommandManager(QObject *parent = nullptr);
    void start();
    void stop();
    void setInterval(int interval);
    void executePostpone(ChatCommand *com);
    bool isAuthed() const;
    void setIsAuthed(bool isAuthed);

private:
    bool m_isAuthed;
    std::deque<ChatCommand*> q_coms;
    QTimer *timer;
    void execComAuth();
signals:

public slots:
    void onTimeOut();
};
}
#endif // CHATCOMMANDMANAGER_H
