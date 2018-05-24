#ifndef DECORATORHANDLER_H
#define DECORATORHANDLER_H

#include "handlerrequest.h"

class DecoratorHandler : public HandlerRequest
{
public:
    DecoratorHandler(HandlerRequest *handler);
    virtual ~DecoratorHandler();
private:
    HandlerRequest *handler;
    // HandlerRequest interface
public:
    ClientCommandPtr data() const;
};

#endif // DECORATORHANDLER_H
