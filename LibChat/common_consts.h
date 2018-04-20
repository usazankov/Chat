#ifndef COMMON_CONSTS_H
#define COMMON_CONSTS_H
#include <string>

namespace chat {
    // Объект список пользователей
    const static std::string USERS_LIST = "Users_list"; //Объект список пользователей
        const static std::string COUNT_USERS_ONLINE = "Count_users_online"; //Количество пользователей в онлайне
        // Описание объекта пользователя:
        const static std::string USER_OBJ = "User_obj";  //Объект пользователь
            const static std::string USER_ID = "User_id"; //Идентификатор пользователя
            const static std::string USER_NAME = "User_name"; //Имя пользователя
            const static std::string USER_STATUS = "User_status"; //Объект статус пользователя
                const static std::string USER_ONLINE = "u_online"; //Пользователь в онлайне
                const static std::string USER_OFFLINE = "u_offline"; //Пользователь в офлайне
            const static std::string USER_INFO = "User_info"; //Какая-то информация о пользователе


    // Описание объекта команда:
    const static std::string COMMAND_OBJ = "Command_obj"; //Объект команда
        const static std::string COMMAND_ID = "Command_id"; //Идентификатор команды
        const static std::string COMMAND_OBJ_PARAM = "Command_param"; //Объект параметры команды
            const static std::string COMMAND_PARAM1 = "Command_param_1"; //1 параметр команды
            const static std::string COMMAND_PARAM2 = "Command_param_2"; //2 параметр команды
            // итд...

    // Описание идентификаторов команд (список возможных полей для поля Command_id)
    const static std::string C_AUTH_REQ = "c_auth_req"; //Запрос на авторизацию
    const static std::string C_GET_COUNT_ONLINE = "c_get_count_online"; //Получить количество пользователей онлайн
    const static std::string C_GET_ALL_USERS = "c_get_users"; //Получить список всех пользователей
    const static std::string C_GET_ONLINE_USERS = "c_get_online_users"; //Получить список пользователей в онлайне
    const static std::string C_GET_USER_INFO = "c_get_user_info"; //Получить подробную информацию о пользователе (ID пользователя передается в Command_param1)
    const static std::string C_SEND_MESSAGE = "c_send_message"; //Отправить сообщение в чат
                                                           //Сообщение передается в поле Command_param_1
                                                           //При не пустом Command_param_2 передается конкретному пользователю
    const static std::string C_GET_EVENTS = "c_get_events_users"; //Получить события от сервера
                                                             //(Сервер должен вернуть список пользователей, изменивших свое состояние, имя или еще что-то)

    const static std::string EVENTS_OBJ = "Events_obj"; //Объект событие от сервера
        //В этом объекте (EVENTS_OBJ) содержится объект USERS_LIST - список пользователей, изменивших свое состояние, имя или еще что-то
        const static std::string MESSAGES_LIST = "Messages_list"; //Список сообщений от пользователей
            const static std::string MESSAGE_OBJ = "Message_obj"; //Объект сообщение
                //Здесь содержится USER_ID и может быть USER_NAME
                const static std::string MESSAGE_DATE = "Message_data"; //Дата сообщения
                const static std::string MESSAGE_TIME = "Message_time"; //Время сообщения
                const static std::string MESSAGE_TEXT = "Message_text"; //Текст сообщения

    const static std::string CODE_RESP = "Code_resp"; //Код ответа сервера

    //Коды ответа сервера
    const static std::string AUTH_SUCCESS = "auth_success"; //Успешная авторизация
    const static std::string C_SUCCESS = "c_success"; //Успешное выполнение запроса
    const static std::string C_ERROR = "c_error"; //Ошибка выполнения запроса

    //Объект ошибка
    const static std::string ERROR_OBJ = "Error_obj"; //Объект ошибка
        const static std::string ERROR_ID = "Error_id"; //Идентификатор ошибки

    // Описание идентификаторов ошибок (список возможных полей для поля ERROR_ID)
    const static std::string ERROR_NAME_INVALID = "Error_name_invalid"; //Недопустимое имя пользователя
    const static std::string ERROR_NAME_IS_USE = "Error_name_is_use"; //Имя пользователя уже используется
    //итд
}
#endif // COMMON_CONSTS_H
