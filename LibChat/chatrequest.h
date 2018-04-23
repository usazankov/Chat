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

    //STL compatibility
    /*ChatRequest(const std::string &key, const std::string &value);
    ChatRequest& addProperty(const std::string &key, const std::string &value);
    ChatRequest& addArray(const std::string &key, const std::vector<std::string> &array);
    ChatRequest& addChildObj(const std::string &key, const ChatRequest &req);*/

    ChatRequest& clear();
    QJsonObject toJson()const;
    std::string toString()const;

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
