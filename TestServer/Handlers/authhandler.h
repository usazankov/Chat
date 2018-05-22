#ifndef AUTHHANDLER_H
#define AUTHHANDLER_H

#include "handlerrequest.h"

class AuthHandler : public HandlerRequest
{
public:
    explicit AuthHandler();
    explicit AuthHandler(QJsonDocument *doc);
private:
    AuthRequest convertToAuthRequest() const;
    // HandlerRequest interface
public:
    ClientCommand data() const;
};

#endif // AUTHHANDLER_H
