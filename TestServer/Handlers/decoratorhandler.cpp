#include "decoratorhandler.h"

DecoratorHandler::DecoratorHandler(HandlerRequest *handler)
{
    this->handler = handler;
}

DecoratorHandler::~DecoratorHandler()
{

}

ClientCommandPtr DecoratorHandler::data() const
{
    return handler->data();
}
