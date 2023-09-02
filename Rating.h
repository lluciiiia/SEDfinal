#ifndef RATING_H
#define RATING_H

#include <iostream>
#include <string>
#include <vector>
#include "Account/User.h"

class Rating
{
private:
    float score;
    std::string comment;

public:
    Rating();
    Rating(float score, string comment);
    float getScore();
    void setScore(float score);
    std::string getComment();
    void setComment(std::string comment);
    // I just changed the parameter for this
    int getNumberOfRatings(const User& user);
};

class UserRating : public Rating
{
    std::string username;

public:
    UserRating();
    UserRating(std::string username, float score, std::string comment);
};

class MotorbikeRating : public Rating
{
    std::string bikeID;

    // Constructors
    MotorbikeRating();
    MotorbikeRating(std::string bikeID, float score, std::string comment);
};

class MotorbikeRating : public Rating
{
    std::string bikeID;

public:
    MotorbikeRating();
    MotorbikeRating(std::string bikeID, float score, std::string comment);
};

#endif
