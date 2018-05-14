#ifndef PARSERREQUEST_H
#define PARSERREQUEST_H

#include <QObject>
#include <QJsonDocument>
#include "server_consts.h"

class ParserRequest : public QObject
{
    Q_OBJECT
public:
    explicit ParserRequest(QObject *parent = nullptr);
    explicit ParserRequest(QJsonDocument *doc, QObject *parent = nullptr);
    server_consts::CommandType typeCommand()const;
    void setJsonDocument(QJsonDocument *doc);
    QVariant data(const QString &key);
private:
    QJsonDocument *doc;
    server_consts::CommandType type;
signals:

public slots:
};

#endif // PARSERREQUEST_H
