#ifndef ICHATNETWORKMANAGER_H
#define ICHATNETWORKMANAGER_H

#include <QObject>
#include <QHostAddress>
#include "../Common/chatrequest.h"
namespace chat {
    static const int sizeHash = 16;
class LIBCHATSHARED_EXPORT IChatNetworkManager : public QObject
{
    Q_OBJECT
public:
    explicit IChatNetworkManager(QObject *parent = nullptr);
    virtual void connectToHost(const QHostAddress &address, quint16 port) = 0;
    virtual bool execute(ChatRequest *request) = 0; // true - успешное выполнение, false - ошибка
    virtual void disconnectHost() = 0;
    enum NetworkState{
        Offline,
        Online,
        Connecting
    };
    enum ErrorNetwork{
        NoError = 0,
        CommunicationError = 1, //Проблемы со связью
        HashError = 2, //Ошибка вычисления хэша
    };
signals:
    void dataReceived(const QJsonObject &obj);
    void stateChanged(IChatNetworkManager::NetworkState newState);
    void error(chat::IChatNetworkManager::ErrorNetwork err);
public slots:
};
}
Q_DECLARE_METATYPE(chat::IChatNetworkManager::ErrorNetwork)
Q_DECLARE_METATYPE(chat::IChatNetworkManager::NetworkState)
#endif // ICHATNETWORKMANAGER_H
