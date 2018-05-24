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
