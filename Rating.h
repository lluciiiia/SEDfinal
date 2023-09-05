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
    // Constructors
    Rating();
    Rating(float score, std::string comment);
    // Getters
    float getScore() const;
    std::string getComment() const;
    // Setters
    void setScore(float score);
    void setComment(string comment);
};

class UserRating : public Rating
{
private:
    std::string username;

public:
    UserRating();
    UserRating(std::string username, float score, std::string comment);

    float getScore() const;
    std::string getComment() const;
    std::string getUsername() const;
};

class MotorbikeRating : public Rating
{
private:
    std::string bikeID;

public:
    // Constructors
    MotorbikeRating();
    MotorbikeRating(std::string bikeID, float score, std::string comment);
    // Getter & Setter
    float getScore() const;
    std::string getComment() const;
    std::string getBikeId() const;
    void setBikeId(std::string bikeID) const;
};

#endif
