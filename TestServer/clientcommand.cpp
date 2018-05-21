#include "clientcommand.h"

ClientCommand::ClientCommand()
{

}

ClientCommand::ClientCommand(const ClientCommand &com)
{
    result = com.result;
    type = com.type;
    data = com.data;
}
