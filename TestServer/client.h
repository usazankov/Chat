#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QTcpSocket>
#include "server_consts.h"
#include "worker.h"
#include "client_p.h"
#include <QThreadPool>
#include <QDataStream>
#include <QScopedPointer>
class ClientPrivate;
class Client : public QObject
{
    Q_OBJECT
public:
    explicit Client(QObject *parent, QTcpSocket *sock);
    QTcpSocket * getSocket();
    void serUsersList(const QStringList &list);
    virtual ~Client();
private:
    Q_DECLARE_PRIVATE(Client)
    QTcpSocket *socket;
    qint32 m_msgSize;
protected:
    ClientPrivate * const d_ptr;
    Client(ClientPrivate &dd, QObject *parent);
signals:
    void authenticated(const QString &idUser, Client *client);
    void sendToClients(const QString &from, const QVariantMap &params, const QByteArray &request);
    void disconnected(const QString &idUser);
public slots:
    void onUserLeft(const QString &idUser);
    void onUserConnect(const QString &idUser);
private slots:
    void onReadyRead();
    void onDisconnected();
    void onResultReady(const QByteArray &arr, const QVariantMap &params);
};
Q_DECLARE_METATYPE(Client*)
#endif // CLIENT_H
