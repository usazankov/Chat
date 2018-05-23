#include "chatrequest.h"

chat::ChatRequest::ChatRequest()
{

}

chat::ChatRequest::ChatRequest(const QString &key, const QString &value)
{
    json.insert(key, value);
}

chat::ChatRequest::ChatRequest(const QJsonObject &obj)
{
    json = obj;
}

chat::ChatRequest &chat::ChatRequest::addProperty(const QString &key, const QString &value)
{
    json.insert(key, value);
    return *this;
}

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
    /*for(auto iter = json.begin(); iter != json.end(); iter++){
        json.erase(iter);
    }*/
    json = QJsonObject();
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
    QByteArray block = doc.toJson();
    //QByteArray block_hash = QCryptographicHash::hash(block, QCryptographicHash::Md5);
    QDataStream out(&res, QIODevice::WriteOnly);
    out << block;
    //out << block_hash;
    return res;
}
