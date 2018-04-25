#include "ichatmodel.h"

chat::IChatModel::IChatModel(QObject *parent) : QObject(parent)
{

}

chat::IChatNetworkManager::NetworkState chat::IChatModel::state() const
{
    return m_state;
}

void chat::IChatModel::setState(IChatNetworkManager::NetworkState state)
{
    if (m_state == state)
        return;

    m_state = state;
    emit stateChanged(m_state);
}
