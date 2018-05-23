#ifndef PARSERSERVEREVENT_H
#define PARSERSERVEREVENT_H

#include <QObject>
#include "iparserrequest.h"
#include "serverevent.h"
#include "Handlers/getlistusershandler.h"

class ParserServerEvent : public IParserRequest
{
public:
    explicit ParserServerEvent(const ServerEvent &event);
    virtual ~ParserServerEvent();
private:
    ServerEvent event;
    // IParserRequest interface
public:
    ClientCommand response();
};

#endif // PARSERSERVEREVENT_H
