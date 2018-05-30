#ifndef EVENTDECORATORHANDLER_H
#define EVENTDECORATORHANDLER_H

#include "decoratorhandler.h"

class EventDecoratorHandler : public DecoratorHandler
{
public:
    EventDecoratorHandler(ServerEvent::EventType event, HandlerRequest *handler);
private:
    ServerEvent::EventType event;
    void process(ClientCommandPtr com) const;
    // HandlerRequest interface
public:
    ClientCommandPtr data() const;
};

#endif // EVENTDECORATORHANDLER_H
