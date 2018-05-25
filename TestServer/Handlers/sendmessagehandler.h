#ifndef SENDMESSAGEHANDLER_H
#define SENDMESSAGEHANDLER_H

#include "senddatahandler.h"
#include "clientcommand.h"

class SendMessageHandler : public SendDataHandler
{
public:
    SendMessageHandler();
    SendMessageHandler(QJsonDocument *doc);

    // HandlerRequest interface
public:
    ClientCommandPtr data() const;
};

#endif // SENDMESSAGEHANDLER_H
