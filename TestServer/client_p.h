#ifndef CLIENT_P_H
#define CLIENT_P_H

#include "client.h"
#include "server.h"

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
    bool isFirst;
    Client *q_ptr;
    Server *server;
};

#endif // CLIENT_P_H
