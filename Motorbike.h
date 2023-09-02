#ifndef MOTORBIKE_H
#define MOTORBIKE_H

#include <iostream>
#include <string>
#include <vector>
#include "Request.cpp"
#include "TimeSlot.cpp"
#include "Motorbike.h"

enum class City
{
    Saigon,
    Hanoi


class Motorbike
{
public:

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
        double motorbikeRating);

    // TODO: Getter methods for attributes

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
    std::vector<Request> requests;
    std::vector<TimeSlot> availability;
};

#endif
