#ifndef ROOM_H
#define ROOM_H

#include <QObject>

class Room : public QObject
{
    Q_OBJECT
public:
    explicit Room(QObject *parent = nullptr);

signals:

public slots:
};

#endif // ROOM_H