#ifndef MOTORBIKE_H
#define MOTORBIKE_H

#include <iostream>
#include <string>
#include <vector>
#include "Request.h"
#include "TimeSlot.h"
#include "Motorbike.h"
#include "City.h"

class Motorbike
{
private:
    Motorbike(
        std::string &model,
        std::string &motorbikeID,
        std::string &color,
        std::string &engineSize,
        City &city,
        std::string &transmissionMode,
        int yearMade,
        std::string &description,
        double consumingPoints,
        double rentalAmount,
        double minRenterRating,
        double motorbikeRating, bool availability);

    // TODO: Getter methods for attributes
public:
    // Methods to manage requests and availability
    void addRequest(const Request &request);
    void viewRequest(const Request &request);
    void checkAvailability(bool &availability);
    void addCreditPoints();

    string toStringMotorBike();

private:
    std::string model;
    std::string motorbikeID;
    std::string color;
    std::string engineSize;
    City city;
    std::string transmissionMode;
    int yearMade;
    std::string description;
    double consumingPoints;
    double rentalAmount;
    double minRenterRating;
    double motorbikeRating;
    std::vector<Request> requests;
    bool availability;
};

#endif
