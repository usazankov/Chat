#ifndef TESTCLIENT_H
#define TESTCLIENT_H

#include <QObject>
#include "libchat.h"
#include <QHostAddress>
#include <iostream>

class TestClient : public QObject
{
    Q_OBJECT
public:
    explicit TestClient(QObject *parent = nullptr);
    void print(const QString &str);
signals:

public slots:
    printError(chat::IChatNetworkManager::ErrorNetwork err);
};

#endif // TESTCLIENT_H
