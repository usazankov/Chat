#ifndef PARSERREQUEST_H
#define PARSERREQUEST_H

#include <QObject>
#include <QJsonDocument>
class ParserRequest : public QObject
{
    Q_OBJECT
public:
    explicit ParserRequest(QJsonDocument *doc, QObject *parent = nullptr);
private:
    QJsonDocument *doc;
signals:

public slots:
};

#endif // PARSERREQUEST_H
