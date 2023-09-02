#include <iostream>
#include <string>
#include <vector>
#include "Rating.h"
#include "Motorbike.h"

Rating::Rating()

{
    
}

float Rating::getScore () const
{

    return this->score;
}


std::string Rating::getComment() const
{
    return this->comment;
}




// user rating
UserRating::UserRating():Rating(0, "")
{
    this->username="";
}

UserRating::UserRating(std::string username, float score, std::string comment):Rating(score,comment)
{
    this->username = username;
}



float UserRating::getScore() const
{
    return Rating::getScore();
}

std::string UserRating::getUsername() const
{
    return username;
}

std::string UserRating::getComment() const
{
    return Rating::getComment();
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

