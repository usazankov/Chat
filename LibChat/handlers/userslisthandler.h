#ifndef USERSLISTHANDLER_H
#define USERSLISTHANDLER_H

#include "chathandler.h"
#include "../models/user.h"
namespace chat {
class UsersListHandler : public ChatHandler
{
public:
    UsersListHandler(QJsonObject *doc);

    // ChatHandler interface
public:
    QVariant data();
private:
};
}
#endif // USERSLISTHANDLER_H
