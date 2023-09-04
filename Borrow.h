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
    Borrow(TimeSlot timeSlot, string username, string motorbikeId, double price)
        : timeSlot(timeSlot), username(username), motorbikeId(motorbikeId), price(price) {}
    
    //getters
    TimeSlot getTimeSlot() const {
        return timeSlot;
    }

    string getUsername() const {
        return username;
    }

    string getMotorbikeID() const {
        return motorbikeId;
    }

    double getPrice() const {
        return price;
    }

    //setters
    void setTimeSlot(TimeSlot timeSlot) {
        timeSlot = timeSlot;
    }

    void setUsername(string username) {
        username = username;
    }

    void setMotorbikeId(string motorbikeId) {
        motorbikeId = motorbikeId;
    }

    void setPrice(double price) {
        price = price;
    }
};

#endif

