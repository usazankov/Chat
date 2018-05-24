#ifndef GETLISTUSERSHANDLER_H
#define GETLISTUSERSHANDLER_H

#include "handlerrequest.h"
#include "globalstorage.h"

class GetListUsersHandler : public HandlerRequest
{
public:
    GetListUsersHandler(const QString &sourceUser = 0);
    virtual ~GetListUsersHandler();
private:
    QString idUser;

    // HandlerRequest interface
public:
    ClientCommandPtr data() const;
};

#endif // GETLISTUSERSHANDLER_H
