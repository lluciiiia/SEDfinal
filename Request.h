#ifndef REQUEST_H
#define REQUEST_H

#include "Account/User.h"
#include "Motorbike.h"
#include "TimeSlot.h"
#include "RequestStatus.h"
using namespace std;

class Motorbike;
class User;

class Request
{
private:
    User* requester;  
    Motorbike* motorbike;  
    RequestStatus status;
    TimeSlot timeSlot;
    string username;
    string motobikeID;
    
public:

    Request(User* requester, Motorbike* motorbike, TimeSlot timeSlot)
        : requester(requester), motorbike(motorbike), status(RequestStatus::PENDING), timeSlot(timeSlot) {
    }

    User* getRequester() const;
    Motorbike* getMotorbike() const;
    RequestStatus getStatus() const;
    TimeSlot getTimeSlot() const;

    void setRequester(User* requester);
    void setMotorbike(Motorbike* motorbike);
    void setStatus(RequestStatus status);
    void setTimeSlot(TimeSlot timeSlot);
};




#endif


