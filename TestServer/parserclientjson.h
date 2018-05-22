#ifndef PARSERCLIENTJSON_H
#define PARSERCLIENTJSON_H

#include <QObject>
#include "Handlers/authhandler.h"
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
    ClientCommand response();
};

#endif // PARSERCLIENTJSON_H
