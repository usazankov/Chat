#include "ichatnetworkmanager.h"

chat::IChatNetworkManager::IChatNetworkManager(QObject *parent) : QObject(parent)
{
    qRegisterMetaType<IChatNetworkManager::NetworkState>();
}
