#ifndef CHATREQUEST_H
#define CHATREQUEST_H

#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <string>
#include <vector>
#include <QByteArray>
#include <QDataStream>
#include <QCryptographicHash>
#include "libchat_global.h"

namespace chat {

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

    static ChatRequest fromJsonObject(const QJsonObject &obj);
    static ChatRequest fromVariantMap(const QVariantMap &obj);
    //Преобразовать в низкоуровненвый запрос. Формат запроса:
    //4 байта - размер блока
    //сам блок
    //16 байт - контрольная сумма блока (не включая размер) по md5 (можно потом алгоритм попроще выбрать)
    QByteArray toRequest()const;
    ~ChatRequest(){}
private:
    QJsonObject json;

signals:

public slots:
};

}

#endif // CHATREQUEST_H
