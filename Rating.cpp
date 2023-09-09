#include "Rating.h"
#include "Motorbike.h"

Rating::Rating() : score(0.0), comment("") {}
Rating::Rating(float score, std::string comment) : score(score), comment(comment) {}

UserRating::UserRating() : Rating(), username("") {}
UserRating::UserRating(std::string username, float score, std::string comment)
    : Rating(score, comment), username(username) {}

MotorbikeRating::MotorbikeRating() : Rating(), bikeID("") {}
MotorbikeRating::MotorbikeRating(std::string bikeID, float score, std::string comment)
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

void Rating::setComment(string comment)
{
    this->comment = comment;
}

// user rating
float UserRating::getScore() const
{
    return Rating::getScore();
}

std::string UserRating::getComment() const
{
    return Rating::getComment();
}

std::string UserRating::getUsername() const
{
    return username;
}

// motobike rating
float MotorbikeRating::getScore() const
{
    return Rating::getScore();
}

std::string MotorbikeRating::getComment() const
{
    return Rating::getComment();
}

std::string MotorbikeRating::getBikeId() const
{
    return bikeID;
}
