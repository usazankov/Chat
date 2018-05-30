#include "userstatushandler.h"

UserStatusHandler::UserStatusHandler(const ServerEvent &event)
{
    this->event = event;
}

ClientCommandPtr UserStatusHandler::data() const
{
    ClientCommandPtr com(new ClientCommand);
    chat::ChatRequest req;
    com->type = server_consts::SendToThisClient;
    if(event.type == ServerEvent::ConnectedUser){
        chat::ChatRequest ev(chat::EVENT_ID, chat::E_CONNECT_USER);
        ev.addChildObj(chat::USER_OBJ, chat::ChatRequest(chat::USER_ID, event.data[chat::USER_ID].toString()));
        req.addChildObj(chat::EVENT_OBJ, ev);
        com->result = server_consts::SUCCESS;
    }else if(event.type == ServerEvent::DisconnectedUser){
        chat::ChatRequest ev(chat::EVENT_ID, chat::E_DISCONNECT_USER);
        ev.addChildObj(chat::USER_OBJ, chat::ChatRequest(chat::USER_ID, event.data[chat::USER_ID].toString()));
        req.addChildObj(chat::EVENT_OBJ, ev);
        com->result = server_consts::SUCCESS;
    }
    com->data = req;
    return com;
}
