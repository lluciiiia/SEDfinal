#include "Rating.h"

Rating::Rating() : score(0.0), comment("") {}
Rating::Rating(float score, std::string comment) : score(score), comment(comment) {}

UserRating::UserRating() : Rating(), username("") {}
UserRating::UserRating(std::string username, float score, std::string comment)
    : Rating(score, comment), username(username) {}

MotorbikeRating::MotorbikeRating() : Rating(), bikeID() {}
MotorbikeRating::MotorbikeRating(int bikeID, float score, std::string comment)
    : Rating(score, comment), bikeID(bikeID) {}

float Rating::getScore() const
{
    return score;
}

std::string Rating::getComment() const
{
    return comment;
}

void Rating::setScore(float score)
{
    this->score = score;
}

void Rating::setComment(std::string comment)
{
    this->comment = comment;
}

std::string UserRating::getUsername() const
{
    return username;
}

int MotorbikeRating::getBikeId() const
{
    return bikeID;
}

void MotorbikeRating::setBikeId(int bikeID)
{
    this->bikeID= bikeID;
}
