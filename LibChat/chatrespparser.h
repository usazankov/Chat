#ifndef CHATRESPPARSER_H
#define CHATRESPPARSER_H

#include <QObject>
#include <QVariant>
#include <QJsonObject>
#include <QDate>
#include <QTime>
#include "../Common/common_consts.h"
#include "handlers/chathandler.h"
#include "handlers/userslisthandler.h"
#include "handlers/userhandler.h"
#include <QScopedPointer>

namespace chat {

class ChatRespParser : public QObject
{
    Q_OBJECT
public:
    explicit ChatRespParser(QObject *parent = nullptr);
    explicit ChatRespParser(QJsonObject *doc, QObject *parent = nullptr);
    virtual ~ChatRespParser();
    enum TypeResp{
        Undefined,
        AuthResp,
        ConnectUser,
        DisconnectUser,
        UsersList,
        UsersListResult,
        Message,
        MessageResult
    };
    enum Result{
        UndefinedError,
        ErrorOnServer,
        ErrorParse,
        UnknownCommand,
        UnknownEvent,
        SUCCESS
    };

    //Установить Json-объект
    void setJsonObject(QJsonObject *obj);

    //Начать парсинг Json-объекта
    void parse();

    //Получить данные ответа от сервера
    QVariant data();

    //Получить дату ответа от сервера
    QDate getDataResp()const;

    //Получить время ответа от сервера
    QTime getTimeResp()const;

    //Получить тип ответа от сервера
    TypeResp getTypeResp()const;

    //Получить статус ответа
    Result getResultResp()const;

signals:

public slots:

private:
    bool isCommand(const QJsonObject &obj)const;
    bool isEvent(const QJsonObject &obj)const;
    QString getTypeCommand(const QJsonObject &obj)const;
    QString getTypeEvent(const QJsonObject &obj)const;
    QJsonObject *doc;
    QScopedPointer<ChatHandler> handler;
    TypeResp typeResp;
    QVariant m_data;
    Result res;
};

}
#endif // CHATRESPPARSER_H
