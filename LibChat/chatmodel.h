#ifndef CHATMODEL_H
#define CHATMODEL_H

#include <QObject>
#include "ichatmodel.h"

class ChatModel : public IChatModel
{
    Q_OBJECT
public:
    explicit ChatModel(QObject *parent = nullptr);

signals:

public slots:
};

#endif // CHATMODEL_H
