#include "Borrow.h"

Borrow::Borrow(TimeSlot timeSlot, string username, int motorbikeId, double price, string status)
    : timeSlot(timeSlot), username(username), motorbikeId(motorbikeId), price(price), borrowSta(status)
{
}

Borrow::Borrow()
{
}

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

string Borrow::getBorrowSta()
{
    return borrowSta;
}

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

string Borrow::borrowtoString()
{
    return username + "," +
           to_string(motorbikeId) + "," +
           to_string(price) + "," +
           timeSlot.getStartTime() + "," +
           timeSlot.getEndTime() + "," +
           borrowSta;
}
