
#include "Motorbike.h"

Motorbike::Motorbike(std::string &model, std::string &motorbikeID, std::string &color, std::string &engineSize, City &city, std::string &transmissionMode, int yearMade, std::string &description, double consumingPoints, double rentalAmount, double minRenterRating, double motorbikeRating)
{

}


void Motorbike::addRequest(const Request &request)
{
}

void Motorbike::viewRequest(const Request &request)
{
}

void Motorbike::checkAvailability(const TimeSlot &timeSlot)
{
}

void Motorbike::reserveTimeSlot(const TimeSlot &timeSlot)
{
}

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