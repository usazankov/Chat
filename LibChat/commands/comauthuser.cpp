#include "comauthuser.h"

chat::ComAuthUser::ComAuthUser(const chat::PersonalData &data)
{
    this->data = data;
}

chat::ComAuthUser::~ComAuthUser()
{

}

void chat::ComAuthUser::execute()
{
    ChatRequest req;
    req.addChildObj(chat::COMMAND_OBJ, ChatRequest(chat::COMMAND_ID, chat::C_AUTH_REQ));
    req.addProperty(chat::USER_ID, data.userName());
    client->getNetworkManager()->execute(&req);
}
