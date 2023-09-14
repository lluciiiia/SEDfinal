#ifndef BORROW_H
#define BORROW_H

#include <string>
#include "TimeSlot.h"

using namespace std;

class Borrow {
private:
    TimeSlot timeSlot;
    string username;
    string motorbikeId;
    double price;

public:
    Borrow(TimeSlot timeSlot, string username, string motorbikeId, double price);
    
    //getters
    TimeSlot getTimeSlot() const;
    string getUsername() const;
    string getMotorbikeID() const;
    double getPrice() const;

    //setters
    void setTimeSlot(TimeSlot timeSlot);
    void setUsername(string username);
    void setMotorbikeId(string motorbikeId);
    void setPrice(double price);
    string toString() const;
};

#endif

