#include "Motorbike.h"


using namespace std;


// TimeSlot Motorbike::getTimeSlot()
// {
//         return
// }

Motorbike::Motorbike(string model, int motorbikeID, string color, string engineSize, City city, string owner, string transmissionMode, int yearMade, string description, double consumingPoints, double rentalAmount, double minRenterRating, double motorbikeRating)
{
        this->model= model;
        this->motorbikeID= motorbikeID;
        this->color= color;
        this->engineSize=engineSize;
        this->city=city;
        this->owner= owner;
        this->transmissionMode= transmissionMode;
        this->yearMade=yearMade;
        this->description=description;
        this->consumingPoints=consumingPoints;
        this->rentalAmount=rentalAmount;
        this->minRenterRating=minRenterRating;
        this->motorbikeRating=motorbikeRating;
}

Motorbike::Motorbike(string model, int motorbikeID, string color, string engineSize, City city, string owner, string transmissionMode, int yearMade, string description, double consumingPoints, double rentalAmount)
{
        this->model = model;
        this->motorbikeID=motorbikeID;
        this->color=color;
        this->engineSize= engineSize;
        this->city= city;
        this->owner= owner;
        this-> transmissionMode = transmissionMode;
        this->yearMade = yearMade;
        this->description=description;
        this->consumingPoints= consumingPoints;
        this->rentalAmount;
}

string Motorbike::getOwner()

{
        return owner;
}

int Motorbike::getMotorbikeId()
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

void Motorbike::setOwner(string owner)
{
        this->owner = owner;
}


void Motorbike::setMotorbikeID(int motorbikeID)

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
{       int i = 1;
        cout << "View requests of the motorbike " << motorbikeID << "\n";
        for (Request request : requests) {
                cout << "Request " << i << ":\n";
                request.showInfo();
        }
}       

bool Motorbike::checkAvailability(bool availability)
{
        return availability;
}

// void Motorbike::addCreditPoints(double points)
// {

// }

// string Motorbike::toStringMotorBike()
// {
//         return model + "," +
//                motorbikeID + "," +
//                color + "," +
//                engineSize + "," +
//                transmissionMode + "," +
//                to_string(yearMade) + "," +
//                description + "," +
//                to_string(consumingPoints) + "," +
//                to_string(rentalAmount) + "," +
//                to_string(minRenterRating) + "," +
//                to_string(motorbikeRating) + ",";
// }

