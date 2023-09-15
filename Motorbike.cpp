#include "Motorbike.h"

using namespace std;

Motorbike::Motorbike(string model, int motorbikeID, string color, string engineSize, City city, string owner, string transmissionMode, int yearMade, string description, double consumingPoints, double rentalAmount, double minRenterRating)
{
        this->model = model;
        this->motorbikeID = motorbikeID;
        this->color = color;
        this->engineSize = engineSize;
        this->city = city;
        this->owner = owner;
        this->transmissionMode = transmissionMode;
        this->yearMade = yearMade;
        this->description = description;
        this->consumingPoints = consumingPoints;
        this->rentalAmount = rentalAmount;
        this->minRenterRating = minRenterRating;
}

Motorbike::Motorbike(string model, int motorbikeID, string color, string engineSize, City city, string owner, string transmissionMode, int yearMade, string description, double consumingPoints, double rentalAmount, double minRenterRating, bool avai)
{
        this->model = model;
        this->motorbikeID = motorbikeID;
        this->color = color;
        this->engineSize = engineSize;
        this->city = city;
        this->owner = owner;
        this->transmissionMode = transmissionMode;
        this->yearMade = yearMade;
        this->description = description;
        this->consumingPoints = consumingPoints;
        this->rentalAmount = rentalAmount;
        this->minRenterRating = minRenterRating;
        this->availability= avai;
}

string Motorbike::getOwner()

{
        return owner;
}

City Motorbike::getCity()
{
        return city;
}

int Motorbike::getYear()
{
        return this->yearMade;
}

string Motorbike::getDes()
{
        return this->description;
}

double Motorbike::getRating()
{
        if (ratings.size() == 0)
        {
                return 0.0;
        }
        double average = 0;
        double total = 0;
        for (auto rating : ratings)
        {
                total += rating.getScore();
        }
        average = total / ratings.size();
        return average;
}

vector<Request> &Motorbike::getRequests()
{
        return this->requests;
}

int Motorbike::getMotorbikeId()
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

string Motorbike::getModel()
{
        return model;
}

string Motorbike::getColor()
{
        return this->color;
}

string Motorbike::getEngine()
{
        return engineSize;
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
{
        int i = 1;
        cout << "View requests of the motorbike " << motorbikeID << "\n";
        for (Request request : requests)
        {
                cout << "Request " << i << ":\n";
                request.showInfo();
        }
}

bool Motorbike::checkAvailability(bool availability)
{
        return this->availability;
}

vector<MotorbikeRating> &Motorbike::getRatings(){
        return this->ratings;
};

// void Motorbike::addCreditPoints(double points)
// {

// }

string Motorbike::toStringMotorBike()
{
        string cityStr;
        switch (city)
        {
        case City::Saigon:
                cityStr = "Saigon";
                break;
        case City::Hanoi:
                cityStr = "Hanoi";
                break;
                // Handle other cases if needed
        default:
                cityStr = "Unknown";
        }
        string bo= (this->availability) ? "true" :"false";
        return this->model + "," +
               to_string(motorbikeID) + "," +
               this->color + "," +
               this->engineSize + "," +
               cityStr + "," +
               this->owner + "," +
               this->transmissionMode + "," +
               to_string(yearMade) + "," +
               this->description + "," +
               to_string(this->consumingPoints) + "," +
               to_string(this->rentalAmount) + "," +
               to_string(this->minRenterRating)+","+
               bo;
}