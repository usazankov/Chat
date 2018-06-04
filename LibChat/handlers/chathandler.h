#ifndef CHATHANDLER_H
#define CHATHANDLER_H

#include <QVariant>
#include <QJsonObject>
#include <QJsonArray>
#include "../Common/common_consts.h"
namespace chat {

class ChatHandler
{
private:
protected:
    QJsonObject *obj;
public:
    ChatHandler();
    ChatHandler(QJsonObject *obj);
    virtual ~ChatHandler();
    virtual QVariant data() = 0;
};

template< typename T >
T unpack( const QVariant& var, const T& defVal = T() ) {
    if( var.isValid() && var.canConvert< T >() ) {
        return var.value< T >();
    }
    return defVal;
}

}
#endif // CHATHANDLER_H
