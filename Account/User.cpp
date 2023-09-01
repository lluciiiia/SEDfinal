#include "User.h"
#include <iostream>

User::User() 
    : Account("", "", "", ""), 
      passportType(""),
      idNum(""),
      licenseNumber(""),
      licenseExpiryDate(""),
      creditPoint(0.0) {        
}


User::User(string username, string password, string full_name, string phone_number, string passportType, string idNum, string licenseNumber, string licenseExpiryDate, UserRating rating, double creditPoint) : Account(username, password, full_name, phone_number)
{

    this->passportType= passportType;
    this->idNum= idNum;
    this->licenseNumber= licenseNumber;
    this-> licenseExpiryDate = licenseExpiryDate;
    userRatings.push_back(rating);
    this->creditPoint= creditPoint;
}

User:: User(string username, string password, string full_name, string phone_number,   string passportType, string idNum,string licenseNumber,string licenseExpiryDate,double creditPoint):
Account(username,password,full_name, phone_number){
    
    this->passportType= passportType;
    this->idNum= idNum;
    this->licenseNumber= licenseNumber;
    this-> licenseExpiryDate = licenseExpiryDate;
    this->userRatings= userRatings;
    this->creditPoint= creditPoint;
}

User::User(string username, string password, string full_name, string phone_number,  string passportType,string idNum, string licenseNumber,string licenseExpiryDate, vector<UserRating> ratings,double creditPoint)
:
Account(username,password,full_name, phone_number){

   
    this->passportType= passportType;
    this->idNum= idNum;
    this->licenseNumber= licenseNumber;
    this-> licenseExpiryDate = licenseExpiryDate;
    this->creditPoint= creditPoint;
}

string User::toStringAccount(){
   return Account::getUsername()+ ","+
    Account::getPassword()+","+
    Account::getFull_Name()+","+
    Account::getPhoneNumber()+","+
    this->passportType+","+
    this->idNum+","+
    this->licenseNumber+","+
    this->licenseExpiryDate+","+
    to_string(this->creditPoint);
}

bool User::registerAccount(const string &username, const string &password, const double &credit, vector<User> &userList, string fullName, string phoneNumber,  string Type, string idNum,string licenseNum, string licenseExdate)
{
   for( User&user: userList){
        if( user.getUserNAME()== username){
            cout<< "Username "<< username << " already exists.";
            return false;
        }else{

            userList.emplace_back(username,password,fullName,phoneNumber,passportType,idNum,licenseNum,licenseExdate);
            cout<<"Register successfully! ";
            
        }
   }
   return true;
}
