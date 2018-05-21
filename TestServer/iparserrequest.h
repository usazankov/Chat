#ifndef IPARSERREQUEST_H
#define IPARSERREQUEST_H

#include <QObject>
#include "handlerrequest.h"
#include "clientcommand.h"

class IParserRequest : public QObject
{
    Q_OBJECT
public:
    explicit IParserRequest(QObject *parent = nullptr);
    virtual ~IParserRequest();
    virtual ClientCommand response() = 0;

protected:
    HandlerRequest *handler;
private:

signals:

public slots:
};

#endif // IPARSERREQUEST_H
