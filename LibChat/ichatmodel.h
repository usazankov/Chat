#ifndef ICHATMODEL_H
#define ICHATMODEL_H

#include <QObject>
#include <QAbstractListModel>
#include "ichatnetworkmanager.h"
namespace chat {

class IChatModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(chat::IChatNetworkManager::NetworkState state READ state WRITE setState NOTIFY stateChanged)

public:
    explicit IChatModel(QObject *parent = nullptr);

    virtual ~IChatModel(){}

    //Получить список пользователей
    virtual QAbstractListModel* usersListModel() = 0;

    //Получить список сообщений
    virtual QAbstractListModel* messagesListModel() = 0;

    chat::IChatNetworkManager::NetworkState state() const;

private:
    chat::IChatNetworkManager::NetworkState m_state;

signals:
    void stateChanged(chat::IChatNetworkManager::NetworkState state);

public slots:
    void setState(chat::IChatNetworkManager::NetworkState state);
};

}
#endif // ICHATMODEL_H
