#ifndef AUTHHANDLER_H
#define AUTHHANDLER_H

#include "handlerrequest.h"

class AuthHandler : public HandlerRequest
{
public:
    explicit AuthHandler(QObject *parent = nullptr);
    explicit AuthHandler(QJsonDocument *doc, QObject *parent = nullptr);
private:
    AuthRequest convertToAuthRequest() const;
    // HandlerRequest interface
public:
    ClientCommand data() const;
};

#endif // AUTHHANDLER_H
