#include "Request.h"

Request::Request()
{
}

Request::Request(string requester, int motorbikeID, TimeSlot timeSlot, RequestStatus status)
{
    this->requester = requester;
    this->motorbikeID = motorbikeID;
    this->timeSlot = timeSlot;
    this->status = status;
}

Request::Request(string requester, int motorbikeID, TimeSlot timeSlot, RequestStatus status, Motorbike bike)
{
    this->requester = requester;
    this->motorbikeID = motorbikeID;
    this->timeSlot = timeSlot;
    this->status = status;
    *this->bike = bike;
}

string Request::getRequester() const
{
    return requester;
}
Motorbike Request::getMotorbike()
{
    return *bike;
}
int Request::getMotorbikeID() const
{
    return motorbikeID;
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
    this->requester = requester;
}

void Request::setMotorbikeID(int motorbikeID)
{
    this->motorbikeID = motorbikeID;
}

void Request::setStatus(RequestStatus status)
{
    this->status = status;
}

void Request::setTimeSlot(TimeSlot timeslot)
{
    this->timeSlot = timeSlot;
}

string Request::requestToString()
{
    string requestSta;
    switch (this->status)
    {
    case RequestStatus::PENDING:
        requestSta = "PENDING";
        break;
    case RequestStatus::ACCEPTED:
        requestSta = "ACCEPTED";
        break;
    case RequestStatus::REJECTED:
        requestSta = "REJECTED";
        break;
    default:
        requestSta = "UNKNOWN";
        break;
    }

    return this->requester + "," +
           to_string(this->motorbikeID) + "," +
           requestSta + "," +
           timeSlot.getStartTime() + "," +
           timeSlot.getEndTime();
}

void Request::showInfo()
{
    cout << "Requester: " << requester << "\n";
    cout << "Motorbike: " << motorbikeID << "\n";
    cout << "Request Status: " << __STRINGIFY(status) << "\n";
    // timeSlot.showInfo();
};
