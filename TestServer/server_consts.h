#ifndef SERVER_CONSTS_H
#define SERVER_CONSTS_H
#include <QObject>

namespace server_consts {

static const QString TYPE_ACTION = "type_action";
enum TypeAction{
    ToAll = 0,
    ToClient,
    ToListClient
};

static const QString RESULT = "result";
enum Result{
    UndefinedError = 0,
    MissingToken,
    ErrorParse,
    SUCCESS
};

static const QString TOKEN = "token";
}
Q_DECLARE_METATYPE(server_consts::TypeAction)
Q_DECLARE_METATYPE(server_consts::Result)
#endif // SERVER_CONSTS_H
