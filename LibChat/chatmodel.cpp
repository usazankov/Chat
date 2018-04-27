#include "chatmodel.h"

chat::ChatModel::ChatModel(QObject *parent) : IChatModel(parent)
{

}

QAbstractListModel *chat::ChatModel::usersListModel()
{

}

QAbstractListModel *chat::ChatModel::messagesListModel()
{
    return ms_ptr.data();
}
