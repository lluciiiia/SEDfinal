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
        User &owner,
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
    User owner;
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
    Motorbike(string model, string motorbikeID, string color, string engineSize, City city, User owner, string transmissionMode, int yearMade, string description, double consumingPoints, double rentalAmount, double minRenterRating, double motorbikeRating);
    // Getters
    User getOwner();
    string getMotorbikeId();
    double getConsumingPoints();
    // Setters
    void setOwner(User Owner);
    void setMotorbikeID(string motorbikeID);
    void setConsumingPoints(double consumingPoints);
    void setAvailability(bool availability);
    // Request / Availability / Credit Points
    void addRequest(const Request &request);
    void viewRequests();
    bool checkAvailability(bool availability);
    // void addCreditPoints(double points);
    // SavingToFile
    string toStringMotorBike();

    friend class Admin;
};

#endif
