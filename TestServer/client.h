#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QTcpSocket>
#include "server_consts.h"
#include "worker.h"
#include <QThreadPool>
#include <QDataStream>
class Client : public QObject
{
    Q_OBJECT
public:
    explicit Client(QObject *parent, QTcpSocket *sock);
    QTcpSocket * getSocket();
private:
    QTcpSocket *socket;
    QString idUser;
    qint32 m_msgSize;
private slots:
    void onReadyRead();
    void onDisconnected();
    void onResultReady(const QByteArray &arr, const QVariantMap &params);
signals:
    void authenticated(const QString &idUser, Client *client);
    void sendToClients(const QString &from, const QVariantMap &params, const QByteArray &request);
    void disconnected(const QString &idUser);
public slots:

};
Q_DECLARE_METATYPE(Client*)
#endif // CLIENT_H
