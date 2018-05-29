#ifndef ERRORDECORATORHANDLER_H
#define ERRORDECORATORHANDLER_H

#include "decoratorhandler.h"

class ErrorDecoratorHandler : public DecoratorHandler
{
public:
    ErrorDecoratorHandler(HandlerRequest *handler);

    // HandlerRequest interface
public:
    ClientCommandPtr data() const;
private:
    void process(ClientCommandPtr com) const;
};

#endif // ERRORDECORATORHANDLER_H
