#ifndef COMAUTHUSER_H
#define COMAUTHUSER_H

#include "chatcommand.h"
#include "personaldata.h"
#include "chatclient.h"

namespace chat {
class ComAuthUser : public ChatCommand
{
public:
    ComAuthUser(const PersonalData &data);
    ~ComAuthUser();
    // ChatCommand interface
    void execute();
private:
    PersonalData data;
};
}
#endif // COMAUTHUSER_H
