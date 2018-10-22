#ifndef CHECKCONNECTHANDLER_H
#define CHECKCONNECTHANDLER_H

#include "handlerrequest.h"

class CheckConnectHandler : public HandlerRequest
{
public:
    CheckConnectHandler();
    CheckConnectHandler(QJsonDocument *doc);

    // HandlerRequest interface
public:
    ClientCommandPtr data() const;
};

#endif // CHECKCONNECTHANDLER_H
