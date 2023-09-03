#ifndef MOTOBIKE_H
#define MOTOBIKE_H

#include <iostream>
#include <string>
#include <vector>
#include "Request.h"
#include "TimeSlot.h"
#include "City.h"

using namespace std;

class Motorbike {
private:
    string model;
    string motorbikeID;
    string color;
    string engineSize;
    City city;
    string transmissionMode;
    int yearMade;
    string description;
    double consumingPoints;
    double rentalAmount;
    double minRenterRating;
    double motorbikeRating;
    string ownerUsername;
    string renterUsername;
    vector<Request> requests;
    bool availability;

public:
    Motorbike(string _model, string _motorbikeID, string _color, string _engineSize, City _city, string _transmissionMode, int _yearMade, string _description, double _consumingPoints, double _rentalAmount, double _minRenterRating, double _motorbikeRating);

    TimeSlot getTimeSlot();
    std::string getUsername();
    std::string getMotorbikeId();
    double getConsumingPoints();
    void setUsername(std::string username);
    void setMotorbikeID(std::string motorbikeID);
    void setConsumingPoints(double consumingPoints);
    void addRequest(Request request);
    void viewRequests();
    bool checkAvailability();
    void reserveTimeSlot(TimeSlot timeSlot);
    void addCreditPoints(double points);
};

enum class City
{
    Saigon,
    Hanoi
};



#endif
