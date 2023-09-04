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
                     double motorbikeRating)
    : model(model),
      motorbikeID(motorbikeID),
      color(color),
      engineSize(engineSize),
      city(city),
      owner(owner),
      transmissionMode(transmissionMode),
      yearMade(yearMade),
      description(description),
      consumingPoints(consumingPoints),
      rentalAmount(rentalAmount),
      minRenterRating(minRenterRating), motorbikeRating(motorbikeRating), ownerUsername(""), renterUsername(""), availability(true)
{
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

void Motorbike::viewRequests()
{
}

bool Motorbike::checkAvailability(bool availability)
{
        return availability;
}

void Motorbike::addCreditPoints(double points)
{
}

string Motorbike::toStringMotorBike()
{
        return model + "," +
               motorbikeID + "," +
               color + "," +
               engineSize + "," +
               transmissionMode + "," +
               to_string(yearMade) + "," +
               description + "," +
               to_string(consumingPoints) + "," +
               to_string(rentalAmount) + "," +
               to_string(minRenterRating) + "," +
               to_string(motorbikeRating) + ",";
}
