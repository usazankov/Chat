#include "parserserverevent.h"

ParserServerEvent::ParserServerEvent(const ServerEvent &event, QObject *parent) : IParserRequest(parent)
{

}

ParserServerEvent::~ParserServerEvent()
{

}

ClientCommand ParserServerEvent::response()
{

}
