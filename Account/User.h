

#ifndef USER_H
#define USER_H


#include<string>
#include <vector>
#include "Account.h"
#include "../Rating.h"
#include "../Motobike.h"

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
    User(string username, string password, string full_name, string phone_number, string userID,  string passportType, string licenseNumber,string licenseExpiryDate, UserRating rating,double creditPoint);
    User(string username, string password, string full_name, string phone_number, string userID,  string passportType, string licenseNumber,string licenseExpiryDate,double creditPoint);
    User(string username, string password, string full_name, string phone_number,string userID,  string passportType, string licenseNumber,string licenseExpiryDate, vector<UserRating> ratings,double creditPoint);
    string toStringAccount();

    bool registerAccount(const string&username, const string&password,const double &credit, vector<User> &userList );
};




#endif // USER_H



