#include "Borrow.h"

Borrow::Borrow(TimeSlot timeSlot, string username, int motorbikeId, double price, string status)
    : timeSlot(timeSlot), username(username), motorbikeId(motorbikeId), price(price), borrowSta(status)
{
}

Borrow::Borrow()
{
}

// Getters
TimeSlot Borrow::getTimeSlot() const
{
    return timeSlot;
}

string Borrow::getUsername() const
{
    return username;
}

int Borrow::getMotorbikeID() const
{
    return motorbikeId;
}

double Borrow::getPrice() const
{
    return price;
}

TimeSlot &Borrow::getTimeSlot()
{
    return timeSlot;
}

string Borrow::getBorrowSta()
{
    return borrowSta;
}

// Setters
void Borrow::setTimeSlot(TimeSlot timeSlot)
{
    timeSlot = timeSlot;
}

void Borrow::setUsername(string username)
{
    username = username;
}

void Borrow::setMotorbikeId(string motorbikeId)
{
    motorbikeId = motorbikeId;
}

void Borrow::setPrice(double price)
{
    price = price;
}

void Borrow::setBorrowStatus(string status)
{
    this->borrowSta = status;
}

// Method to convert borrow information to string
string Borrow::borrowtoString()
{
    return username + "," +
           to_string(motorbikeId) + "," +
           to_string(price) + "," +
           timeSlot.getStartTime() + "," +
           timeSlot.getEndTime() + "," +
           borrowSta;
}
