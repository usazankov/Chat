#ifndef PERSONALDATA_H
#define PERSONALDATA_H

#include "../Common/libchat_global.h"
#include <QObject>
namespace chat {
class LIBCHATSHARED_EXPORT PersonalData
{

public:
    PersonalData();
    PersonalData(const PersonalData &data);
    PersonalData& operator =(const PersonalData& d)
    {
        m_userName = d.m_userName;
        return *this;
    }
    QString userName() const;
    friend bool operator==(const PersonalData& left, const PersonalData& right)
    {
        return left.m_userName == right.m_userName;
    }
void setUserName(const QString &userName);
private:
    QString m_userName;
};
}
#endif // PERSONALDATA_H
