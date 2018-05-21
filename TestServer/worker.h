#ifndef WORKER_H
#define WORKER_H

#include <QObject>
#include <QRunnable>
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

class Worker : public QObject, public QRunnable
{
    Q_OBJECT
public:
    explicit Worker(const QByteArray &arr, QObject *parent = nullptr);
    explicit Worker(const ServerEvent &event, QObject *parent = nullptr);
    ~Worker();
private:
    QScopedPointer<IParserRequest> parser_ptr;
signals:
    void result(const ClientCommand &com);
public slots:

    // QRunnable interface
public:
    void run();
};

#endif // WORKER_H
