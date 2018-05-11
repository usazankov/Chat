#ifndef CLIENT_P_H
#define CLIENT_P_H

#include "client.h"

class Client;

class ClientPrivate
{
    Q_DECLARE_PUBLIC(Client)
public:
    ClientPrivate();
    virtual ~ClientPrivate();
    QStringList users;
    QByteArray token;
    QString idUser;
    bool isAuth;
    Client *q_ptr;

};

#endif // CLIENT_P_H
