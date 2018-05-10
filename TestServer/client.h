#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QTcpSocket>
#include "server_consts.h"

class Client : public QObject
{
    Q_OBJECT
public:
    explicit Client(QObject *parent, QTcpSocket *sock);
    QTcpSocket * getSocket();
private:
    QTcpSocket *socket;
    QString idUser;
private slots:

signals:
    void authenticated(const QString &idUser, Client *client);
    void sendToClients(const QString &from, const QVariantMap &params, const QByteArray &request);
    void disconnected(const QString &idUser);
public slots:

};
Q_DECLARE_METATYPE(Client*)
#endif // CLIENT_H
