#include "messagelistmodel.h"

chat::MessageListModel::MessageListModel(QObject *parent)
    : QAbstractListModel(parent)
{

}

int chat::MessageListModel::rowCount(const QModelIndex &parent) const
{
    return messages.size();
}

QVariant chat::MessageListModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    int row = index.row();
    auto message = messages[row];
    switch (role) {
    case FromRole:
        return message.getUser();
    case BodyRole:
        return message.getTextMessage();
    case DateRole:
        return message.getDateTime().date();
    case TimeRole:
        return message.getDateTime().time();
    default:
        break;
    }
    return QVariant();
}

void chat::MessageListModel::initRoleNames()
{
    roles[FromRole] = "from";
    roles[BodyRole] = "body";
    roles[DateRole] = "date";
    roles[TimeRole] = "time";
}

QHash<int, QByteArray> chat::MessageListModel::roleNames() const
{
    return roles;
}

void chat::MessageListModel::addMessage(const chat::Message &message)
{
    int index = messages.size() - 1;
    beginInsertRows(QModelIndex(), index, index);
    messages.push_back(message);
    endInsertRows();
}
