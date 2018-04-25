#ifndef CHATCLIENT_H
#define CHATCLIENT_H

#include <QObject>
#include "ichatmodel.h"
#include "chatmodel.h"
#include "ichatnetworkmanager.h"
#include "chattcpmanager.h"
#include "commands/chatcommand.h"
#include "commands/comgetusers.h"
#include "commands/comsendmessage.h"

namespace chat {
class ChatCommand;
class ChatClient : public QObject
{
    Q_OBJECT
public:
    explicit ChatClient(QObject *parent = nullptr);
    explicit ChatClient(IChatNetworkManager *networkManager, QObject *parent = nullptr);
    virtual ~ChatClient();
    //Установить объект, с помощью которого будем соединяться с внешним миром
    void setNetworkManager(IChatNetworkManager *networkManager);

    //Получить указатель на модель
    ChatModel *getModel();

    //Получить указатель на объект, с помощью которого будем соединяться с внешним миром
    IChatNetworkManager *getNetworkManager();

    void executeCommand(ChatCommand *com);

    IChatNetworkManager::NetworkState currentState()const;

    friend class ChatModelUpdater;
private:
    IChatNetworkManager *networkManager;
    ChatModel *model;
    IChatNetworkManager::NetworkState m_currentState;
signals:

public slots:
    void updateChat(const QJsonObject &obj);
    void onStateChanged(IChatNetworkManager::NetworkState state);
};

class ChatModelUpdater
{
public:
    ChatModelUpdater(ChatClient *client);
    void updateData(const QJsonObject &obj);
private:
    ChatClient *client;

};
}
#endif // CHATCLIENT_H
