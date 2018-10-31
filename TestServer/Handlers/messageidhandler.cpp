#include "messageidhandler.h"

MessageIdHandler::MessageIdHandler(HandlerRequest *handler, QJsonDocument *doc) : DecoratorHandler(handler)
{
    this->doc = doc;
}

MessageIdHandler::~MessageIdHandler()
{

}

ClientCommandPtr MessageIdHandler::data() const
{
    ClientCommandPtr root = DecoratorHandler::data();
    QJsonObject obj = doc->object();
    if(obj.contains(chat::ID_MSG)){
        QString idMsg = obj.value(chat::ID_MSG).toString();
        if(idMsg != chat::NO_MSG_ID)
            root->data.addProperty(chat::ID_MSG, idMsg);
    }
    return root;
}
