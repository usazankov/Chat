#ifndef CHATCLIENT_H
#define CHATCLIENT_H

#include <QObject>
namespace chat {

class ChatClient : public QObject
{
    Q_OBJECT
public:
    explicit ChatClient(QObject *parent = nullptr);

signals:

public slots:
};

}
#endif // CHATCLIENT_H
