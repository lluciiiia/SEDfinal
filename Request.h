#ifndef REQUEST_H
#define REQUEST_H

<<<<<<< Updated upstream

class Request{

=======
#include "Account/User.h"
#include "Motorbike.h"
#include "TimeSlot.h"
#include "RequestStatus.h"
using namespace std;
class Request {
private:
    
    RequestStatus status;
    TimeSlot timeSlot;
    string username;
    string motobikeID;
    
public:
    Request (string username, string motorbikeId, RequestStatus status, TimeSlot timeSlot);
    string getUsername();
    string getMotorbikeId();
>>>>>>> Stashed changes
};




#endif


