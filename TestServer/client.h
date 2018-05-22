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
#include "serverevent.h"
#include "clientcommand.h"
#include <QFutureWatcher>
#include <QFuture>
#include <qtconcurrentrun.h>
class ClientPrivate;
class Server;
class Client : public QObject
{
    Q_OBJECT
public:
    explicit Client(Server *server, QTcpSocket *sock);
    QTcpSocket * getSocket();
    virtual ~Client();
private:
    Q_DECLARE_PRIVATE(Client)
    QTcpSocket *socket;
    qint32 m_msgSize;
    bool isAuthenticated(const ClientCommand &com = ClientCommand());
    void writeToSocket(const QByteArray &req);
protected:
    ClientPrivate * const d_ptr;
    Client(ClientPrivate &dd, QObject *parent);
public slots:
    void onServerEvent(const ServerEvent &event);
private slots:
    void onReadyRead();
    void onDisconnected();
    void onResultReady();
};
Q_DECLARE_METATYPE(Client*)
#endif // CLIENT_H
