#ifndef MESSAGELISTMODEL_H
#define MESSAGELISTMODEL_H

#include <QAbstractListModel>
#include <QVector>
#include "message.h"
namespace chat {

class MessageListModel : public QAbstractListModel
{
    Q_OBJECT
    enum Roles{
        FromRole = Qt::UserRole + 1,
        BodyRole,
        DateRole,
        TimeRole
    };
public:
    explicit MessageListModel(QObject *parent = nullptr);

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    QHash<int, QByteArray> roleNames() const override;

    void addMessage(const Message &message);

private:
    QVector<Message> messages;
    QHash<int, QByteArray> roles;
    void initRoleNames();

};
}
#endif // MESSAGELISTMODEL_H
