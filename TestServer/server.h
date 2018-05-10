#ifndef SERVER_H
#define SERVER_H

#include <QTcpServer>
#include "client.h"
#include "server_consts.h"

class Server : public QObject
{
    Q_OBJECT
public:
    explicit Server(QObject *parent = nullptr);
    void startServer(const QHostAddress &address, quint16 port);
public slots:
    void onAuthenticated(const QString &idUser, Client *client);
    void onSendToClients(const QString &from, const QVariantMap &params, const QByteArray &request);
    void onDisconnected(const QString &idUser);
private slots:
    void onNewConnection();
private:
    QScopedPointer<QTcpServer> m_ptcpServer;
    QHash<QString, QTcpSocket*> m_sockets;

};

#endif // SERVER_H
