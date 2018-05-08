#ifndef LIBCHAT_H
#define LIBCHAT_H

#include "libchat_global.h"
#include "chatclient.h"

namespace chat {
class LIBCHATSHARED_EXPORT LibChat
{
private:
    LibChat();
    LibChat(const LibChat& root) = delete;
    LibChat& operator=(const LibChat&) = delete;

    ChatClient *client;
public:
    static LibChat& instance()
    {
        static LibChat theSingleInstance;
        return theSingleInstance;
    }
    //Model
    Q_INVOKABLE IChatModel* model();

    //Controller
    Q_INVOKABLE void connectToChat(const QHostAddress &address, quint16 port);
    Q_INVOKABLE void disconnectFromChat();
    Q_INVOKABLE void getUsers();
    Q_INVOKABLE void sendMessage(const QString &message);
    Q_INVOKABLE void deleteChat();
    Q_INVOKABLE ChatClient* getChatClient();
};
}
#endif // LIBCHAT_H
