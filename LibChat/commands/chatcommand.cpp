#include "chatcommand.h"

chat::ChatCommand::ChatCommand()
{

}

chat::ChatCommand::ChatCommand(const chat::ChatCommand &com)
{
    this->client = com.client;
}

void chat::ChatCommand::execute()
{

}

void chat::ChatCommand::setChatClient(chat::ChatClient *client)
{
    this->client = client;
}
