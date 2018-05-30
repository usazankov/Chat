#include "chathandler.h"

chat::ChatHandler::ChatHandler()
{

}

chat::ChatHandler::ChatHandler(QJsonObject *obj)
{
    this->obj = obj;
}

