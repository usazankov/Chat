#ifndef WORKER_H
#define WORKER_H

#include <QObject>
#include <QRunnable>
#include <QJsonDocument>
#include "authorizator.h"
#include <QScopedPointer>
#include <parserrequest.h>
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
    QByteArray data;
    ServerEvent event;
    QScopedPointer<Authorizator> auth_ptr;
    QScopedPointer<ParserRequest> parser_ptr;
    void process_data();
    void process_event();
    void authorization();
signals:
    void result(const ClientCommand &com);
public slots:

    // QRunnable interface
public:
    void run();
};

#endif // WORKER_H
