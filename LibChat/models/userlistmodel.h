#ifndef USERLISTMODEL_H
#define USERLISTMODEL_H

#include <QAbstractListModel>
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

private:
    enum Roles{
        FromRole = Qt::UserRole + 1,
        BodyRole,
        DateRole,
        TimeRole
    };
    QHash<int, QByteArray> roles;
    void initRoleNames();
};
}
#endif // USERLISTMODEL_H
