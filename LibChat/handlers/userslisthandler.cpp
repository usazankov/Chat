#include "userslisthandler.h"

chat::UsersListHandler::UsersListHandler(QJsonObject *doc) : ChatHandler(doc)
{

}

QVariant chat::UsersListHandler::data()
{
    UsersListPtr listPtr(new QList<User>);
    if(obj->contains(chat::USERS_LIST)){
        if(obj->value(chat::USERS_LIST).isArray()){
            QJsonArray arr = obj->value(chat::USERS_LIST).toArray();
            if(!arr.empty()){
                for(QJsonValue item : arr){
                    if(item.isObject()){
                        QJsonObject temp = item.toObject();
                        User user;
                        if(temp.contains(chat::USER_OBJ) && temp.value(chat::USER_OBJ).isObject()){
                            user.userId = temp.value(chat::USER_OBJ).toObject().value(chat::USER_ID).toString();
                        }
                        if(!user.userId.isEmpty())
                            listPtr->push_back(user);
                    }
                }
            }
        }
    }
    return QVariant::fromValue(listPtr);
}
