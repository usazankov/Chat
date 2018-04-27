#include "chatrequest.h"

chat::ChatRequest::ChatRequest()
{

}

chat::ChatRequest::ChatRequest(const QString &key, const QString &value)
{
    json.insert(key, value);
}

chat::ChatRequest &chat::ChatRequest::addProperty(const QString &key, const QString &value)
{
    json.insert(key, value);
    return *this;
}

/*
ChatRequest &ChatRequest::addProperty(const std::string &key, const std::string &value)
{
    json.insert(QString::fromStdString(key), QString::fromStdString(value));
    return *this;
}

ChatRequest::ChatRequest(const std::string &key, const std::string &value)
{
    json.insert(QString::fromStdString(key), QString::fromStdString(value));
}

ChatRequest &ChatRequest::addArray(const std::string &key, const std::vector<std::string> &array)
{
    QJsonArray arr;
    for(auto iter : array){
        arr.push_back(QString::fromStdString(iter));
    }
    json.insert(QString::fromStdString(key), arr);
    return *this;
}

ChatRequest &ChatRequest::addChildObj(const std::string &key, const ChatRequest &req)
{
    json.insert(QString::fromStdString(key), req.toJson());
    return *this;
}
*/

chat::ChatRequest &chat::ChatRequest::addArray(const QString &key, const QStringList &array)
{
    QJsonArray arr = QJsonArray::fromStringList(array);
    json.insert(key, arr);
    return *this;
}

chat::ChatRequest &chat::ChatRequest::addChildObj(const QString &key, const ChatRequest &req)
{
    json.insert(key, req.toJson());
    return *this;
}

chat::ChatRequest &chat::ChatRequest::clear()
{
    for(auto iter = json.begin(); iter != json.end(); iter++){
        json.erase(iter);
    }
    return *this;
}

QJsonObject chat::ChatRequest::toJson() const
{
    return json;
}

std::string chat::ChatRequest::toString() const
{
    QJsonDocument doc(json);
    QString strJson(doc.toJson(QJsonDocument::Compact));
    return strJson.toStdString();
}

QByteArray chat::ChatRequest::toRequest() const
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
