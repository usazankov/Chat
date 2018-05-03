#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QTcpSocket>

class Client : public QObject
{
    Q_OBJECT
public:
    explicit Client(QTcpSocket *sock);
    QTcpSocket * getSocket();
private:
    QTcpSocket *socket;
    QString idUser;
private slots:

signals:
    void authenticated(const QString &idUser, Client *client);
    void sendToAll(const QByteArray &request);
    void sendToUser(const QString &idUser, const QByteArray &request);
    void sendToListUsers(const QStringList &listIdUsers, const QByteArray &request);
    void disconnected(const QString &idUser);
public slots:

};
Q_DECLARE_METATYPE(Client)
#endif // CLIENT_H
