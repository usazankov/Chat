#ifndef COMMON_CONSTS_H
#define COMMON_CONSTS_H

#ifdef USE_QSTRING_CONSTS
#include <QString>
#define TYPE_STR QString
#else
#include <string>
#define TYPE_STR std::string
#endif

namespace chat {
    // Объект список пользователей
    const static TYPE_STR USERS_LIST = "Users_list"; //Объект список пользователей
        const static TYPE_STR COUNT_USERS_ONLINE = "Count_users_online"; //Количество пользователей в онлайне
        // Описание объекта пользователя:
        const static TYPE_STR USER_OBJ = "User_obj";  //Объект пользователь
            const static TYPE_STR USER_ID = "User_id"; //Идентификатор пользователя
            const static TYPE_STR USER_NAME = "User_name"; //Имя пользователя
            const static TYPE_STR USER_STATUS = "User_status"; //Объект статус пользователя
                const static TYPE_STR USER_ONLINE = "u_online"; //Пользователь в онлайне
                const static TYPE_STR USER_OFFLINE = "u_offline"; //Пользователь в офлайне
            const static TYPE_STR USER_INFO = "User_info"; //Какая-то информация о пользователе
    // Описание объекта сообщение
        const static TYPE_STR MESSAGE_OBJ = "Message_obj"; //Объект сообщение
            const static TYPE_STR MESSAGE_DATE = "Message_data"; //Дата сообщения
            const static TYPE_STR MESSAGE_TIME = "Message_time"; //Время сообщения
            const static TYPE_STR MESSAGE_BODY = "Message_body"; //Тело сообщения
            //Содержится User_id - от кого
            //Здесь должен быть объект Users_list, если его нет, то сообщение отправляется всем

    // Описание объекта команда:
    const static TYPE_STR COMMAND_OBJ = "Command_obj"; //Объект команда
        const static TYPE_STR COMMAND_ID = "Command_id"; //Идентификатор команды
        const static TYPE_STR COMMAND_ARR_PARAM = "Command_param"; //Объект параметры команды
            const static TYPE_STR COMMAND_PARAM1 = "Command_param_1"; //1 параметр команды
            const static TYPE_STR COMMAND_PARAM2 = "Command_param_2"; //2 параметр команды
            // итд...

    // Описание идентификаторов команд (список возможных полей для поля Command_id)
    const static TYPE_STR C_AUTH_REQ = "c_auth_req"; //Запрос на авторизацию
    const static TYPE_STR C_CHECK_CONNECT = "c_check_connect"; //Проверка соединения
    const static TYPE_STR C_GET_COUNT_ONLINE = "c_get_count_online"; //Получить количество пользователей онлайн
    const static TYPE_STR C_GET_ALL_USERS = "c_get_users"; //Получить список всех пользователей
    const static TYPE_STR C_GET_ONLINE_USERS = "c_get_online_users"; //Получить список пользователей в онлайне
    const static TYPE_STR C_GET_USER_INFO = "c_get_user_info"; //Получить подробную информацию о пользователе (ID пользователя передается в Command_param1)
    const static TYPE_STR C_SEND_MESSAGE = "c_send_message"; //Отправить сообщение в чат
    const static TYPE_STR C_GET_EVENTS = "c_get_events_users"; //Получить события от сервера
                                                             //(Сервер должен вернуть список пользователей, изменивших свое состояние, имя или еще что-то)

    const static TYPE_STR EVENT_OBJ = "Event_obj"; //Объект событие от сервера
        const static TYPE_STR EVENT_ID = "Event_id"; //Идентификатор события
        //В этом объекте (EVENT_OBJ) может содержаться объект USERS_LIST - список пользователей, изменивших свое состояние, имя или еще что-то
        const static TYPE_STR MESSAGES_LIST = "Messages_list"; //Список сообщений от пользователей

    // Описание идентификаторов команд (список возможных полей для поля Event_id)
    const static TYPE_STR E_UNDEFINED = "e_undefined"; //Неизвестный Event
    const static TYPE_STR E_CONNECT_USER = "e_connect_user"; //В этом типе события находится объект USER_OBJ
    const static TYPE_STR E_DISCONNECT_USER = "e_disconnect_user"; //В этом типе события находится объект USER_OBJ
    const static TYPE_STR E_MESSAGE = "e_message"; //Сообщение
    const static TYPE_STR E_USERS_LIST = "e_users_list"; //Список пользователей

    const static TYPE_STR ID_MSG = "id_msg"; //Идентификатор запроса
    const static TYPE_STR CODE_RESP = "Code_resp"; //Код ответа сервера

    const static TYPE_STR NO_MSG_ID = "no_msg_id"; //При таком значении в запросе id_msg сервер не будет отвечать id_msg

    //Коды ответа сервера
    const static TYPE_STR USER_IS_NOT_REG = "user_is_not_reg"; //Пользователь не зарегистрирован
    const static TYPE_STR TIMEOUT_LIMIT_EXCEEDED = "timeout_limit_exceeded"; //Превышен допустимый таймаут запросов
    const static TYPE_STR C_SUCCESS = "c_success"; //Успешное выполнение запроса
    const static TYPE_STR C_ERROR = "c_error"; //Ошибка выполнения запроса

    //Объект ошибка
    const static TYPE_STR ERROR_OBJ = "Error_obj"; //Объект ошибка
        const static TYPE_STR ERROR_ID = "Error_id"; //Идентификатор ошибки
    // Описание идентификаторов ошибок (список возможных полей для поля ERROR_ID)
    const static TYPE_STR ERROR_UNDEFINED = "Error_undefined"; //Неизвестная ошибка
    const static TYPE_STR ERROR_PARSE = "Error_parse"; //ошибка при парсинге (отправлен не JSon-объект)
    const static TYPE_STR ERROR_MISSING_USER_ID = "Error_missing_user_id"; //В запросе нет UserId
    const static TYPE_STR ERROR_EMPTY_MESSAGE = "Error_empty_message"; //В запросе пустое сообщение
    const static TYPE_STR ERROR_NAME_INVALID = "Error_name_invalid"; //Недопустимое имя пользователя
    const static TYPE_STR ERROR_NAME_IS_USE = "Error_name_is_use"; //Имя пользователя уже используется
    //итд

    const static TYPE_STR DATE = "Date"; //Дата
    const static TYPE_STR TIME = "Time"; //Время
}
#endif // COMMON_CONSTS_H
