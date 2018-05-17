#include "personaldata.h"

chat::PersonalData::PersonalData()
{

}

chat::PersonalData::PersonalData(const chat::PersonalData &data)
{
    m_userName = data.m_userName;
}

QString chat::PersonalData::userName() const
{
    return m_userName;
}

void chat::PersonalData::setUserName(const QString &userName)
{
    if (m_userName == userName)
        return;
    m_userName = userName;
}
