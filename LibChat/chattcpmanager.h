#ifndef CHATTCPMANAGER_H
#define CHATTCPMANAGER_H

#include <QObject>
#include "ichatnetworkmanager.h"
#include "../Common/chatrequest.h"
#include <QTcpSocket>
#include <QHostAddress>
#include "../Common/common_consts.h"
namespace chat {

class ChatTCPManager : public IChatNetworkManager
{
    Q_OBJECT
public:
    explicit ChatTCPManager(QObject *parent = nullptr);
    explicit ChatTCPManager(qintptr socketDescriptor, QObject *parent = nullptr);

    //IChatNetworkManager interface
    bool execute(ChatRequest *request); // true - успешное выполнение, false - ошибка
    void connectToHost(const QHostAddress &address, quint16 port);
    void disconnectHost();

signals:

private slots:
    void onSocketConnected();
    void onSocketDisconnected();
    void onSocketReadyRead();
    void onSocketError(QAbstractSocket::SocketError);
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
