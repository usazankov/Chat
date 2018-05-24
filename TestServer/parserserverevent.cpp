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

ClientCommandPtr ParserServerEvent::response()
{
    if(event.type == ServerEvent::ConnectedUser){
        ClientCommandPtr com(new ClientCommand);
        com->type = server_consts::SendToThisClient;
        com->data = userConnected();
        return com;
    }else if(event.type == ServerEvent::DisconnectedUser){
        ClientCommandPtr com(new ClientCommand);
        com->type = server_consts::SendToThisClient;
        com->data = userDisconnected();
        return com;
    }else if(event.type == ServerEvent::GetListUsers){
        handler = new GetListUsersHandler(event.data[chat::USER_ID].toString());
        return handler->data();
    }

}
