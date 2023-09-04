#ifndef MOTORBIKE_H
#define MOTORBIKE_H

#include <iostream>
#include <string>
#include <vector>
#include "TimeSlot.h"
#include "Motorbike.h"
#include "City.h"
#include "Account/User.h"
#include "Request.h"

class User;
class Motorbike
{
private:
  

    // TODO: Getter methods for attributes
public:
    // Methods to manage requests and availability
    void addRequest(const Request &request);
    void viewRequest(const Request &request);
    void checkAvailability(const TimeSlot &timeSlot);
    void reserveTimeSlot(const TimeSlot &timeSlot);
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
    string ownerUsername;
    string renterUsername;
    bool availability;

public:
    Motorbike(  string model,
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
                     string renter);
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
    void viewRequests();
    bool checkAvailability(bool availability);
    void addCreditPoints(double points);
    // SavingToFile
    //string toStringMotorBike();

      Motorbike(
        std::string &model, std::string &motorbikeID, std::string &color, std::string &engineSize, City &city, std::string &transmissionMode, int yearMade, std::string &description, double consumingPoints, double rentalAmount, double minRenterRating, double motorbikeRating, bool availability);
};

#endif
