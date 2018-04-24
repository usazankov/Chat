#ifndef CHATTCPMANAGER_H
#define CHATTCPMANAGER_H

#include <QObject>
#include "ichatnetworkmanager.h"
#include "chatrequest.h"
#include <QTcpSocket>
#include <QHostAddress>
#include "common_consts.h"
namespace chat {

class ChatTCPManager : public IChatNetworkManager
{
    Q_OBJECT
public:
    explicit ChatTCPManager(QObject *parent = nullptr);
    explicit ChatTCPManager(qintptr socketDescriptor, QObject *parent = nullptr);

    //IChatNetworkManager interface
    bool execute(ChatRequest *request); // true - успешное выполнение, false - ошибка
    void connectToChat(const QHostAddress &address, quint16 port);
    void disconnectChat();

signals:

private slots:
    void onSocketConnected();
    void onSocketDisconnected();
    void onSocketReadyRead();
    void onSocketDisplayError(QAbstractSocket::SocketError socketError);
private:
    void initChat();
    void sendData(ChatRequest * request);
    QTcpSocket *socket;
    quint32 blockSize;
    QHostAddress address;
    quint16 port;
};

}

#endif // CHATTCPMANAGER_H
