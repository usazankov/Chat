#ifndef CHATCOMMAND_H
#define CHATCOMMAND_H
#include "../Common/chatrequest.h"
#include "../Common/common_consts.h"

namespace chat {
class ChatClient;
class ChatCommand
{
public:
    explicit ChatCommand();
    ChatCommand(const ChatCommand &com);
    virtual void execute();
    void setChatClient(ChatClient *client);
    virtual ~ChatCommand(){}
protected:
    ChatClient *client;
private:

};

}
#endif // CHATCOMMAND_H
