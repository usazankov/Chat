#ifndef PARSERREQUEST_H
#define PARSERREQUEST_H

#include <QObject>
#include <QJsonDocument>
#include "QJsonObject"
#include <QVariantMap>
#include "server_consts.h"
#include "common_consts.h"
#include "Requests/authrequest.h"

class ParserRequest : public QObject
{
    Q_OBJECT
public:
    explicit ParserRequest(QObject *parent = nullptr);
    explicit ParserRequest(QJsonDocument *doc, QObject *parent = nullptr);
    void process();
    server_consts::CommandType typeCommand()const;
    void setJsonDocument(QJsonDocument *doc);
    QJsonDocument *getJsonDocument()const;
    QVariant data()const;
private:
    QJsonDocument *doc;
    server_consts::CommandType type;
    QVariantMap map;
    AuthRequest convertToAuthRequest() const;
signals:

public slots:
};
namespace server_consts {
template< typename T >
T unpack( const QVariant& var, const T& defVal = T() ) {
    if( var.isValid() && var.canConvert< T >() ) {
        return var.value< T >();
    }
    return defVal;
}
}
#endif // PARSERREQUEST_H
