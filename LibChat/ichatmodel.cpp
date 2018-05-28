#include "ichatmodel.h"

chat::IChatModel::IChatModel(QObject *parent) : QObject(parent)
{
    m_state = IChatNetworkManager::Offline;
}

chat::IChatNetworkManager::NetworkState chat::IChatModel::state() const
{
    return m_state;
}

chat::IChatModel::AuthState chat::IChatModel::authState() const
{
    return m_authState;
}

void chat::IChatModel::setState(IChatNetworkManager::NetworkState state)
{
    if (m_state == state)
        return;

    m_state = state;
    emit stateChanged(m_state);
}

void chat::IChatModel::setAuthState(IChatModel::AuthState authState)
{
    if (m_authState == authState)
        return;

    m_authState = authState;
    emit authStateChanged(m_authState);
}

