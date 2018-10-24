#include "requestfilter.h"

int RequestFilter::getExceededTick() const
{
    return exceededTick;
}

void RequestFilter::setExceededTick(int ms)
{
    exceededTick = ms;
}

int RequestFilter::getExceededLimitFailReq() const
{
    return exceededLimitFailReq;
}

void RequestFilter::setExceededLimitFailReq(int count)
{
    exceededLimitFailReq = count;
}

RequestFilter::RequestFilter()
{
    currentTick = 0;
    currentFail = 0;
}

RequestFilter::CheckResult RequestFilter::check()
{
    qDebug() << "Current range time: " << QDateTime::currentMSecsSinceEpoch() - currentTick;
    qDebug() << "Exceeded Time: " << exceededTick;
    qDebug() << "Current Fail: " << currentFail;
    qDebug() << "Exceeded Fail: " << exceededLimitFailReq;
    if((QDateTime::currentMSecsSinceEpoch() - currentTick) >= exceededTick){
        currentFail = 0;
        return CheckResult::OK;
    }else if(currentFail >= exceededLimitFailReq){
        return CheckResult::NEED_DISCONNECT;
    }else{
        currentFail++;
        return CheckResult::SEND_FAIL;
    }

}

void RequestFilter::updateStatus(RequestFilter::Event event)
{
    currentTick = QDateTime::currentMSecsSinceEpoch();
}
