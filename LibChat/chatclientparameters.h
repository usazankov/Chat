#ifndef CHATCLIENTPARAMETERS_H
#define CHATCLIENTPARAMETERS_H
#include "personaldata.h"
#include <QHostAddress>

namespace chat {
class ChatClientParameters : public QObject
{
    Q_PROPERTY(PersonalData personalData READ personalData WRITE setPersonalData NOTIFY personalDataChanged)
    Q_OBJECT

private:
    PersonalData m_personalData;
    QHostAddress adress;
    quint16 port;
public:
    explicit ChatClientParameters(QObject *parent = 0);

    ~ChatClientParameters();

    PersonalData personalData() const;

    QHostAddress getAdress() const;
    void setAdress(const QHostAddress &value);

    quint16 getPort() const;
    void setPort(const quint16 &value);

public slots:
    void setPersonalData(PersonalData personalData);

signals:
    void personalDataChanged(PersonalData personalData);

};
}
#endif // CHATCLIENTPARAMETERS_H
