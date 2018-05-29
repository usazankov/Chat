#include "clientcommand.h"

ClientCommand::ClientCommand()
{
    result = server_consts::UndefinedError;
    type = server_consts::Undefined;
    data = chat::ChatRequest();
    params = QVariantMap();
    com_onSuccess.reset();
    com_onError.reset();
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
    com_onSuccess = com.com_onSuccess;
    com_onError = com.com_onError;
}

ClientCommand &ClientCommand::operator=(const ClientCommand &com)
{
    result = com.result;
    type = com.type;
    data = com.data;
    params = com.params;
    com_onSuccess = com.com_onSuccess;
    com_onError = com.com_onError;
    return *this;
}
