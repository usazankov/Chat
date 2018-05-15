#ifndef CLIENTCOMMAND_H
#define CLIENTCOMMAND_H

#include <QObject>
#include "server_consts.h"

class ClientCommand
{
public:
    explicit ClientCommand();

    server_consts::Result result;
    server_consts::CommandType type;
    QByteArray data;
};
Q_DECLARE_METATYPE(ClientCommand)
#endif // CLIENTCOMMAND_H
