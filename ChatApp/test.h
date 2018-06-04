#ifndef TEST_H
#define TEST_H

#include <QObject>
#include "libchat.h"
#include <QHostAddress>
#include <iostream>
#include <QRandomGenerator>
#include <cstdlib>
#include <QTime>
class Test : public QObject
{
    Q_OBJECT
public:
    explicit Test(QObject *parent = nullptr);

signals:

public slots:
};

#endif // TEST_H
