#ifndef AUTHORIZATOR_H
#define AUTHORIZATOR_H

#include <QObject>
#include <QVariantMap>
#include "server_consts.h"
#include "Requests/authrequest.h"

class Authorizator : public QObject
{
    Q_OBJECT
public:
    explicit Authorizator(QObject *parent = nullptr);
    bool isValidData(const AuthRequest &data);
    QString generateToken()const;
signals:

public slots:
};

#endif // AUTHORIZATOR_H
