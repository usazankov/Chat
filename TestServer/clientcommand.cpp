#include "clientcommand.h"

ClientCommand::ClientCommand()
{
    result = server_consts::UndefinedError;
    type = server_consts::Undefined;
    data = chat::ChatRequest();
    params = QVariantMap();
}

ClientCommand::ClientCommand(const ClientCommand &com)
{
    result = com.result;
    type = com.type;
    data = com.data;
    params = com.params;
}

ClientCommand &ClientCommand::operator=(ClientCommand &&com)
{
    result = std::move(com.result);
    type = std::move(com.type);
    data = std::move(com.data);
    params = std::move(com.params);
    return *this;
}

ClientCommand &ClientCommand::operator=(const ClientCommand &com)
{
    result = com.result;
    type = com.type;
    data = com.data;
    params = com.params;
    return *this;
}

ClientCommand::ClientCommand(ClientCommand &&com) : result(std::move(com.result)),
                                                    type(std::move(com.type)),
                                                    data(std::move(com.data)),
                                                    params(std::move(com.params))
{

}
