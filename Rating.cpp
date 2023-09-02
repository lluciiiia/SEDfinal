#include <iostream>
#include <string>
#include <vector>
#include "User.cpp" // I'm not sure if it's .cpp or .h

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
    // Constructors
    UserRating();

    UserRating(std::string username, float score, std::string comment)
    {
        this->username = username;
        this->score = score;
        this->comment = comment;
    }

    // Getters/setters
    int getScore() {
        return this->score;
    }

    void setScore(int score) {
        this->score = score;
    }

    std::string getComment() {
        return this->comment;
    }

    void setComment(std::string comment) {
        this->comment = comment;
    }

    // Missing the user class so it's giving an error
    int getNumberOfRatings() {
        return userRating->size;
    }

};

class MotorbikeRating : public Rating
{
    std::string bikeID;


    // Constructors 
    MotorbikeRating();

    MotorbikeRating(std::string bikeID, float score, std::string comment)
    {
        this->bikeID = bikeID;
        this->score = score;
        this->comment = comment;
    }

    int getScore() {
        return this->score;
    }

    void setScore (int score) {
        this->score = score; 
    }

    std::string getComment() {
        return this->comment;
    }

    void setComment(std::string comment) {
        this->comment = comment;
    }
};

#endif

};

#endif

