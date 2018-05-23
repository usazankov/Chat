#ifndef CLIENTCOMMAND_H
#define CLIENTCOMMAND_H

#include <QObject>
#include "server_consts.h"
#include <QVariantMap>
#include "chatrequest.h"

class ClientCommand
{
public:
    ClientCommand();
    ClientCommand(const ClientCommand &com);
    ClientCommand(ClientCommand &&com);
    ClientCommand &operator=(ClientCommand &&com);
    ClientCommand &operator=(const ClientCommand &com);
    QVariantMap params;
    server_consts::Result result;
    server_consts::CommandType type;
    chat::ChatRequest data;
};
Q_DECLARE_METATYPE(ClientCommand)
#endif // CLIENTCOMMAND_H
