#ifndef ICHATMODEL_H
#define ICHATMODEL_H

#include <QObject>
#include <QAbstractListModel>

class IChatModel : public QObject
{
    Q_OBJECT
public:
    explicit IChatModel(QObject *parent = nullptr);

    //Получить список пользователей
    virtual QAbstractListModel* usersListModel() = 0;
    //Получить список сообщений
    virtual QAbstractListModel* messagesListModel() = 0;
signals:

public slots:
};

#endif // ICHATMODEL_H
