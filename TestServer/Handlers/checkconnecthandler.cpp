#include "checkconnecthandler.h"

CheckConnectHandler::CheckConnectHandler() : HandlerRequest()
{

}

CheckConnectHandler::CheckConnectHandler(QJsonDocument *doc) : HandlerRequest(doc)
{

}

ClientCommandPtr CheckConnectHandler::data() const
{
    ClientCommandPtr com(new ClientCommand);
    chat::ChatRequest req;
    com->result = server_consts::SUCCESS;
    com->type = server_consts::SendToThisClient;
    return com;
}
