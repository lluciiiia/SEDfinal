#include "Rating.h"

// Constructors for Rating class
Rating::Rating() : score(0.0), comment("") {}
Rating::Rating(float score, std::string comment) : score(score), comment(comment) {}

// Constructors for User Rating class
UserRating::UserRating() : Rating(), username("") {}
UserRating::UserRating(std::string username, float score, std::string comment)
    : Rating(score, comment), username(username) {}

// Constructors for Motorbike Rating class
MotorbikeRating::MotorbikeRating() : Rating(), bikeID() {}
MotorbikeRating::MotorbikeRating(int bikeID, float score, std::string comment)
    : Rating(score, comment), bikeID(bikeID) {}

// Getters
float &Rating::getScore()
{
    return score;
}

std::string Rating::getComment() const
{
    return comment;
}

std::string UserRating::getUsername() const
{
    return username;
}

int MotorbikeRating::getBikeId() const
{
    return bikeID;
}

// Setters
void Rating::setScore(float score)
{
    this->score = score;
}

void Rating::setComment(std::string comment)
{
    this->comment = comment;
}

void MotorbikeRating::setBikeId(int bikeID)
{
    this->bikeID = bikeID;
}