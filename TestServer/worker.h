#ifndef WORKER_H
#define WORKER_H

#include <QObject>
#include <QRunnable>
#include <QJsonDocument>
#include "authorizator.h"
#include <QScopedPointer>
#include <parserrequest.h>

class Worker : public QObject, public QRunnable
{
    Q_OBJECT
public:
    explicit Worker(const QByteArray &arr, QObject *parent = nullptr);
    ~Worker();
private:
    QByteArray data;
    QScopedPointer<Authorizator> auth_ptr;
    QScopedPointer<ParserRequest> parser_ptr;
    void process();
signals:
    void result(const QByteArray &res, const QVariantMap &params);
public slots:

    // QRunnable interface
public:
    void run();
};

#endif // WORKER_H
