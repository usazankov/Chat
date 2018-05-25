#ifndef SERVER_CONSTS_H
#define SERVER_CONSTS_H
#include <QObject>

namespace server_consts {

static const QString TOKEN = "token";
enum CommandType{
    Undefined = 0,
    SendToClient, // Отправить данные конкретному пользователю
    SendToListClient, // Отправить данные списку пользователей
    SendToAllClient, // Отправить данные всем пользователям
    SendToThisClient, // Отправить данные пользователю, который инициировал запрос
    AuthenticationClient //Аутентификация пользователя
};
enum Result{
    UndefinedError = 0,
    ErrorParseRequest,
    MissingUserID,
    MissingToken,
    EmptyMessage,
    SUCCESS
};
}
#endif // SERVER_CONSTS_H
