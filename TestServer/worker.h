#ifndef WORKER_H
#define WORKER_H

#include <QJsonDocument>
#include <QScopedPointer>
#include "iparserrequest.h"
#include "parserclientjson.h"
#include "parserserverevent.h"
#include "clientcommand.h"
#include "serverevent.h"
#include "chatrequest.h"
#include "common_consts.h"
#include <QDebug>

namespace Worker {
    ClientCommand executeClientRequest(const QByteArray &arr);
    ClientCommand executeServerEvent(const ServerEvent &event);
}
#endif // WORKER_H
