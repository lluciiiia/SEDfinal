#include "Rating.h"
#include "Motorbike.h"

Rating::Rating() {}
Rating::Rating(float score, std::string comment) : score(score), comment(comment) {}

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
