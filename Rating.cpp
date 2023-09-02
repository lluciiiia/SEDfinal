#include "Rating.h"


Rating::Rating() : score(0.0), comment("") {}

Rating::Rating(float score, std::string comment) : score(score), comment(comment) {}

float Rating::getScore() {
    return score;
}

void Rating::setScore(float score) {
    this->score = score;
}

std::string Rating::getComment() {
    return comment;
}

void Rating::setComment(std::string comment) {
    this->comment = comment;
}

int Rating::getNumberOfRatings() {
    // TODO: Implement this function to get the number of ratings
    return 0; // Placeholder value, replace with actual implementation
}

UserRating::UserRating() : Rating(), username("") {}

UserRating::UserRating(std::string username, float score, std::string comment)
    : Rating(score, comment), username(username) {}

MotorbikeRating::MotorbikeRating() : Rating(), bikeID("") {}

MotorbikeRating::MotorbikeRating(std::string bikeID, float score, std::string comment)
    : Rating(score, comment), bikeID(bikeID) {}
