#ifndef SENDDATAHANDLER_H
#define SENDDATAHANDLER_H

#include "handlerrequest.h"

class SendDataHandler : public HandlerRequest
{
public:
    SendDataHandler();
    SendDataHandler(QJsonDocument *doc);

    // HandlerRequest interface
public:
    ClientCommandPtr data() const;
};

#endif // SENDDATAHANDLER_H
