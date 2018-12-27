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

        if(idMsg != chat::NO_MSG_ID && (root->type == server_consts::SendToThisClient || root->type == server_consts::AuthenticationClient))
            root->data.addProperty(chat::ID_MSG, idMsg);
        if(root->com_onSuccess != NULL){
            if(root->com_onSuccess->type == server_consts::SendToThisClient || root->com_onSuccess->type == server_consts::AuthenticationClient)
                root->com_onSuccess->data.addProperty(chat::ID_MSG, idMsg);
        }
        if(root->com_onError != NULL){
            if(root->com_onError->type == server_consts::SendToThisClient || root->com_onError->type == server_consts::AuthenticationClient)
                root->com_onError->data.addProperty(chat::ID_MSG, idMsg);
        }
    }
    return root;
}
