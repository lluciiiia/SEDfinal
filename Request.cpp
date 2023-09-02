#include "Request.h"

Request::Request(string username, string motorbikeId, RequestStatus status, TimeSlot timeSlot)
{
    this->username = username;
    this->motobikeID = motorbikeId;
    this->status = status;
    this->timeSlot = timeSlot;
}

string Request::getUsername()
{
    return username;
}

string Request::getMotorbikeId()
{
    return motobikeID;
}

