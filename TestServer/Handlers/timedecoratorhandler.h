#ifndef TIMEDECORATORHANDLER_H
#define TIMEDECORATORHANDLER_H

#include "decoratorhandler.h"
#include <QTime>
#include <QDate>

class TimeDecoratorHandler : public DecoratorHandler
{
public:
    TimeDecoratorHandler(HandlerRequest *handler);
    virtual ~TimeDecoratorHandler();
    // HandlerRequest interface
public:
    ClientCommandPtr data() const;
};

#endif // TIMEDECORATORHANDLER_H
