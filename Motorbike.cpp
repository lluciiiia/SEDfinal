#include "Motorbike.h"
#include "Account/User.h"

using namespace std;

Motorbike::Motorbike(string model,
                     string motorbikeID,
                     string color,
                     string engineSize,
                     City city,
                     User owner,
                     string transmissionMode,
                     int yearMade,
                     string description,
                     double consumingPoints,
                     double rentalAmount,
                     double minRenterRating,
                     double motorbikeRating,
                     bool availability)

{
        this->model = model;
        this->motorbikeID = motorbikeID;
        this->color = color;
        this->engineSize = engineSize;
        this->city = city;
        this->transmissionMode = transmissionMode;
        this->yearMade = yearMade;
        this->description = description;
        this->consumingPoints = consumingPoints;
        this->rentalAmount = rentalAmount;
        this->minRenterRating = minRenterRating;
        this->motorbikeRating = motorbikeRating;
        this->availability = availability;
        // this-> ownerUsername= owner;
        // this-> renterUsername= renter;
}

// TimeSlot Motorbike::getTimeSlot()
// {
//         return
// }

User Motorbike::getOwner()
{
        return owner;
}

string Motorbike::getMotorbikeId()
{
        return motorbikeID;
}

double Motorbike::getConsumingPoints()
{
        return consumingPoints;
}

bool Motorbike::getAvailability()
{
        return availability;
}

void Motorbike::setAvailability(bool availability)
{
        this->availability = availability;
}

void Motorbike::setOwner(User owner)
{
        this->owner = owner;
}

void Motorbike::setMotorbikeID(string motorbikeID)
{
        this->motorbikeID = motorbikeID;
}

void Motorbike::setConsumingPoints(double consumingPoints)
{
        this->consumingPoints = consumingPoints;
}

void Motorbike::addRequest(const Request &request)
{
        requests.push_back(request);
}

void Motorbike::viewRequest(const Request &request)
{
}

void Motorbike::reserveTimeSlot(const TimeSlot &timeSlot)
{
}