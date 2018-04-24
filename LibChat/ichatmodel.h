#ifndef ICHATMODEL_H
#define ICHATMODEL_H

#include <QObject>

class IChatModel : public QObject
{
    Q_OBJECT
public:
    explicit IChatModel(QObject *parent = nullptr);

signals:

public slots:
};

#endif // ICHATMODEL_H