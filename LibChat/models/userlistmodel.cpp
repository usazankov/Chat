#include "userlistmodel.h"

chat::UserListModel::UserListModel(QObject *parent) : QAbstractListModel(parent)
{
    initRoleNames();
}

int chat::UserListModel::rowCount(const QModelIndex &parent) const
{

}

QVariant chat::UserListModel::data(const QModelIndex &index, int role) const
{

}

QHash<int, QByteArray> chat::UserListModel::roleNames() const
{
    return roles;
}

void chat::UserListModel::initRoleNames()
{
    roles[FromRole] = "from";
    roles[BodyRole] = "body";
    roles[DateRole] = "date";
    roles[TimeRole] = "time";
}
