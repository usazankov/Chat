#ifndef CHATRESPPARSER_H
#define CHATRESPPARSER_H

#include <QObject>
#include <QJsonObject>
namespace chat {

class ChatRespParser : public QObject
{
    Q_OBJECT
public:
    explicit ChatRespParser(QJsonObject *obj, QObject *parent = nullptr);

signals:

public slots:

private:
    QJsonObject *ptrObj;
};

}
#endif // CHATRESPPARSER_H
