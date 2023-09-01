
// Rating
class Rating {
    protected:
    float score;
    string comment;
};

// UserRating
class UserRating : protected Rating{
    string username;
    public:
    UserRating(string username, float score, string comment) {
        this->username = username;
        this->score = score;
        this->comment = comment;
    }
};

// BikeRating
class MotorbikeRating : protected Rating{
    string bikeID;
    public:
    MotorbikeRating(string bikeID, float score, string comment) {
        this->bikeID = bikeID;
        this->score = score;
        this->comment = comment;
    }
};
