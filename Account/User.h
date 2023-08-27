#include<string>
#include <vector>
#include "Account.h"
#include "../Rating.h"
#include "../Motobike.h"
using namespace std;

class User: public Account{
    private:
    string userID;
    string IDtype;
    string passportType;
    string licenseNumber;
    string licenseExpiryDate;
    vector <UserRating> userRatings;
    double creditPoint;
    public: 
    User(string username, string password, string full_name, string phone_number, string userID, string IDtype, string passportType, string licenseNumber,string licenseExpiryDate, UserRating rating,double creditPoint);
    User(string username, string password, string full_name, string phone_number,string userID, string IDtype, string passportType, string licenseNumber,string licenseExpiryDate, vector<UserRating> ratings,double creditPoint);
};