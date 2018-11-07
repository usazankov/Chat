#ifndef MESSAGEIDHANDLER_H
#define MESSAGEIDHANDLER_H

#include "decoratorhandler.h"

class MessageIdHandler : public DecoratorHandler
{
public:
    MessageIdHandler(HandlerRequest *handler, QJsonDocument *doc);
    virtual ~MessageIdHandler();
    // HandlerRequest interface
public:
    ClientCommandPtr data() const;
private:
    void addMessageId(ClientCommandPtr root)const;
};

#endif // MESSAGEIDHANDLER_H
