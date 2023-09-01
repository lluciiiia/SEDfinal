#include <iostream>
#include <string>
#include <vector>
#ifndef RATING_H
#define RATING_H

class Rating
{
protected:
    float score;
    std::string comment;
    std::string userID;
};

class UserRating : public Rating
{
    std::string username;

public:
    UserRating(std::string username, float score, std::string comment)
    {
        this->username = username;
        this->score = score;
        this->comment = comment;
    }

    // TODO: structure methods
};

class MotorbikeRating : public Rating
{
    std::string bikeID;

public:
    MotorbikeRating(std::string bikeID, float score, std::string comment)
    {
        this->bikeID = bikeID;
        this->score = score;
        this->comment = comment;
    }

    // TODO: structure methods
};

#endif