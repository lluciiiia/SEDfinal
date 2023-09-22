#include "Request.h"

Request::Request(){}
Request::Request(string requester, int motorbikeID, TimeSlot timeSlot, RequestStatus status)
{
    this->requester = requester;
    this->motorbikeID = motorbikeID;
    this->timeSlot = timeSlot;
    this->status = status;
}

// Getters
string Request::getRequester() const
{
    return requester;
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

// Setters
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

// Method to convert the request information to string
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

// Method to display the information of the request
void Request::showInfo()
{
    cout << "Requester: " << requester << "\n";
    cout << "Motorbike: " << motorbikeID << "\n";
    cout << "Request Status: " << __STRINGIFY(status) << "\n";
};

// == Operator Method
bool Request::operator==(const Request &other) const
{
    return this->requester == other.requester &&
           this->status == other.status &&
           this->timeSlot == other.timeSlot &&
           this->motorbikeID == other.motorbikeID;
}
