#ifndef REQUEST_H
#define REQUEST_H

#include "Account/User.h"
#include "Motorbike.h"
#include "TimeSlot.h"
#include "RequestStatus.h"
using namespace std;

class Motorbike;
class Request
{
private:
    string requester;  
    int motorbike;  
    RequestStatus status;
    TimeSlot timeSlot;
    int motobikeID;
    
public:

    Request(string requester, int motorbike, TimeSlot timeSlot, RequestStatus status);


    string getRequester() const;
    string getMotorbike() const;
    void setMotorbikeID(int motorbikeID);
    RequestStatus getStatus() const;
    TimeSlot getTimeSlot() const;
    int getMotorbikeID() const;
    void setRequester(string requester);
    void setMotorbike(string motorbike);
    void setStatus(RequestStatus status);
    void setTimeSlot(TimeSlot timeSlot);

    void showInfo();
};




#endif


