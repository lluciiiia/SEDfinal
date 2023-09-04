#ifndef REQUEST_H
#define REQUEST_H

#include "Account/User.h"
#include "Motorbike.h"
#include "TimeSlot.h"
#include "RequestStatus.h"
using namespace std;



class Motorbike;
class User;

class Request {
private:
    User* requester;   // Change to a pointer to User
    Motorbike* motorbike;  // Change to a pointer to Motorbike
    RequestStatus status;
    TimeSlot timeSlot;
    string username;
    string motobikeID;
    
public:
    Request(User* requester, Motorbike* motorbike, TimeSlot timeSlot)
        : requester(requester), motorbike(motorbike), status(RequestStatus::PENDING), timeSlot(timeSlot) {
    }

    User* getRequester() const {
        return requester;
    }

    Motorbike* getMotorbike() const {
        return motorbike;
    }

    RequestStatus getStatus() const {
        return status;
    }

    void setStatus(RequestStatus status) {
        this->status = status;  // Use 'this->status' to distinguish from the parameter
    }

    TimeSlot getTimeSlot() const {
        return timeSlot;
    }
};




#endif


