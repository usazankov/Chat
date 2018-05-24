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

chat::ChatRequest ParserServerEvent::userConnected()
{
    chat::ChatRequest req;
    chat::ChatRequest ev(chat::EVENT_ID, chat::E_CONNECT_USER);
    ev.addChildObj(chat::USER_OBJ, chat::ChatRequest(chat::USER_ID, event.data[chat::USER_ID].toString()));
    req.addChildObj(chat::EVENT_OBJ, ev);
    return req;
}

chat::ChatRequest ParserServerEvent::userDisconnected()
{
    chat::ChatRequest req;
    chat::ChatRequest ev(chat::EVENT_ID, chat::E_DISCONNECT_USER);
    ev.addChildObj(chat::USER_OBJ, chat::ChatRequest(chat::USER_ID, event.data[chat::USER_ID].toString()));
    req.addChildObj(chat::EVENT_OBJ, ev);
    return req;
}

ClientCommand ParserServerEvent::response()
{
    ClientCommand com;
    com.type = server_consts::SendToThisClient;
    chat::ChatRequest req;
    if(event.type == ServerEvent::ConnectedUser){
        req = userConnected();
    }else if(event.type == ServerEvent::DisconnectedUser){
        req = userDisconnected();
    }else if(event.type == ServerEvent::GetListUsers){
        handler = new GetListUsersHandler(event.data[chat::USER_ID].toString());
        return handler->data();
    }
    com.data = req;
    return com;
}
