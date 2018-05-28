#include "commanddecoratorhandler.h"

CommandDecoratorHandler::CommandDecoratorHandler(const QString &commandID, HandlerRequest *req) : DecoratorHandler(req)
{
    this->commandID = commandID;
}

ClientCommandPtr CommandDecoratorHandler::data() const
{
    ClientCommandPtr com = DecoratorHandler::data();
    if(com->type == server_consts::SendToThisClient){
        chat::ChatRequest req(chat::COMMAND_ID, commandID);
        com->data.addChildObj(chat::COMMAND_OBJ, req);
    }
    return com;
}
