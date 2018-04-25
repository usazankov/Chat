#ifndef CHATMODEL_H
#define CHATMODEL_H

#include <QObject>
#include "ichatmodel.h"
namespace chat {

class ChatModel : public IChatModel
{
    Q_OBJECT
public:
    explicit ChatModel(QObject *parent = nullptr);

    // IChatModel interface
    QAbstractListModel *usersListModel();
    QAbstractListModel *messagesListModel();
private:

signals:

public slots:


};

}
#endif // CHATMODEL_H
