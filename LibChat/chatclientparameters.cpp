#include "chatclientparameters.h"

QHostAddress chat::ChatClientParameters::getAdress() const
{
    return adress;
}

void chat::ChatClientParameters::setAdress(const QHostAddress &value)
{
    adress = value;
}

quint16 chat::ChatClientParameters::getPort() const
{
    return port;
}

void chat::ChatClientParameters::setPort(const quint16 &value)
{
    port = value;
}

chat::ChatClientParameters::ChatClientParameters(QObject *parent) : QObject(parent)
{
    
}

chat::ChatClientParameters::~ChatClientParameters()
{
    
}

chat::PersonalData chat::ChatClientParameters::personalData() const
{
    return m_personalData;
}

void chat::ChatClientParameters::setPersonalData(chat::PersonalData personalData)
{
    if (m_personalData == personalData)
        return;

    m_personalData = personalData;
    emit personalDataChanged(m_personalData);
}
