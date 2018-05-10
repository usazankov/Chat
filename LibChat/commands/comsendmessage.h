#ifndef COMSENDMESSAGE_H
#define COMSENDMESSAGE_H

#include "chatcommand.h"
#include "chatclient.h"
namespace chat {

class ComSendMessage : public ChatCommand
{
public:
    ComSendMessage();

    // ChatCommand interface
    void execute();
    ~ComSendMessage(){}
};
}
#endif // COMSENDMESSAGE_H
