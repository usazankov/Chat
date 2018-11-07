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
    if(root->type == server_consts::SendToThisClient
            || root->type == server_consts::AuthenticationClient){
        addMessageId(root);
    }
    if(root->com_onSuccess){
        addMessageId(root->com_onSuccess);
    }
    if(root->com_onError){
        addMessageId(root->com_onError);
    }
    return root;
}

void MessageIdHandler::addMessageId(ClientCommandPtr root) const
{
    QJsonObject obj = doc->object();
    if(obj.contains(chat::ID_MSG)){
        QString idMsg = obj.value(chat::ID_MSG).toString();
        if(idMsg != chat::NO_MSG_ID)
            root->data.addProperty(chat::ID_MSG, idMsg);
    }
}
