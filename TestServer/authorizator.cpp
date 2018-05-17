#include "authorizator.h"

Authorizator::Authorizator(QObject *parent) : QObject(parent)
{

}

bool Authorizator::isValidData(const AuthRequest &data)
{
    return true;
}

QString Authorizator::generateToken() const
{
    QString temp("test_token for ");
    return temp;
}
