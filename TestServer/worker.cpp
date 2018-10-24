#include "worker.h"

ClientCommandPtr Worker::executeClientRequest(const QByteArray &arr)
{
    QScopedPointer<IParserRequest> parser_ptr(new ParserClientJson(arr));
    return parser_ptr->response();
}

ClientCommandPtr Worker::executeServerEvent(const ServerEvent &event)
{
    QScopedPointer<IParserRequest> parser_ptr(new ParserServerEvent(event));
    return parser_ptr->response();
}

chat::ChatRequest Worker::createRespToNotAuth(const QString userId)
{
    chat::ChatRequest req;
    if(!userId.isEmpty())
        req.addProperty(chat::USER_ID, userId);
    req.addProperty(chat::CODE_RESP, chat::USER_IS_NOT_REG);
    return req;
}

chat::ChatRequest Worker::createRespToTimeout()
{
    chat::ChatRequest req;
    req.addProperty(chat::CODE_RESP, chat::TIMEOUT_LIMIT_EXCEEDED);
    return req;
}
