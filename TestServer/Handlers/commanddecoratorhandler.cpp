#include "commanddecoratorhandler.h"

CommandDecoratorHandler::CommandDecoratorHandler(const QString &commandID, HandlerRequest *req) : DecoratorHandler(req)
{
    this->commandID = commandID;
}

void CommandDecoratorHandler::process(ClientCommandPtr com) const
{
    if(com->type == server_consts::SendToThisClient){
        chat::ChatRequest req(chat::COMMAND_ID, commandID);
        com->data.addChildObj(chat::COMMAND_OBJ, req);
    }
}

ClientCommandPtr CommandDecoratorHandler::data() const
{
    ClientCommandPtr com = DecoratorHandler::data();
    process(com);
    if(!com->com_onError.isNull())
        process(com->com_onError);
    if(!com->com_onSuccess.isNull())
        process(com->com_onSuccess);
    return com;
}
