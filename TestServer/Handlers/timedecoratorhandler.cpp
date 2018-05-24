#include "timedecoratorhandler.h"

TimeDecoratorHandler::TimeDecoratorHandler(HandlerRequest *handler) : DecoratorHandler(handler)
{

}

TimeDecoratorHandler::~TimeDecoratorHandler()
{

}

ClientCommandPtr TimeDecoratorHandler::data() const
{
    ClientCommandPtr com = DecoratorHandler::data();
    com->data.addProperty(chat::DATE, QDate::currentDate().toString(Qt::SystemLocaleDate));
    com->data.addProperty(chat::TIME, QTime::currentTime().toString(Qt::SystemLocaleDate));
    return com;
}
