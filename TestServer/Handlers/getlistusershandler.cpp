#include "getlistusershandler.h"

GetListUsersHandler::GetListUsersHandler(const QString &sourceUser)
{
    idUser = sourceUser;
}

GetListUsersHandler::GetListUsersHandler(QJsonDocument *doc)
{
    QJsonObject obj = doc->object();
    if(obj.contains(chat::USER_ID)){
        idUser = obj.value(chat::USER_ID).toString();
    }
}

GetListUsersHandler::~GetListUsersHandler()
{

}

ClientCommandPtr GetListUsersHandler::data() const
{
    std::unordered_set<std::string> set = GlobalStorage::instance().getUsers();
    ClientCommandPtr com(new ClientCommand);
    com->type = server_consts::SendToThisClient;
    QJsonArray arr;
    QJsonObject root;
    for(std::string item : set){
        if(idUser == QString::fromStdString(item))
            continue;
        QJsonObject user;
        user[chat::USER_ID] = QString::fromStdString(item);
        QJsonObject user_obj;
        user_obj.insert(chat::USER_OBJ, user);
        arr.append(user_obj);
    }
    root.insert(chat::USERS_LIST, arr);
    chat::ChatRequest req(root);
    com->data = req;
    if(set.empty()){
        com->result = server_consts::UndefinedError;
    }else{
        com->result = server_consts::SUCCESS;
    }
    return com;
}
