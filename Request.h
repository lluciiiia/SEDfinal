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
    RequestStatus status;
    TimeSlot timeSlot;
    int motorbikeID;
    
    
public:
    Request();
    Request(string requester, int motorbikeID, TimeSlot timeSlot, RequestStatus status);
    string getRequester() const;
    void setMotorbikeID(int motorbikeID);
    RequestStatus getStatus() const;
    TimeSlot getTimeSlot() const;
    int getMotorbikeID() const;
    void setRequester(string requester);
    //void setMotorbike(string motorbike);
    void setStatus(RequestStatus status);
    void setTimeSlot(TimeSlot timeSlot);
    string requestToString();
    void showInfo();
};




#endif


