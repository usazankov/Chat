#ifndef COMSENDMESSAGE_H
#define COMSENDMESSAGE_H

#include "chatcommand.h"
#include "chatclient.h"
namespace chat {

class ComSendMessage : public ChatCommand
{
public:
    ComSendMessage(const QString &message);
    ComSendMessage(const QString &message, const QString &userId);
    ComSendMessage(const QString &message, const QStringList &usersId);
private:
    QString message;
    QStringList users;
    // ChatCommand interface
    void execute();
    ~ComSendMessage(){}
};
}
#endif // COMSENDMESSAGE_H
