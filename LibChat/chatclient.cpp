#include "chatclient.h"

chat::ChatClient::ChatClient(chat::IChatNetworkManager *networkManager, chat::ChatClientParameters *params, QObject *parent): QObject(parent), networkManager(networkManager)
{
    model = new ChatModel(this);
    m_currentState = IChatNetworkManager::Offline;
    networkManager->setParent(this);
    params->setParent(this);
    connect(networkManager,SIGNAL(dataReceived(QJsonObject)),this,SLOT(updateChat(QJsonObject)));
    connect(networkManager,SIGNAL(stateChanged(IChatNetworkManager::NetworkState)),this,SLOT(onStateChanged(IChatNetworkManager::NetworkState)));
    connect(model,SIGNAL(authStateChanged(IChatModel::AuthState)),this,SLOT(onAuthStateChanged(IChatModel::AuthState)));
    com_manager = new ChatCommandManager(this);
    this->params = params;
    timerConnect.reset(new QTimer);
    connect(timerConnect.data(),SIGNAL(timeout()),this,SLOT(periodicConnect()));
    timerConnect->setInterval(5000);
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

void chat::ChatClient::periodicConnect()
{
    networkManager->connectToHost(params->getAdress(), params->getPort());
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
        executeCommand(new ComAuthUser(params->personalData()));
        timerConnect->stop();
        com_manager->start();
    }
    else{
        com_manager->stop();
        timerConnect->start();
    }
}

void chat::ChatClient::onAuthStateChanged(IChatModel::AuthState authState)
{
    switch (authState) {
    case IChatModel::AuthSUCCESS:
        com_manager->setIsAuthed(true);
        break;
    case IChatModel::NotAuth:
    case IChatModel::NameIsAlreadyUse:
        com_manager->setIsAuthed(false);
        break;
    default:
        break;
    }
}

chat::ChatModelUpdater::ChatModelUpdater(chat::ChatClient *client)
{
    this->client = client;
    parser.reset(new ChatRespParser(client));
}

void chat::ChatModelUpdater::updateData(const QJsonObject &obj)
{
    QJsonObject object = obj;
    if(obj.contains(chat::CODE_RESP)){
        if(obj.contains(chat::COMMAND_OBJ) && obj.value(chat::COMMAND_OBJ).isObject()){
            QString comId = obj.value(chat::COMMAND_OBJ).toObject().value(chat::COMMAND_ID).toString();
            QString res = obj.value(chat::CODE_RESP).toString();
            if(comId == chat::C_AUTH_REQ && res == chat::C_SUCCESS){
                client->getModel()->setAuthState(IChatModel::AuthSUCCESS);
                return;
            }
        }
    }
    parser->setJsonObject(&object);
    parser->parse();
    if(parser->getResultResp() == ChatRespParser::SUCCESS){
        switch (parser->getTypeResp()) {
        case ChatRespParser::AuthResp:

            break;
        case ChatRespParser::ConnectUser:

            break;
        case ChatRespParser::DisconnectUser:
            break;
        case ChatRespParser::Message:
            break;
        case ChatRespParser::UsersList:{
            UsersListPtr users = unpack<UsersListPtr>(parser->data());
            if(!users.isNull()){
                for(int i = 0; i < users->count(); i++){
                    qDebug() << users->at(i).userId;
                }
            }
            break;
        }

        default:
            break;
        }
    }
}
