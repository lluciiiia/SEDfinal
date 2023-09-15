#ifndef MOTORBIKE_H
#define MOTORBIKE_H

#include <iostream>
#include <string>
#include <vector>
#include "Request.h"
#include "TimeSlot.h"
#include "Motorbike.h"
#include "City.h"
#include "Account/User.h"
#include "Request.h"
#include "Rating.h"
class User;
class Rating;
class Request;
class Motorbike
{
private:
    
        std::string model;
        int motorbikeID;
        std::string color;
        std::string engineSize;
        City city;
        string owner;
        std::string transmissionMode;
        int yearMade;
        std::string description;
        double consumingPoints;
        double rentalAmount;
        double minRenterRating;
        double motorbikeRating;
        bool availability;
        std::vector<Request> requests;
        std::vector<Rating> ratings;

public:
    Motorbike(string model, int motorbikeID, string color, string engineSize, City city, string owner, string transmissionMode, int yearMade, string description, double consumingPoints, double rentalAmount,double minRenterRating);
    Motorbike(string model, int motorbikeID, string color, string engineSize, City city, string owner, string transmissionMode, int yearMade, string description, double consumingPoints, double rentalAmount,double minRenterRating,bool avai);
    // Getters

    int getMotorbikeId();
    double getConsumingPoints();
    bool getAvailability();
    string getModel();
    string getColor();
    string getEngine();
    City getCity();
    string getOwner();
    int getYear();
    string getDes();
    double getRating();
    vector<Rating> &getRatings();
    vector<Request> &getRequests();
    // Setters
    void setOwner(string Owner);
    void setMotorbikeID(int motorbikeID);
    void setConsumingPoints(double consumingPoints);
    void setAvailability(bool availability);
    // Request / Availability / Credit Points
    void addRequest(const Request &request);
    void viewRequest(const Request &request);
    void viewRequests();
    bool checkAvailability(bool availability);
    void reserveTimeSlot(const TimeSlot &timeSlot);
    void addCreditPoints(double &points);   

    //to string
    string toStringMotorBike();

    friend class User;
};

#endif
