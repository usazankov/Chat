#ifndef COMMANDDECORATORHANDLER_H
#define COMMANDDECORATORHANDLER_H

#include "decoratorhandler.h"

class CommandDecoratorHandler : public DecoratorHandler
{
public:
    CommandDecoratorHandler(const QString &commandID, HandlerRequest *req);
private:
    QString commandID;
    // HandlerRequest interface
public:
    ClientCommandPtr data() const;
};

#endif // COMMANDDECORATORHANDLER_H
