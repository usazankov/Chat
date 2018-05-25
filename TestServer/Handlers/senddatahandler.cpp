#include "senddatahandler.h"

SendDataHandler::SendDataHandler()
{

}

SendDataHandler::SendDataHandler(QJsonDocument *doc) : HandlerRequest(doc)
{

}

ClientCommandPtr SendDataHandler::data() const
{

}
