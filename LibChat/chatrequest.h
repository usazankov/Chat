#ifndef CHATREQUEST_H
#define CHATREQUEST_H

#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <string>
#include <QByteArray>
#include <QDataStream>
#include <QCryptographicHash>
#include "libchat_global.h"

class LIBCHATSHARED_EXPORT ChatRequest
{
public:
    explicit ChatRequest();

    ChatRequest(const QString &key, const QString &value);
    ChatRequest& addProperty(const QString &key, const QString &value);
    ChatRequest& addArray(const QString &key, const QStringList &array);
    ChatRequest& addChildObj(const QString &key, const ChatRequest &req);

    ChatRequest& clear();
    QJsonObject toJson()const;
    std::string toString()const;
    QByteArray toRequest()const;
private:
    QJsonObject json;

signals:

public slots:
};

#endif // CHATREQUEST_H
