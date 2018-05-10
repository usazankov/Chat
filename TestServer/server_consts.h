#ifndef SERVER_CONSTS_H
#define SERVER_CONSTS_H
#include <QObject>

namespace server_consts {
enum sendTo{
    ToAll = 0,
    ToClient,
    ToListClient
};
}
Q_DECLARE_METATYPE(server_consts::sendTo)
#endif // SERVER_CONSTS_H
