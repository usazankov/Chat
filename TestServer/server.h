#ifndef SERVER_H
#define SERVER_H

#include <QTcpServer>
#include "iserver.h"

class Server : public IServer
{
    Q_OBJECT
public:
    explicit Server(QObject *parent = nullptr);

public slots:
private slots:
    void onNewConnection();
private:
    QScopedPointer<QTcpServer> m_ptcpServer;
    // IServer interface
public:
    void startServer(const QHostAddress &address, quint16 port);
    void sendToAllSockets(const QByteArray &request);
    void sendToSocket(QTcpSocket* socket, const QByteArray &request);
    void sendToListSockets(QList<QTcpSocket*>, const QByteArray &request);
    QList<QTcpSocket*> listSockets();
};

#endif // SERVER_H
