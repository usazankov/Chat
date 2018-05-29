#include "timedecoratorhandler.h"

TimeDecoratorHandler::TimeDecoratorHandler(HandlerRequest *handler) : DecoratorHandler(handler)
{

}

TimeDecoratorHandler::~TimeDecoratorHandler()
{

}

ClientCommandPtr TimeDecoratorHandler::data() const
{
    ClientCommandPtr root = DecoratorHandler::data();
    ClientCommandPtr com = root;
    process(com);
    if(!com->com_onError.isNull())
        process(com->com_onError);
    if(!com->com_onSuccess.isNull())
        process(com->com_onSuccess);

    return root;
}

void TimeDecoratorHandler::process(ClientCommandPtr com) const
{
    com->data.addProperty(chat::DATE, QDate::currentDate().toString(Qt::SystemLocaleDate));
    com->data.addProperty(chat::TIME, QTime::currentTime().toString(Qt::SystemLocaleDate));
}
