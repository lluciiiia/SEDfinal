#include <iostream>
#include <string>
#include <vector>
#include "Rating.h"


Rating::Rating()

{
    
}

float Rating::getScore()
{

    return this->score;
}


std::string Rating::getComment()
{
    return this->comment;
}

UserRating::UserRating():Rating(0, "")
{
    this->username="";
}

UserRating::UserRating(std::string username, float score, std::string comment):Rating(score,comment)
{
    this->username = username;
}



float UserRating::getUserScore()
{
    return Rating::getScore();
}

std::string UserRating::getComment()
{
    return Rating::getComment();
}

float MotorbikeRating::getScore()
{
    return Rating::getScore();
}

std::string MotorbikeRating::getComment()
{
    return Rating::getComment();
}

std::string MotorbikeRating::getBikeId()
{
    return bikeID;
}

