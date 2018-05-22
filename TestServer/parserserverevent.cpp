#include "parserserverevent.h"

ParserServerEvent::ParserServerEvent(const ServerEvent &event) : IParserRequest()
{
    map = event.data;
}

ParserServerEvent::~ParserServerEvent()
{

}

ClientCommand ParserServerEvent::response()
{
    ClientCommand com;
    com.type = server_consts::SendToThisClient;
    chat::ChatRequest req;
    chat::ChatRequest event(chat::EVENT_ID, chat::E_CONNECT_USER);
    event.addChildObj(chat::USER_OBJ, chat::ChatRequest(chat::USER_ID, map[chat::USER_ID].toString()));
    req.addChildObj(chat::EVENT_OBJ, event);
    com.data = req.toRequest();
    return com;
}
