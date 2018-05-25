#include "clientcommand.h"

ClientCommand::ClientCommand()
{
    result = server_consts::UndefinedError;
    type = server_consts::Undefined;
    data = chat::ChatRequest();
    params = QVariantMap();
    child.reset();
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
    child = com.child;
}

ClientCommand &ClientCommand::operator=(const ClientCommand &com)
{
    result = com.result;
    type = com.type;
    data = com.data;
    params = com.params;
    child = com.child;
    return *this;
}
