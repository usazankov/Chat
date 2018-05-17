#ifndef CHATCLIENTPARAMETERS_H
#define CHATCLIENTPARAMETERS_H
#include "personaldata.h"

namespace chat {
class ChatClientParameters : public QObject
{
    Q_PROPERTY(PersonalData personalData READ personalData WRITE setPersonalData NOTIFY personalDataChanged)
    Q_OBJECT

private:
    PersonalData m_personalData;

public:
    explicit ChatClientParameters(QObject *parent = 0);

    ~ChatClientParameters();

    PersonalData personalData() const;

public slots:
    void setPersonalData(PersonalData personalData);

signals:
    void personalDataChanged(PersonalData personalData);

};
}
#endif // CHATCLIENTPARAMETERS_H
