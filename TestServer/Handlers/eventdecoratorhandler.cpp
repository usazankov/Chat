#include "eventdecoratorhandler.h"

EventDecoratorHandler::EventDecoratorHandler(ServerEvent::EventType event, HandlerRequest *handler) : DecoratorHandler(handler)
{
    this->event = event;
}

void EventDecoratorHandler::process(ClientCommandPtr com) const
{
    if(com->type == server_consts::SendToThisClient){
        if(!com->data.toJson().contains(chat::EVENT_OBJ))
        {
            QString eventStr;
            switch (event) {
            case ServerEvent::UndefinedEvent:
                eventStr = chat::E_UNDEFINED;
                break;
            case ServerEvent::ConnectedUser:
                eventStr = chat::E_CONNECT_USER;
                break;
            case ServerEvent::DisconnectedUser:
                eventStr = chat::E_DISCONNECT_USER;
                break;
            case ServerEvent::GetListUsers:
                eventStr = chat::E_USERS_LIST;
                break;
            default:
                eventStr = chat::E_UNDEFINED;
                break;
            }
            chat::ChatRequest req(chat::EVENT_ID, eventStr);
            com->data.addChildObj(chat::EVENT_OBJ, req);
        }
    }
}

ClientCommandPtr EventDecoratorHandler::data() const
{
    ClientCommandPtr com = DecoratorHandler::data();
    process(com);
    return com;
}
