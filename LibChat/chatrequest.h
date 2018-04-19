#ifndef CHATREQUEST_H
#define CHATREQUEST_H

#include <QObject>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonValue>
#include <string>

class ChatRequest : public QObject
{
    Q_OBJECT
public:
    explicit ChatRequest(QObject *parent = nullptr);
    ChatRequest(const string &key, const string &value, QObject *parent = nullptr);
    ChatRequest& addProperty(const string &key, const string &value);
    ChatRequest& addProperty(const ChatRequest &req);
    ChatRequest& addChild(const string &keyParent, const string &key, const string &value);
    ChatRequest& addChild(const string &keyParent, const ChatRequest &req);
    ChatRequest& clear();
private:
    QJsonObject json;

signals:

public slots:
};

#endif // CHATREQUEST_H
