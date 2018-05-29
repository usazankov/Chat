#include "errordecoratorhandler.h"

ErrorDecoratorHandler::ErrorDecoratorHandler(HandlerRequest *handler) : DecoratorHandler(handler)
{

}

void ErrorDecoratorHandler::process(ClientCommandPtr com) const
{
    if(com->result != server_consts::SUCCESS){
        QString errStr;
        switch (com->result) {
        case server_consts::UndefinedError:
            errStr = chat::ERROR_UNDEFINED;
            break;
        case server_consts::ErrorParseRequest:
            errStr = chat::ERROR_PARSE;
            break;
        case server_consts::MissingUserID:
            errStr = chat::ERROR_MISSING_USER_ID;
            break;
        case server_consts::MissingToken:
            errStr = chat::ERROR_MISSING_USER_ID;
            break;
        case server_consts::EmptyMessage:
            errStr = chat::ERROR_EMPTY_MESSAGE;
            break;
        default:
            errStr = chat::ERROR_UNDEFINED;
            break;
        }
        com->data.addProperty(chat::CODE_RESP, chat::C_ERROR);
        com->data.addChildObj(chat::ERROR_OBJ, chat::ChatRequest(chat::ERROR_ID, errStr));
    }else{
        com->data.addProperty(chat::CODE_RESP, chat::C_SUCCESS);
    }
}

ClientCommandPtr ErrorDecoratorHandler::data() const
{
    ClientCommandPtr root = DecoratorHandler::data();
    ClientCommandPtr com = root;
    process(com);
    if(!com->com_onError.isNull())
        process(com->com_onError);
    if(!com->com_onSuccess.isNull())
        process(com->com_onSuccess);

    return root;
}
