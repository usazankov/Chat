#ifndef COMGETUSERS_H
#define COMGETUSERS_H

#include "chatcommand.h"
#include "chatclient.h"

namespace chat {
class ChatClient;
class ComGetUsers : public ChatCommand
{
public:
    ComGetUsers();
    // ChatCommand interface
    void execute();
    ~ComGetUsers(){}
};
}
#endif // COMGETUSERS_H
