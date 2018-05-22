#ifndef AUTHHANDLER_H
#define AUTHHANDLER_H

#include "handlerrequest.h"
class AuthRequest;
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

class AuthRequest
{
public:
    AuthRequest();
    AuthRequest(const AuthRequest &req);
    AuthRequest(AuthRequest &&req);
    AuthRequest& operator=(AuthRequest&& req) ;
    AuthRequest& operator=(const AuthRequest& req) ;
    ~AuthRequest(){}
    QString userId;
};

#endif // AUTHHANDLER_H
