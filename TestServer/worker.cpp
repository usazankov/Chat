#include "worker.h"

ClientCommand Worker::executeClientRequest(const QByteArray &arr)
{
    QScopedPointer<IParserRequest> parser_ptr(new ParserClientJson(arr));
    return parser_ptr->response();
}

ClientCommand Worker::executeServerEvent(const ServerEvent &event)
{
    QScopedPointer<IParserRequest> parser_ptr(new ParserServerEvent(event));
    return parser_ptr->response();
}
