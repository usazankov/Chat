#ifndef CHATMODEL_H
#define CHATMODEL_H

#include <QObject>
#include "ichatmodel.h"
#include "models/messagelistmodel.h"
#include "models/userlistmodel.h"
#include <QScopedPointer>

namespace chat {

class ChatModel : public IChatModel
{
    Q_OBJECT
public:
    explicit ChatModel(QObject *parent = nullptr);

    ~ChatModel(){}
    // IChatModel interface
    QAbstractListModel *usersListModel();
    QAbstractListModel *messagesListModel();

    UserListModel *usersModel();
private:
    QScopedPointer<MessageListModel> ms_ptr;
    QScopedPointer<UserListModel> us_ptr;
signals:

public slots:


};

}
#endif // CHATMODEL_H
