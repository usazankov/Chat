#ifndef CHATCLIENT_H
#define CHATCLIENT_H

#include <QObject>
#include "ichatmodel.h"
#include "chatmodel.h"
#include "ichatnetworkmanager.h"
#include "chattcpmanager.h"
#include "commands/comauthuser.h"
#include "chatcommandmanager.h"
#include "chatclientparameters.h"
#include <QQueue>
#include <QTimer>

namespace chat {
class ChatCommand;
class ChatCommandManager;
class LIBCHATSHARED_EXPORT ChatClient : public QObject
{
    Q_OBJECT
public:
    explicit ChatClient(IChatNetworkManager *networkManager, ChatClientParameters *params, QObject *parent = nullptr);
    virtual ~ChatClient();

    //Установить объект, с помощью которого будем соединяться с внешним миром
    void setNetworkManager(IChatNetworkManager *networkManager);

    //Установить параметры клиента
    void setChatClientParameters(ChatClientParameters *params);

    //Получить параметры клиента
    ChatClientParameters *chatClientParameters()const;

    //Получить указатель на модель
    ChatModel *getModel();

    //Получить указатель на объект, с помощью которого будем соединяться с внешним миром
    IChatNetworkManager *getNetworkManager();

    void executeCommand(ChatCommand *com);

    IChatNetworkManager::NetworkState currentState()const;

    //Support Class
    friend class ChatModelUpdater;
private:
    IChatNetworkManager *networkManager;
    ChatModel *model;
    IChatNetworkManager::NetworkState m_currentState;
    ChatCommandManager *com_manager;
    ChatClientParameters *params;
    QScopedPointer<QTimer> timerConnect;
signals:
    void chatClientParametersChanged();
private:
    void onPersonalDataChanged(PersonalData data);
private slots:
    void periodicConnect();
public slots:
    void updateChat(const QJsonObject &obj);
    void onStateChanged(IChatNetworkManager::NetworkState state);
    void onAuthStateChanged(IChatModel::AuthState authState);

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
