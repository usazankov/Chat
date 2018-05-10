#include "comgetusers.h"

chat::ComGetUsers::ComGetUsers() : ChatCommand()
{

}

void chat::ComGetUsers::execute()
{
    ChatRequest req;
    ChatRequest com;
    com.addProperty(chat::COMMAND_ID, chat::C_GET_ALL_USERS);
    req.addChildObj(chat::COMMAND_OBJ, com);
    client->getNetworkManager()->execute(&req);
}
