#ifndef CLIENTCOMMAND_H
#define CLIENTCOMMAND_H

#include <QObject>

class ClientCommand
{
public:
    explicit ClientCommand();
    enum Result{
        UndefinedError = 0,
        ErrorParseRequest,
        MissingToken,
        SUCCESS
    };
    enum CommandType{
        Undefined = 0,
        SendToClient, // Отправить данные конкретному пользователю
        SendToListClient, // Отправить данные списку пользователей
        SendToAllClient, // Отправить данные всем пользователям
        SendToThisClient, // Отправить данные пользователю, который инициировал запрос
        AuthenticationClient //Аутентификация пользователя
    };
    Result result;
    CommandType type;
    QByteArray data;
};
Q_DECLARE_METATYPE(ClientCommand)
#endif // CLIENTCOMMAND_H
