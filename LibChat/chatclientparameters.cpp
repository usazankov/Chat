#include "chatclientparameters.h"

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
