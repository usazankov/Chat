#include "worker.h"

ClientCommand Worker::run(const QByteArray &arr)
{
    QScopedPointer<IParserRequest> parser_ptr(new ParserClientJson(arr));
    return parser_ptr->response();
}

ClientCommand Worker::run(const ServerEvent &event)
{
    QScopedPointer<IParserRequest> parser_ptr(new ParserServerEvent(event));
    return parser_ptr->response();
}
