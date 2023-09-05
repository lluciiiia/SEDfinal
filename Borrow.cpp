#include "Borrow.h"

Borrow::Borrow(TimeSlot timeSlot, string username, string motorbikeId, double price)
    : timeSlot(timeSlot), username(username), motorbikeId(motorbikeId), price(price) {
}

TimeSlot Borrow::getTimeSlot() const {
    return timeSlot;
}

string Borrow::getUsername() const {
    return username;
}

string Borrow::getMotorbikeID() const {
    return motorbikeId;
}

double Borrow::getPrice() const {
    return price;
}

void Borrow::setTimeSlot(TimeSlot timeSlot) {
    timeSlot = timeSlot;
}

void Borrow::setUsername(string username) {
    username = username;
}

void Borrow::setMotorbikeId(string motorbikeId) {
    motorbikeId = motorbikeId;
}

void Borrow::setPrice(double price) {
    price = price;
}
