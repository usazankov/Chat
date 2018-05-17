#include "chatclient.h"

chat::ChatClient::ChatClient(chat::IChatNetworkManager *networkManager, chat::ChatClientParameters *params, QObject *parent): QObject(parent), networkManager(networkManager)
{
    model = new ChatModel(this);
    m_currentState = IChatNetworkManager::Offline;
    networkManager->setParent(this);
    params->setParent(this);
    connect(networkManager,SIGNAL(dataReceived(QJsonObject)),this,SLOT(updateChat(QJsonObject)));
    connect(networkManager,SIGNAL(stateChanged(IChatNetworkManager::NetworkState)),this,SLOT(onStateChanged(IChatNetworkManager::NetworkState)));
    com_manager = new ChatCommandManager(this);
    this->params = params;

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

void chat::ChatClient::setChatClientParameters(chat::ChatClientParameters *params)
{
    if (this->params == params)
        return;
    this->params = params;
    emit chatClientParametersChanged();
}

chat::ChatClientParameters *chat::ChatClient::chatClientParameters() const
{
    return params;
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

void chat::ChatClient::onPersonalDataChanged(chat::PersonalData data)
{

}

void chat::ChatClient::updateChat(const QJsonObject &obj)
{
    ChatModelUpdater updater(this);
    updater.updateData(obj);
}

void chat::ChatClient::onStateChanged(IChatNetworkManager::NetworkState state)
{
    m_currentState = state;
    if(model)
        model->setState(state);
    if(state == IChatNetworkManager::Online){
        com_manager->start();
    }
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
