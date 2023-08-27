#include "User.h"





User::User(string username, string password, string full_name, string phone_number, string userID, string IDtype, string passportType, string licenseNumber,string licenseExpiryDate, UserRating rating,double creditPoint):
 Account(username,password,full_name, phone_number){
    this->userID= userID;
    this-> IDtype= IDtype;
    this->passportType= passportType;
    this->licenseNumber= licenseNumber;
    this-> licenseExpiryDate = licenseExpiryDate;
    userRatings.push_back(rating);
    this->creditPoint= creditPoint;
 }

User:: User(string username, string password, string full_name, string phone_number,string userID, string IDtype, string passportType, string licenseNumber,string licenseExpiryDate, vector<UserRating> ratings,double creditPoint):
Account(username,password,full_name, phone_number){
     this->userID= userID;
    this-> IDtype= IDtype;
    this->passportType= passportType;
    this->licenseNumber= licenseNumber;
    this-> licenseExpiryDate = licenseExpiryDate;
    this->userRatings= userRatings;
    this->creditPoint= creditPoint;
}