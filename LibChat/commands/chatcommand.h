#ifndef CHATCOMMAND_H
#define CHATCOMMAND_H

#include <QObject>
#include "chatclient.h"

namespace chat {
class ChatClient;
class ChatCommand
{
public:
    explicit ChatCommand();
    virtual void execute() = 0;
    void setChatClient(ChatClient *client);
    virtual ~ChatCommand(){}
protected:
    ChatClient *client;
private:

signals:

public slots:
};

}
#endif // CHATCOMMAND_H
