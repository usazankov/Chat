#include "chatmodel.h"

chat::ChatModel::ChatModel(QObject *parent) : IChatModel(parent)
{
    us_ptr.reset(new UserListModel(this));
    ms_ptr.reset(new MessageListModel(this));
}

QAbstractListModel *chat::ChatModel::usersListModel()
{
    return us_ptr.data();
}

QAbstractListModel *chat::ChatModel::messagesListModel()
{
    return ms_ptr.data();
}

chat::UserListModel *chat::ChatModel::usersModel()
{
    return us_ptr.data();
}
