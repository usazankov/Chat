#include "message.h"

chat::Message::Message()
{

}

QString chat::Message::getTextMessage() const
{
    return textMessage;
}

void chat::Message::setTextMessage(const QString &value)
{
    textMessage = value;
}

QDateTime chat::Message::getDateTime() const
{
    return dateTime;
}

void chat::Message::setDateTime(const QDateTime &value)
{
    dateTime = value;
}

QString chat::Message::getUser() const
{
    return user;
}

void chat::Message::setUser(const QString &value)
{
    user = value;
}
