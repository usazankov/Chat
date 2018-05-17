#include "authrequest.h"

AuthRequest::AuthRequest()
{
    userId = QString();
}

AuthRequest::AuthRequest(const AuthRequest &req)
{
    userId = req.userId;
}
