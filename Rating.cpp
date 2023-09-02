#include <Rating.h> // Not sure if this gives errors in your vscode

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

// Just changed this
int Rating::getNumberOfRatings(const User& user) {
    const std::vector<UserRating>& ratings = user.getUserRatings();
    return ratings.size();
}

UserRating::UserRating() : Rating(), username("") {}

UserRating::UserRating(std::string username, float score, std::string comment)
    : Rating(score, comment), username(username) {}

MotorbikeRating::MotorbikeRating() : Rating(), bikeID("") {}

MotorbikeRating::MotorbikeRating(std::string bikeID, float score, std::string comment)
    : Rating(score, comment), bikeID(bikeID) {}
