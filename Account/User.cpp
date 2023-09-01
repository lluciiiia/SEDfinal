#include "User.h"






User::User(string username, string password, string full_name, string phone_number, string userID,  string passportType, string licenseNumber,string licenseExpiryDate, UserRating rating,double creditPoint):
 Account(username,password,full_name, phone_number){
    this->userID= userID;
    this->passportType= passportType;
    this->licenseNumber= licenseNumber;
    this-> licenseExpiryDate = licenseExpiryDate;
    userRatings.push_back(rating);
    this->creditPoint= creditPoint;
 }

User:: User(string username, string password, string full_name, string phone_number,string userID,  string passportType, string licenseNumber,string licenseExpiryDate, vector<UserRating> ratings,double creditPoint):
Account(username,password,full_name, phone_number){
     this->userID= userID;
    this->passportType= passportType;
    this->licenseNumber= licenseNumber;
    this-> licenseExpiryDate = licenseExpiryDate;
    this->userRatings= userRatings;
    this->creditPoint= creditPoint;
}

User::User(string username, string password, string full_name, string phone_number, string userID,  string passportType, string licenseNumber, string licenseExpiryDate, double creditPoint)
:
Account(username,password,full_name, phone_number){
     this->userID= userID;
    this->passportType= passportType;
    this->licenseNumber= licenseNumber;
    this-> licenseExpiryDate = licenseExpiryDate;

    this->creditPoint= creditPoint;
}

string User::toStringAccount(){
   return Account::getUsername()+ ","+
    Account::getPassword()+","+
    Account::getFull_Name()+","+
    Account::getPhoneNumber()+","+
    this->userID+","+
    this->passportType+","+
    this->licenseNumber+","+
    this->licenseExpiryDate+","+
    to_string(this->creditPoint);
}

bool User::registerAccount(const string &username, const string &password, const double &credit, vector<User> &userList)
{
   
}
