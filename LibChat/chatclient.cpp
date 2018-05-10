#include "chatclient.h"

chat::ChatClient::ChatClient(QObject *parent) : QObject(parent)
{
    model = new ChatModel(this);
    networkManager = new ChatTCPManager(this);
    connect(networkManager,SIGNAL(dataReceived(QJsonObject)),this,SLOT(updateChat(QJsonObject)));
    m_currentState = IChatNetworkManager::Offline;
    com_manager = new ChatCommandManager(this);
}

chat::ChatClient::ChatClient(chat::IChatNetworkManager *networkManager, QObject *parent): QObject(parent), networkManager(networkManager)
{
    model = new ChatModel(this);
    m_currentState = IChatNetworkManager::Offline;
    connect(networkManager,SIGNAL(dataReceived(QJsonObject)),this,SLOT(updateChat(QJsonObject)));
    connect(networkManager,SIGNAL(stateChanged(chat::IChatNetworkManager::NetworkState)),SLOT(onStateChanged(chat::IChatNetworkManager::NetworkState)));
    com_manager = new ChatCommandManager(this);
}

chat::ChatClient::~ChatClient()
{
    networkManager->deleteLater();
    model->deleteLater();
    com_manager->deleteLater();
}

void chat::ChatClient::setNetworkManager(chat::IChatNetworkManager *networkManager)
{
    this->networkManager = networkManager;
}

chat::ChatModel *chat::ChatClient::getModel()
{
    return model;
}

chat::IChatNetworkManager *chat::ChatClient::getNetworkManager()
{
    return networkManager;
}

void chat::ChatClient::executeCommand(ChatCommand *com)
{
    com->setChatClient(this);
    com_manager->executePostpone(com);
}

chat::IChatNetworkManager::NetworkState chat::ChatClient::currentState() const
{
    return m_currentState;
}

void chat::ChatClient::updateChat(const QJsonObject &obj)
{
    ChatModelUpdater updater(this);
    updater.updateData(obj);
}

void chat::ChatClient::onStateChanged(chat::IChatNetworkManager::NetworkState state)
{
    m_currentState = state;
    if(model)
        model->setState(state);
    if(state == IChatNetworkManager::Online)
        com_manager->start();
    else
        com_manager->stop();
}

chat::ChatModelUpdater::ChatModelUpdater(chat::ChatClient *client)
{
    this->client = client;
}

void chat::ChatModelUpdater::updateData(const QJsonObject &obj)
{

}
