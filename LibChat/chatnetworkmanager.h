#ifndef CHATNETWORKMANAGER_H
#define CHATNETWORKMANAGER_H

#include <QObject>
#include "chatrequest.h"
#include <QTcpSocket>
#include <QHostAddress>
#include "common_consts.h"
namespace chat {
    static const int sizeHash = 16;
class ChatNetworkManager : public QObject
{
    Q_OBJECT
public:
    explicit ChatNetworkManager(qintptr socketDescriptor = 0, QObject *parent = nullptr);
    virtual void execute(ChatRequest *request);
    void connectToChat(const QHostAddress &address, quint16 port);
    void disconnectChat();
signals:
    void dataReceived(const QJsonObject &obj);
private slots:
    void onSocketConnected();
    void onSocketDisconnected();
    void onSocketReadyRead();
    void onSocketDisplayError(QAbstractSocket::SocketError socketError);
private:
    void initChat();
    void sendData(ChatRequest * request);
    ChatRequest *currentReq;
    QTcpSocket *socket;
    quint32 blockSize;
    QHostAddress address;
    quint16 port;
};

}
#endif // CHATNETWORKMANAGER_H
