#ifndef AUTHREQUEST_H
#define AUTHREQUEST_H

#include <QObject>

class AuthRequest
{
public:
    AuthRequest();
    AuthRequest(const AuthRequest &req);
    ~AuthRequest(){}
    QString userId;
signals:

public slots:
};
Q_DECLARE_METATYPE(AuthRequest)
#endif // AUTHREQUEST_H
