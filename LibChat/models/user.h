#ifndef USER_H
#define USER_H

#include <QObject>
#include <QList>
#include <QSharedPointer>
namespace chat {

class User
{
public:
    explicit User();
    User(const User &user);
    User& operator =(const User &user);
    bool operator ==(const User &right);
QString userId;

};
typedef QSharedPointer<QList<User>> UsersListPtr;
}
Q_DECLARE_METATYPE(chat::User)
Q_DECLARE_METATYPE(chat::UsersListPtr)
#endif // USER_H
