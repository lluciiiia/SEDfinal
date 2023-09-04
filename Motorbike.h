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
        double motorbikeRating, bool availability,
        std::vector<Request> requests);

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
    string ownerUsername;
    string renterUsername;
    vector<Request> requests;
    bool availability;

public:
    Motorbike(string model, string motorbikeID, string color, string engineSize, City city, string transmissionMode, int yearMade, string description, double consumingPoints, double rentalAmount, double minRenterRating, double motorbikeRating);
    // Getters
    // TimeSlot getTimeSlot();
    string getUsername();
    string getMotorbikeId();
    double getConsumingPoints();
    // Setters
    void setUsername(string username);
    void setMotorbikeID(string motorbikeID);
    void setConsumingPoints(double consumingPoints);
    // Request / Availability / Credit Points
    void addRequest(const Request &request);
    void viewRequests();
    bool checkAvailability(bool availability);
    void addCreditPoints(double points);
    // SavingToFile
    string toStringMotorBike();
};

#endif
