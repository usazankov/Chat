#ifndef SERVER_CONSTS_H
#define SERVER_CONSTS_H
#include <QObject>

namespace server_consts {

static const QString TOKEN = "token";
static const QString USER_ID = "user_id";
enum CommandType{
    Undefined = 0,
    SendToClient, // Отправить данные конкретному пользователю
    SendToListClient, // Отправить данные списку пользователей
    SendToAllClient, // Отправить данные всем пользователям
    SendToThisClient, // Отправить данные пользователю, который инициировал запрос
    AuthenticationClient //Аутентификация пользователя
};
}
#endif // SERVER_CONSTS_H
