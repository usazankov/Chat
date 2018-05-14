#ifndef AUTHORIZATOR_H
#define AUTHORIZATOR_H

#include <QObject>
#include <QVariantMap>
#include "server_consts.h"

class Authorizator : public QObject
{
    Q_OBJECT
public:
    explicit Authorizator(QObject *parent = nullptr);
    bool isValidData(QVariantMap data);
    QString generateToken(QString idUser)const;
signals:

public slots:
};

#endif // AUTHORIZATOR_H
