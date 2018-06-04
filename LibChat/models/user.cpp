#include "user.h"

chat::User::User()
{
    userId = QString();
}

chat::User::User(const chat::User &user)
{
    userId = user.userId;
}

chat::User &chat::User::operator =(const chat::User &user)
{
    userId = user.userId;
    return *this;
}

bool chat::User::operator ==(const chat::User &right)
{
    return userId == right.userId;
}
