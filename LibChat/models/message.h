#ifndef MESSAGE_H
#define MESSAGE_H

#include <QObject>
#include <QDateTime>
namespace chat {

class Message
{
public:
    explicit Message();
    QString getTextMessage() const;
    void setTextMessage(const QString &value);

    QDateTime getDateTime() const;
    void setDateTime(const QDateTime &value);

    QString getUser() const;
    void setUser(const QString &value);

private:
    QString textMessage;
    QDateTime dateTime;
    QString user;
signals:

public slots:
};
}
Q_DECLARE_METATYPE(chat::Message)
#endif // MESSAGE_H
