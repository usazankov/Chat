#ifndef REQUESTFILTER_H
#define REQUESTFILTER_H

#include <QDateTime>
#include <QDebug>

class RequestFilter
{
private:
    qint64 currentTick;
    int currentFail;
    int exceededTick;
    int exceededLimitFailReq;
public:
    enum CheckResult{
        OK,
        SEND_FAIL,
        NEED_DISCONNECT
    };

    enum Event{
        Request
    };

    RequestFilter();
    CheckResult check();
    void updateStatus(Event event);

    int getExceededTick() const;
    void setExceededTick(int ms);
    int getExceededLimitFailReq() const;
    void setExceededLimitFailReq(int count);
};

#endif // REQUESTFILTER_H
