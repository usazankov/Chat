#ifndef CHATRESPONSE_H
#define CHATRESPONSE_H

#include <QObject>

class ChatResponse : public QObject
{
    Q_OBJECT
public:
    explicit ChatResponse(QObject *parent = nullptr);

signals:

public slots:
};

#endif // CHATRESPONSE_H