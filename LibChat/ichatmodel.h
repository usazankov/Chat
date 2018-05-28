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
    Q_PROPERTY(IChatModel::AuthState authState READ authState WRITE setAuthState NOTIFY authStateChanged)
public:
    explicit IChatModel(QObject *parent = nullptr);

    virtual ~IChatModel(){}

    //Текущее состояние о регистрации пользователя
    enum AuthState{
        NotAuth = 0,
        NameIsAlreadyUse,
        AuthSUCCESS
    };
    //Получить список пользователей
    virtual QAbstractListModel* usersListModel() = 0;

    //Получить список сообщений
    virtual QAbstractListModel* messagesListModel() = 0;

    //Получить текущее состояние сети
    IChatNetworkManager::NetworkState state() const;

    //Получить текущее состояние о регистрации пользователя
    IChatModel::AuthState authState() const;

private:
    IChatNetworkManager::NetworkState m_state;
    bool m_isAuth;
    IChatModel::AuthState m_authState;

signals:
    void stateChanged(IChatNetworkManager::NetworkState state);
    void authStateChanged(IChatModel::AuthState authState);

public slots:
    void setState(IChatNetworkManager::NetworkState state);
    void setAuthState(IChatModel::AuthState authState);


}; 
}
Q_DECLARE_METATYPE(chat::IChatModel::AuthState)
#endif // ICHATMODEL_H
