#ifndef USERLISTMODEL_H
#define USERLISTMODEL_H

#include <QAbstractListModel>
#include "user.h"
namespace chat {
class UserListModel : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit UserListModel(QObject *parent = nullptr);

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    QHash<int, QByteArray> roleNames() const override;

    void addUser(const User &user);

    void removeUser(const User &user);
    void removeUser(const QString &userId);

    void setUsersList(const QList<User> &list);

private:
    enum Roles{
        UserIDRole = Qt::UserRole + 1,
    };
    QHash<int, QByteArray> roles;
    QList<User> users;
    void initRoleNames();
};
}
#endif // USERLISTMODEL_H
