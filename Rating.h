#ifndef RATING_H
#define RATING_H


#include <iostream>
#include <string>
#include <vector>
#include "Account/User.h" // I'm not sure if it's .cpp or .h



class Rating
{
private:
    float score;
    std::string comment;
    public:
    Rating();
    Rating(float score, string comment);
    float getScore();
    std:: string getComment();
};

class UserRating : public Rating
{
    std::string username;

public:
    // Constructors
    UserRating();

    UserRating(std::string username, float score, std::string comment);

    // Getters/setters
    float getUserScore() ;

    

    std::string getComment();


    // Missing the user class so it's giving an error
    int getNumberOfRatings() ;

};

class MotorbikeRating : public Rating
{
    std::string bikeID;


    // Constructors 
    MotorbikeRating();

    MotorbikeRating(std::string bikeID, float score, std::string comment);

    float getScore() ;

    void setScore (int score);

    std::string getComment();

    void setComment(std::string comment) ;
    std:: string getBikeId();

};


<<<<<<< Updated upstream
public:
    MotorbikeRating();

    MotorbikeRating(std::string bikeID, float score, std::string comment);

    float getScore() const;
    void setScore(float score);

    std::string getComment() const;
    void setComment(const std::string &comment);
};
=======
>>>>>>> Stashed changes


#endif

