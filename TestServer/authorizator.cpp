#include "authorizator.h"

Authorizator::Authorizator(QObject *parent) : QObject(parent)
{

}

bool Authorizator::isValidData(QVariantMap data)
{

}

QString Authorizator::generateToken(QString idUser) const
{
    QString temp("test_token for ");
    return temp + idUser;
}
