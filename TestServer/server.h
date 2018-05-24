#ifndef SERVER_H
#define SERVER_H

#include <QTcpServer>
#include "client.h"
#include "server_consts.h"
#include "globalstorage.h"
#include "clientcommand.h"
#include "serverevent.h"

class Client;
class Server : public QObject
{
    Q_OBJECT
public:
    explicit Server(QObject *parent = nullptr);
    virtual ~Server();

    //Запустить сервер
    void startServer(const QHostAddress &address, quint16 port);

    //Работа с клиентами
    void addClient(const QString &idUser, Client *client);
    void removeClient(const QString &idUser);

    //Выполнить команду
    void executeCommand(const ClientCommand &com);

private slots:
    void onNewConnection();
signals:
    //Событие от сервера
    void serverEvent(const ServerEvent &event);
private:
    QScopedPointer<QTcpServer> m_ptcpServer;
    QHash<QString, QTcpSocket*> m_sockets;

};

#endif // SERVER_H
