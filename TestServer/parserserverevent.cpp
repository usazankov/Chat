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

ClientCommand ParserServerEvent::response()
{
    ClientCommand com;
    com.type = server_consts::SendToThisClient;
    chat::ChatRequest req;
    if(event.type == ServerEvent::ConnectedUser){
        chat::ChatRequest ev(chat::EVENT_ID, chat::E_CONNECT_USER);
        ev.addChildObj(chat::USER_OBJ, chat::ChatRequest(chat::USER_ID, event.data[chat::USER_ID].toString()));
        req.addChildObj(chat::EVENT_OBJ, ev);
    }else if(event.type == ServerEvent::DisconnectedUser){
        chat::ChatRequest ev(chat::EVENT_ID, chat::E_DISCONNECT_USER);
        ev.addChildObj(chat::USER_OBJ, chat::ChatRequest(chat::USER_ID, event.data[chat::USER_ID].toString()));
        req.addChildObj(chat::EVENT_OBJ, ev);
    }else if(event.type == ServerEvent::GetListUsers){
        handler = new GetListUsersHandler(event.data[chat::USER_ID].toString());
        return handler->data();
    }
    com.data = req;
    return com;
}
