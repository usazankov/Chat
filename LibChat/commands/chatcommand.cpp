#include "chatcommand.h"

chat::ChatCommand::ChatCommand()
{

}

void chat::ChatCommand::setChatClient(chat::ChatClient *client)
{
    this->client = client;
}
