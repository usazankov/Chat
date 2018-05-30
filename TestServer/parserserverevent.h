#ifndef PARSERSERVEREVENT_H
#define PARSERSERVEREVENT_H

#include <QObject>
#include "iparserrequest.h"
#include "serverevent.h"
#include "Handlers/getlistusershandler.h"
#include "Handlers/timedecoratorhandler.h"
#include "Handlers/userstatushandler.h"
#include "Handlers/errordecoratorhandler.h"
#include "Handlers/eventdecoratorhandler.h"

class ParserServerEvent : public IParserRequest
{
public:
    explicit ParserServerEvent(const ServerEvent &event);
    virtual ~ParserServerEvent();
private:
    ServerEvent event;
    bool isUserStatus(ServerEvent::EventType eventType)const;
    // IParserRequest interface
public:
    ClientCommandPtr response();
};

#endif // PARSERSERVEREVENT_H
