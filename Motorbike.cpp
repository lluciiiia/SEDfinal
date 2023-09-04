#include "Motorbike.h"

<<<<<<< Updated upstream
Motorbike::Motorbike(std::string &model, std::string &motorbikeID, std::string &color, std::string &engineSize, City &city, std::string &transmissionMode, int yearMade, std::string &description, double consumingPoints, double rentalAmount, double minRenterRating, double motorbikeRating)
=======
using namespace std;

Motorbike::Motorbike(string model,
                     string motorbikeID,
                     string color,
                     string engineSize,
                     City city,
                     string transmissionMode,
                     int yearMade,
                     string description,
                     double consumingPoints,
                     double rentalAmount,
                     double minRenterRating,
                     double motorbikeRating,
                     string owner,
                     string renter)
>>>>>>> Stashed changes
{
        this->model= model;
        this-> motorbikeID= motorbikeID;
        this-> color= color;
        this-> engineSize=engineSize;
        this-> city= city;
        this-> transmissionMode = transmissionMode;
        this->yearMade = yearMade;
        this-> description= description;
        this-> consumingPoints= consumingPoints;
        this-> rentalAmount= rentalAmount;
        this-> minRenterRating=minRenterRating;
        this-> motorbikeRating= motorbikeRating;
        this-> ownerUsername= owner;
        this-> renterUsername= renter;
}

<<<<<<< Updated upstream
void Motorbike::addRequest(const Request &request)
{
}
=======
// TimeSlot Motorbike::getTimeSlot()
// {
//         return
// }


string Motorbike::getMotorbikeId()
{
        return motorbikeID;
}

double Motorbike::getConsumingPoints()
{
        return consumingPoints;
}

void Motorbike::setAvailability(bool availability)
{
        this->availability = availability;
}


void Motorbike::setMotorbikeID(string motorbikeID)
{
        this->motorbikeID = motorbikeID;
}

void Motorbike::setConsumingPoints(double consumingPoints)
{
        this->consumingPoints = consumingPoints;
}


>>>>>>> Stashed changes

void Motorbike::viewRequest(const Request &request)
{
}

void Motorbike::checkAvailability(const TimeSlot &timeSlot)
{
}

void Motorbike::reserveTimeSlot(const TimeSlot &timeSlot)
{
}

<<<<<<< Updated upstream
void Motorbike::addCreditPoints()
{
}
string Motorbike:: toStringMotorBike(){
        return model+","+
                motorbikeID+","+
                color+","+
                engineSize+","+
                transmissionMode+","+
                to_string(yearMade)+","+
                description+","+
                to_string(consumingPoints)+","+
                to_string(rentalAmount)+","+
                to_string(minRenterRating)+","+
                to_string(motorbikeRating)+",";
    }
=======
Motorbike::Motorbike(std::string &model, std::string &motorbikeID, std::string &color, std::string &engineSize, City &city, std::string &transmissionMode, int yearMade, std::string &description, double consumingPoints, double rentalAmount, double minRenterRating, double motorbikeRating, bool availability)
{
        this->model= model;
        this-> motorbikeID = motorbikeID;
        this-> color =color;
        this-> engineSize = engineSize;
        this->city= city;
        this->transmissionMode = transmissionMode;
        this-> yearMade= yearMade;
        this->description= description;
        this->consumingPoints= consumingPoints;
        this-> rentalAmount= rentalAmount;
        this-> minRenterRating= minRenterRating;
        this->motorbikeRating= motorbikeRating;
        this-> availability= availability;
}
>>>>>>> Stashed changes
