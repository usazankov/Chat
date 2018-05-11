#ifndef AUTHORIZATOR_H
#define AUTHORIZATOR_H

#include <QObject>
#include <QVariantMap>

namespace server_consts {
    static const QString ID_USER = "id_user";
}
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
