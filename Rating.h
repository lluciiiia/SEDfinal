#ifndef RATING_H
#define RATING_H

#include <iostream>
#include <string>
#include <vector>

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
    void setComment(std::string comment);
};

class UserRating : public Rating
{
private:
    std::string username;

public:
    // Constructors
    UserRating();
    UserRating(std::string username, float score, std::string comment);
    // Getter
    std::string getUsername() const;
    string uRatingtoString(){
        return username+","+
                to_string(Rating::getScore())+","+
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
    MotorbikeRating(int bikeID, float score, std::string comment);
    // Getter
    int getBikeId() const;

    // Setter
    void setBikeId(int bikeID);
    string mRatingtoString(){
        return to_string(bikeID)+","+
                to_string(Rating::getScore())+","+
                Rating::getComment();
    }
};

#endif