#include "chatrequest.h"

ChatRequest::ChatRequest()
{

}

ChatRequest::ChatRequest(const QString &key, const QString &value)
{
    json.insert(key, value);
}

ChatRequest &ChatRequest::addProperty(const QString &key, const QString &value)
{
    json.insert(key, value);
    return *this;
}

ChatRequest &ChatRequest::addArray(const QString &key, const QStringList &array)
{
    QJsonArray arr;
    arr.fromStringList(array);
    json.insert(key, arr);
    return *this;
}

ChatRequest &ChatRequest::addChildObj(const QString &key, const ChatRequest &req)
{
    json.insert(key, req.toJson());
    return *this;
}

ChatRequest &ChatRequest::clear()
{
    for(auto iter = json.begin(); iter != json.end(); iter++){
        json.erase(iter);
    }
    return *this;
}

QJsonObject ChatRequest::toJson() const
{
    return json;
}

std::string ChatRequest::toString() const
{
    QJsonDocument doc(json);
    QString strJson(doc.toJson(QJsonDocument::Compact));
    return strJson.toStdString();
}

QByteArray ChatRequest::toRequest() const
{
    QByteArray res;
    QJsonDocument doc(json);
    QByteArray block = doc.toBinaryData();
    QByteArray block_hash = QCryptographicHash::hash(block, QCryptographicHash::Md5);
    QDataStream out(&res, QIODevice::WriteOnly);
    out << block.size();
    out << block;
    out << block_hash;
    return res;
}
