

#ifndef USER_H
#define USER_H


#include<string>
#include <vector>
#include "Account.h"
#include "../Rating.h"
#include "../Motorbike.h"

class User: public Account{
    private:
    string IDtype;
    string passportType;
    string idNum;
    string licenseNumber;
    string licenseExpiryDate;
    vector <UserRating> userRatings;
    double creditPoint;
    public:
    User ();
    User(string username, string password, string full_name, string phone_number,  string passportType, string idNum,string licenseNumber,string licenseExpiryDate, UserRating rating,double creditPoint);
    User(string username, string password, string full_name, string phone_number,   string passportType, string idNum,string licenseNumber,string licenseExpiryDate,double creditPoint);
    User(string username, string password, string full_name, string phone_number,  string passportType,string idNum, string licenseNumber,string licenseExpiryDate, vector<UserRating> ratings,double creditPoint);
    string toStringAccount();
    string getUserNAME(){
        return Account::getUsername();
    }
    bool registerAccount(const string &username, const string &password, const double &credit, vector<User> &userList, string fullName, string phoneNumber,  string Type, string idNum,string licenseNum, string licenseExdate);





};




#endif // USER_H



