#ifndef CLIENT_P_H
#define CLIENT_P_H

#include "client.h"
#include "server.h"
#include "requestfilter.h"

class Client;
class Server;
class ClientPrivate
{
    Q_DECLARE_PUBLIC(Client)
public:
    ClientPrivate();
    virtual ~ClientPrivate();
    QByteArray token;
    QString idUser;
    bool isAuth;
    Client *q_ptr;
    Server *server;
    RequestFilter *filter;
};

#endif // CLIENT_P_H
