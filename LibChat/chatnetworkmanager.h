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
    virtual bool execute(ChatRequest *request); // true - успешное выполнение, false - ошибка
    void connectToChat(const QHostAddress &address, quint16 port);
    void disconnectChat();
    enum ErrorNetwork{
        NoError = 0,
        CommunicationError = 1, //Проблемы со связью
        HashError = 2, //Ошибка вычисления хэша
    };
    Q_ENUM(ErrorNetwork)
signals:
    void dataReceived(const QJsonObject &obj);
    void error(ErrorNetwork err);
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
Q_DECLARE_METATYPE(chat::ChatNetworkManager::ErrorNetwork)
#endif // CHATNETWORKMANAGER_H
