#ifndef RATING_H
#define RATING_H

#include <iostream>
#include <string>
#include <vector>

// Include User.h header with the correct path
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
    float getScore() const; // Added const qualifier
    std::string getComment() const; // Added const qualifier
};

class UserRating : public Rating
{
private:
    std::string username;

public:
    // Constructors
    UserRating();
    UserRating(std::string username, float score, std::string comment);
    float getScore() const;
    // Getter for username
    std::string getUsername() const; // Added const qualifier
    std:: string getComment() const;
    // You don't need to redefine getScore and getComment since they are inherited
};


// motorbkike rating
class MotorbikeRating : public Rating
{
private:
    std::string bikeID;

public:
    // Constructors
    MotorbikeRating();
    MotorbikeRating(std::string bikeID, float score, std::string comment);
   
    // Getter and setter for bikeID
    std::string getBikeId() const; // Added const qualifier
    float getScore() const;
    std:: string getComment() const;
    void setBikeId(std::string bikeID) const;
};

#endif
