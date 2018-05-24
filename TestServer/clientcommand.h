#ifndef CLIENTCOMMAND_H
#define CLIENTCOMMAND_H

#include <QObject>
#include "server_consts.h"
#include <QVariantMap>
#include "chatrequest.h"
#include <QSharedPointer>

class ClientCommand
{
public:
    ClientCommand();
    ~ClientCommand();
    ClientCommand(const ClientCommand &com);
    ClientCommand &operator=(const ClientCommand &com);
    QVariantMap params;
    server_consts::Result result;
    server_consts::CommandType type;
    chat::ChatRequest data;
};
typedef QSharedPointer<ClientCommand> ClientCommandPtr;
Q_DECLARE_METATYPE(ClientCommand)
#endif // CLIENTCOMMAND_H
