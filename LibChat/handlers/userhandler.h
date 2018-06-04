#ifndef USERHANDLER_H
#define USERHANDLER_H

#include "chathandler.h"
#include "models/user.h"
namespace chat {

class UserHandler : public ChatHandler
{
public:
    UserHandler(QJsonObject *obj);

    // ChatHandler interface
public:
    QVariant data();
private:
    QJsonObject *obj;
};
}
#endif // USERHANDLER_H
