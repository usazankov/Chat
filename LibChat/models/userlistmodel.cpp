#include "userlistmodel.h"

chat::UserListModel::UserListModel(QObject *parent) : QAbstractListModel(parent)
{
    initRoleNames();
}

int chat::UserListModel::rowCount(const QModelIndex &parent) const
{
    return users.count();
}

QVariant chat::UserListModel::data(const QModelIndex &index, int role) const
{
    int row = index.row();
    User user = users.at(row);
    switch (role) {
        case UserIDRole:
        return QVariant::fromValue(user.userId);
        break;
    default:
        break;
    }
    return QVariant();
}

QHash<int, QByteArray> chat::UserListModel::roleNames() const
{
    return roles;
}

void chat::UserListModel::addUser(const chat::User &user)
{
    int index = 0;
    if(users.count() > 0)
        index = users.count();
    beginInsertRows(QModelIndex(), index, index);
    users.append(user);
    endInsertRows();
}

void chat::UserListModel::removeUser(const chat::User &user)
{

    int index = users.indexOf(user);
    beginRemoveRows(QModelIndex(), index, index);
    users.removeOne(user);
    endRemoveRows();
}

void chat::UserListModel::removeUser(const QString &userId)
{

    for(auto iter = users.begin(); iter != users.end(); iter++){
        if((*iter).userId == userId){
            beginRemoveRows(QModelIndex(), 0, users.count()-1);
            users.erase(iter);
            endRemoveRows();
        }
    }
}

void chat::UserListModel::setUsersList(const QList<chat::User> &list)
{
    int end = 0;
    if(list.count() > 0)
        end = list.count();
    beginInsertRows(QModelIndex(), 0, end);
    users = list;
    endInsertRows();
}

void chat::UserListModel::clearUsersList()
{
    int end = 0;
    if(users.count() > 0)
        end = users.count();
    beginRemoveRows(QModelIndex(), 0, end);
    users.clear();
    endRemoveRows();
}

void chat::UserListModel::initRoleNames()
{
    roles[UserIDRole] = "userId";

}
