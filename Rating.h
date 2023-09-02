#ifndef RATING_H
#define RATING_H

#include <string>

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
    UserRating();

    UserRating(std::string username, float score, std::string comment);

    // Getters/setters
    float getScore() const;
    void setScore(float score);

    std::string getComment() const;
    void setComment(const std::string &comment);

    // TODO: Missing the user class so it's giving an error
    int getNumberOfRatings() const;
};

class MotorbikeRating : public Rating
{
    std::string bikeID;

public:
    MotorbikeRating();

    MotorbikeRating(std::string bikeID, float score, std::string comment);

    float getScore() const;
    void setScore(float score);

    std::string getComment() const;
    void setComment(const std::string &comment);
};

#endif
