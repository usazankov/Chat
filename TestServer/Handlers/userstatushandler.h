#ifndef USERSTATUSHANDLER_H
#define USERSTATUSHANDLER_H

#include "handlerrequest.h"

class UserStatusHandler : public HandlerRequest
{
public:
    UserStatusHandler(const ServerEvent &event);
    ServerEvent event;
    // HandlerRequest interface
public:
    ClientCommandPtr data() const;
};

#endif // USERSTATUSHANDLER_H
