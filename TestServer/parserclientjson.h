#ifndef PARSERCLIENTJSON_H
#define PARSERCLIENTJSON_H

#include <QObject>
#include "Handlers/authhandler.h"
#include "Handlers/timedecoratorhandler.h"
#include "Handlers/sendmessagehandler.h"
#include "Handlers/getlistusershandler.h"
#include "Handlers/errordecoratorhandler.h"
#include "Handlers/commanddecoratorhandler.h"
#include "Handlers/checkconnecthandler.h"
#include "Handlers/messageidhandler.h"
#include "handlerrequest.h"
#include "iparserrequest.h"

class ParserClientJson : public IParserRequest
{
public:
    explicit ParserClientJson(const QByteArray &arr);
    virtual ~ParserClientJson();
private:
    QJsonDocument doc;
    QJsonParseError error;

    // IParserRequest interface
public:
    ClientCommandPtr response();
};

#endif // PARSERCLIENTJSON_H
