#include "clientcommand.h"

ClientCommand::ClientCommand()
{
    result = server_consts::UndefinedError;
    type = server_consts::Undefined;
    data = chat::ChatRequest();
    params = QVariantMap();
}

ClientCommand::~ClientCommand()
{

}

ClientCommand::ClientCommand(const ClientCommand &com)
{
    result = com.result;
    type = com.type;
    data = com.data;
    params = com.params;
}

ClientCommand &ClientCommand::operator=(const ClientCommand &com)
{
    result = com.result;
    type = com.type;
    data = com.data;
    params = com.params;
    return *this;
}
