#include "Request.h"



Request::Request(string requester, string motorbike, TimeSlot timeSlot, RequestStatus status)
{
    this->requester= requester;
    this->motobikeID= motorbike;
    this->timeSlot= timeSlot;
    this->status= status;
}

string Request::getRequester() const
{
    return requester;
}

string Request::getMotorbike() const
{
    return motobikeID;
}

RequestStatus Request::getStatus() const
{
    return status;
}

TimeSlot Request::getTimeSlot() const
{
    return timeSlot;
}

void Request::setRequester(string requester)
{
    this->requester= requester;
}

void Request::setMotorbike(string motorbike)
{
    this->motobikeID= motorbike;
}




void Request::setStatus(RequestStatus status)
{
    this->status = status;
}

void Request::setTimeSlot(TimeSlot timeslot)
{
    this->timeSlot = timeSlot;
}

void Request::showInfo()
{
    cout << "Requester: " << requester<< "\n";
    cout << "Motorbike: " << motobikeID << "\n";
    cout << "Request Status: " << __STRINGIFY(status) << "\n";
    //timeSlot.showInfo();
};
