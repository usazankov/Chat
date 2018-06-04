#include "userhandler.h"

chat::UserHandler::UserHandler(QJsonObject *obj)
{
    this->obj = obj;
}

QVariant chat::UserHandler::data()
{
    if(obj->contains(chat::USER_OBJ) && obj->value(chat::USER_OBJ).isObject()){
        if(obj->value(chat::USER_OBJ).toObject().contains(chat::USER_ID)){
            User user;
            QString userID = obj->value(chat::USER_OBJ).toObject().value(chat::USER_ID).toString();
            if(!userID.isNull()){
                user.userId = userID;
            }
            return QVariant::fromValue(user);
        }
    }
    return QVariant();
}
