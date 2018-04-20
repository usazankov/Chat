#ifndef CHATNETWORKMANAGER_H
#define CHATNETWORKMANAGER_H

#include <QObject>
#include "chatrequest.h"
#include "chatresponse.h"
#include <QTcpSocket>
#include <QHostAddress>
#include "common_consts.h"

class ChatNetworkManager : public QObject
{
    Q_OBJECT
public:
    explicit ChatNetworkManager(int socketDescriptor = 0, QObject *parent = nullptr);
    virtual ChatResponse *execute(ChatRequest *request); // Здесь освободить память для ChatResponse * нужно вызывающему методу
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
    quint16 blockSize;
    QHostAddress address;
    quint16 port;
};

#endif // CHATNETWORKMANAGER_H
