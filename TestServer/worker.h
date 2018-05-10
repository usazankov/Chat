#ifndef WORKER_H
#define WORKER_H

#include <QObject>
#include <QRunnable>

class Worker : public QObject, public QRunnable
{
    Q_OBJECT
public:
    explicit Worker(const QByteArray &arr, QObject *parent = nullptr);
private:
    QByteArray data;
signals:
    void result(const QByteArray &res, const QVariantMap &params);
public slots:

    // QRunnable interface
public:
    void run();
};

#endif // WORKER_H
