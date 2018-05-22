#ifndef HANDLERREQUEST_H
#define HANDLERREQUEST_H

#include <QObject>
#include <QJsonDocument>
#include "QJsonObject"
#include <QVariantMap>
#include "server_consts.h"
#include "common_consts.h"
#include "clientcommand.h"
#include "common_consts.h"
#include "chatrequest.h"
#include <QDebug>

class HandlerRequest
{
public:
    explicit HandlerRequest();
    explicit HandlerRequest(QJsonDocument *doc);
    virtual ~HandlerRequest();

    void setJsonDocument(QJsonDocument *doc);
    QJsonDocument *getJsonDocument()const;

    //Вернуть результат
    virtual ClientCommand data()const = 0;

protected:
    server_consts::CommandType type;
    QJsonDocument *doc;
private:

};
namespace server_consts {
template< typename T >
T unpack( const QVariant& var, const T& defVal = T() ) {
    if( var.isValid() && var.canConvert< T >() ) {
        return var.value< T >();
    }
    return defVal;
}
QString getTypeCommand(const QJsonObject &obj);
}
#endif // HANDLERREQUEST_H
