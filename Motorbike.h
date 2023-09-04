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
    string ownerUsername;
    string renterUsername;
    vector<Request> requests;
    bool availability;

public:
    Motorbike(string model, string motorbikeID, string color, string engineSize, City city, string transmissionMode, int yearMade, string description, double consumingPoints, double rentalAmount, double minRenterRating, double motorbikeRating);

    TimeSlot getTimeSlot();
    string getUsername();
    string getMotorbikeId();
    double getConsumingPoints();
    void setUsername(string username);
    void setMotorbikeID(string motorbikeID);
    void setConsumingPoints(double consumingPoints);
    void addRequest(Request request);
    void viewRequests();
    bool checkAvailability();
    void reserveTimeSlot(TimeSlot timeSlot);
    void addCreditPoints(double points);
};

#endif
