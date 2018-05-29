#ifndef CLIENTCOMMAND_H
#define CLIENTCOMMAND_H

#include <QObject>
#include "server_consts.h"
#include <QVariantMap>
#include "chatrequest.h"
#include <QSharedPointer>
#include <QVector>

class ClientCommand
{
public:
    ClientCommand();
    ~ClientCommand();
    ClientCommand(const ClientCommand &com);
    ClientCommand &operator=(const ClientCommand &com);
    QSharedPointer<ClientCommand> com_onSuccess; //Команда, выполняемая в случае успеха текущей команды
    QSharedPointer<ClientCommand> com_onError;//Команда, выполняемая в случае ошибки выполнения текущей команды
    QVariantMap params;
    server_consts::Result result;
    server_consts::CommandType type;
    chat::ChatRequest data;
};
typedef QSharedPointer<ClientCommand> ClientCommandPtr;
Q_DECLARE_METATYPE(ClientCommand)
#endif // CLIENTCOMMAND_H
