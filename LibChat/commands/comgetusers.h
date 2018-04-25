#ifndef COMGETUSERS_H
#define COMGETUSERS_H

#include <QObject>
#include "chatcommand.h"
#include "ichatmodel.h"

namespace chat {

class ComGetUsers : public ChatCommand
{
public:
    ComGetUsers();
};
}
#endif // COMGETUSERS_H
