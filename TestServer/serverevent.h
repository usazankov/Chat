#ifndef SERVEREVENT_H
#define SERVEREVENT_H

#include <QObject>
#include <QVariantMap>

class ServerEvent
{
public:
    explicit ServerEvent();
    enum EventType{
        UndefinedEvent,
        ConnectedUser,
        DisconnectedUser
    };
    QVariantMap data;
    EventType type;
};
Q_DECLARE_METATYPE(ServerEvent)
#endif // SERVEREVENT_H
