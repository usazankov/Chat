#ifndef GETLISTUSERSHANDLER_H
#define GETLISTUSERSHANDLER_H

#include "handlerrequest.h"
#include "globalstorage.h"

class GetListUsersHandler : public HandlerRequest
{
public:
    GetListUsersHandler(const QString &sourceUser = 0);
private:
    QString idUser;
    inline chat::ChatRequest createUserObj()const;
    // HandlerRequest interface
public:
    ClientCommandPtr data() const;
};

#endif // GETLISTUSERSHANDLER_H
