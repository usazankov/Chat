#ifndef ISERVER_H
#define ISERVER_H

#include <QObject>
#include <QHostAddress>
#include <QTcpSocket>

class IServer : public QObject
{
    Q_OBJECT
public:
    explicit IServer(QObject *parent = nullptr);

    virtual void startServer(const QHostAddress &address = QHostAddress::Any, quint16 port = 0) = 0;
    virtual void sendToAllUsers(const QByteArray &request) = 0;
    virtual void sendToUser(QTcpSocket* socket, const QByteArray &request) = 0;
    virtual void sendToListUsers(QList<QTcpSocket*>, const QByteArray &request) = 0;
signals:

public slots:
};

#endif // ISERVER_H
