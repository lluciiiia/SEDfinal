#include "Request.h"

Request::Request(User *requester, Motorbike *motorbike, TimeSlot timeSlot)
    : requester(requester), motorbike(motorbike), status(RequestStatus::PENDING), timeSlot(timeSlot)
{
}

User *Request::getRequester() const
{
    return requester;
}

Motorbike *Request::getMotorbike() const
{
    return motorbike;
}

RequestStatus Request::getStatus() const
{
    return status;
}

TimeSlot Request::getTimeSlot() const
{
    return timeSlot;
}

void Request::setRequester(User *requester)
{
    this->requester = requester;
}

void Request::setMotorbike(Motorbike *motorbike)
{
    this->motorbike = motorbike;
}

void Request::setStatus(RequestStatus status)
{
    this->status = status;
}

void Request::setTimeSlot(TimeSlot timeslot)
{
    this->timeSlot = timeSlot;
}
