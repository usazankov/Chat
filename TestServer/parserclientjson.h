#ifndef PARSERCLIENTJSON_H
#define PARSERCLIENTJSON_H

#include <QObject>
#include "Handlers/authhandler.h"
#include "handlerrequest.h"
#include "iparserrequest.h"

class ParserClientJson : public IParserRequest
{
    Q_OBJECT
public:
    explicit ParserClientJson(const QByteArray &arr, QObject *parent = nullptr);

    virtual ~ParserClientJson();
private:
    QJsonDocument doc;
    QJsonParseError error;
signals:

public slots:

    // IParserRequest interface
public:
    ClientCommand response();
};

#endif // PARSERCLIENTJSON_H
