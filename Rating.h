#ifndef RATING_H
#define RATING_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Rating
{
private:
    float score;
    string comment;

public:
    // Constructors
    Rating();
    Rating(float score, string comment);
    // Getters
    float &getScore();
    string getComment() const;
    // Setters
    void setScore(float score);
    void setComment(string comment);
};

class UserRating : public Rating
{
private:
    string username;

public:
    // Constructors
    UserRating();
    UserRating(string username, float score, string comment);
    // Getter
    string getUsername() const;
    string uRatingtoString(){
        return username+";"+
                to_string(Rating::getScore())+";"+
                Rating::getComment();
    }
};

class MotorbikeRating : public Rating
{
private:
    int bikeID;

public:
    // Constructors
    MotorbikeRating();
    MotorbikeRating(int bikeID, float score, string comment);
    // Getter
    int getBikeId() const;

    // Setter
    void setBikeId(int bikeID);
    string mRatingtoString(){
        return to_string(bikeID)+";"+
                to_string(Rating::getScore())+";"+
                Rating::getComment();
    }
};

#endif