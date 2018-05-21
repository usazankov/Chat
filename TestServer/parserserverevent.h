#ifndef PARSERSERVEREVENT_H
#define PARSERSERVEREVENT_H

#include <QObject>
#include "iparserrequest.h"
#include "serverevent.h"

class ParserServerEvent : public IParserRequest
{
    Q_OBJECT
public:
    explicit ParserServerEvent(const ServerEvent &event, QObject *parent = nullptr);
    virtual ~ParserServerEvent();

    // IParserRequest interface
public:
    ClientCommand response();
};

#endif // PARSERSERVEREVENT_H
