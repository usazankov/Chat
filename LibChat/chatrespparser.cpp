#include "chatrespparser.h"

chat::ChatRespParser::ChatRespParser(QObject *parent) : QObject(parent)
{
    handler.reset();
}

chat::ChatRespParser::ChatRespParser(QJsonObject *doc, QObject *parent) : QObject(parent)
{
    this->doc = doc;
    typeResp = ChatRespParser::Undefined;
    res = ChatRespParser::UndefinedError;
    handler.reset();
}

chat::ChatRespParser::~ChatRespParser()
{

}

void chat::ChatRespParser::setJsonObject(QJsonObject *obj)
{
    doc = obj;
}

void chat::ChatRespParser::parse()
{
    res = getResultResp();
    typeResp = getTypeResp();
    switch (typeResp) {
    case ChatRespParser::UsersList:
        handler.reset(new UsersListHandler(doc));
        break;
    case ChatRespParser::ConnectUser:
        handler.reset(new UserHandler(doc));
        break;
    case ChatRespParser::DisconnectUser:
        handler.reset(new UserHandler(doc));
        break;
    default:
        break;
    }
    if(!handler.isNull()){
        m_data = handler->data();
    }
}

QVariant chat::ChatRespParser::data()
{
    return m_data;
}

QDate chat::ChatRespParser::getDataResp() const
{

}

QTime chat::ChatRespParser::getTimeResp() const
{

}

chat::ChatRespParser::TypeResp chat::ChatRespParser::getTypeResp() const
{
    if(isEvent(*doc)){
        QString ev = getTypeEvent(*doc);
        if(ev == chat::E_CONNECT_USER){
            return ChatRespParser::ConnectUser;
        }else if(ev == chat::E_DISCONNECT_USER){
            return ChatRespParser::DisconnectUser;
        }else if(ev == chat::E_MESSAGE){
            return ChatRespParser::Message;
        }else if(ev == chat::E_USERS_LIST){
            return ChatRespParser::UsersList;
        }
    }else if(isCommand(*doc)){
        QString com = getTypeCommand(*doc);
        if(com == chat::C_AUTH_REQ){
            return ChatRespParser::AuthResp;
        }else if(com == chat::C_GET_ALL_USERS){
            return ChatRespParser::UsersListResult;
        }else if(com == chat::C_SEND_MESSAGE){
            return ChatRespParser::MessageResult;
        }
    }
    return ChatRespParser::Undefined;
}

chat::ChatRespParser::Result chat::ChatRespParser::getResultResp() const
{
    if(doc->contains(chat::CODE_RESP)){
        QString res = doc->value(chat::CODE_RESP).toString();
        if(!res.isNull()){
            if(res == chat::C_ERROR){
                return ChatRespParser::ErrorOnServer;
            }else if(res == chat::C_SUCCESS){
                if(isEvent(*doc) || isCommand(*doc)){
                    return ChatRespParser::SUCCESS;
                }
            }
        }
    }
    return ChatRespParser::ErrorParse;
}

bool chat::ChatRespParser::isCommand(const QJsonObject &obj) const
{
    if(obj.contains(chat::COMMAND_OBJ) && obj.value(chat::COMMAND_OBJ).isObject()){
        if(obj.value(chat::COMMAND_OBJ).toObject().contains(chat::COMMAND_ID))
            return true;
    }
    return false;
}

bool chat::ChatRespParser::isEvent(const QJsonObject &obj) const
{
    if(obj.contains(chat::EVENT_OBJ) && obj.value(chat::EVENT_OBJ).isObject()){
        if(obj.value(chat::EVENT_OBJ).toObject().contains(chat::EVENT_ID))
            return true;
    }
    return false;
}

QString chat::ChatRespParser::getTypeCommand(const QJsonObject &obj) const
{
    QJsonObject com_obj = obj.value(chat::COMMAND_OBJ).toObject();
    return com_obj.value(chat::COMMAND_ID).toString();
}

QString chat::ChatRespParser::getTypeEvent(const QJsonObject &obj) const
{
    QJsonObject com_obj = obj.value(chat::EVENT_OBJ).toObject();
    return com_obj.value(chat::EVENT_ID).toString();
}
