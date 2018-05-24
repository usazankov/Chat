#include "parserserverevent.h"

ParserServerEvent::ParserServerEvent(const ServerEvent &event) : IParserRequest()
{
    this->event = event;
}

ParserServerEvent::~ParserServerEvent()
{
    if(!handler)
        delete handler;
}

bool ParserServerEvent::isUserStatus(ServerEvent::EventType eventType) const
{
    if(eventType == ServerEvent::ConnectedUser
            || eventType == ServerEvent::DisconnectedUser)
        return true;
    return false;
}

ClientCommandPtr ParserServerEvent::response()
{
    if(isUserStatus(event.type)){
        handler = new UserStatusHandler(event);
    }else if(event.type == ServerEvent::GetListUsers){
        handler = new GetListUsersHandler(event.data[chat::USER_ID].toString());
    }
    handler = new TimeDecoratorHandler(handler);
    return handler->data();
}
