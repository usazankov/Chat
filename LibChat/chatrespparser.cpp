#include "chatrespparser.h"

chat::ChatRespParser::ChatRespParser(QJsonObject *obj, QObject *parent) : QObject(parent)
{
    ptrObj = obj;
}
