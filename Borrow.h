#ifndef BORROW_H
#define BORROW_H

#include <string>
#include "TimeSlot.h"

using namespace std;

class Borrow
{
private:
    TimeSlot timeSlot;
    string username;
    int motorbikeId;
    double price;
    string borrowSta;

public:
    Borrow(TimeSlot timeSlot, string username, int motorbikeId, double price, string status);
    Borrow();
    // getters
    TimeSlot getTimeSlot() const;
    string getUsername() const;
    int getMotorbikeID() const;
    double getPrice() const;
    string getBorrowSta();
    // setters
    void setTimeSlot(TimeSlot timeSlot);
    void setUsername(string username);
    void setMotorbikeId(string motorbikeId);
    void setPrice(double price);
    void setBorrowStatus(string status);
    string borrowtoString();
};

#endif
