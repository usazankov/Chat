#ifndef CHATCOMMANDMANAGER_H
#define CHATCOMMANDMANAGER_H

#include <QObject>
#include <commands/chatcommand.h>
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
private:
    std::deque<ChatCommand*> q_coms;
    QTimer *timer;
signals:

public slots:
    void onTimeOut();
};
}
#endif // CHATCOMMANDMANAGER_H
