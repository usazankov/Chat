#ifndef CHATREQUEST_H
#define CHATREQUEST_H

#include <QObject>

class ChatRequest : public QObject
{
    Q_OBJECT
public:
    explicit ChatRequest(QObject *parent = nullptr);

signals:

public slots:
};

#endif // CHATREQUEST_H