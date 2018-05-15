#ifndef PARSERREQUEST_H
#define PARSERREQUEST_H

#include <QObject>
#include <QJsonDocument>
#include "QJsonObject"
#include <QVariantMap>
#include "server_consts.h"
#include "common_consts.h"

class ParserRequest : public QObject
{
    Q_OBJECT
public:
    explicit ParserRequest(QObject *parent = nullptr);
    explicit ParserRequest(QJsonDocument *doc, QObject *parent = nullptr);
    void process();
    server_consts::CommandType typeCommand()const;
    void setJsonDocument(QJsonDocument *doc);
    QVariant data(const QString &key);
private:
    QJsonDocument *doc;
    server_consts::CommandType type;
    QVariantMap map;
signals:

public slots:
};

#endif // PARSERREQUEST_H
