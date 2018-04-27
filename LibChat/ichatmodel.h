#ifndef ICHATMODEL_H
#define ICHATMODEL_H

#include <QObject>
#include <QAbstractListModel>
#include "ichatnetworkmanager.h"
namespace chat {

class IChatModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(IChatNetworkManager::NetworkState state READ state WRITE setState NOTIFY stateChanged)

public:
    explicit IChatModel(QObject *parent = nullptr);

    virtual ~IChatModel(){}

    //Получить список пользователей
    virtual QAbstractListModel* usersListModel() = 0;

    //Получить список сообщений
    virtual QAbstractListModel* messagesListModel() = 0;

    IChatNetworkManager::NetworkState state() const;

private:
    IChatNetworkManager::NetworkState m_state;

signals:
    void stateChanged(IChatNetworkManager::NetworkState state);

public slots:
    void setState(IChatNetworkManager::NetworkState state);
};

}
#endif // ICHATMODEL_H
