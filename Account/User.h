#ifndef USER_H
#define USER_H

#include <string>
#include <vector> 
#include "Account.h"
#include "../Rating.h"
#include "../Motorbike.h"
#include "../City.h"

class Motorbike;
class Request;
class UserRating;

class User : public Account
{
private:
    string IDtype;
    string idNum;
    string licenseNumber;
    string licenseExpiryDate;
    vector<UserRating> userRatings;
    double creditPoint;
    vector<Motorbike> listOwnedMotorbike;
    vector <Motorbike> listrentingBike;
    vector <Request> listOfRequest;
    City city;
public:
    User();
    User(string username, string password, string fullName, string phoneNumber, string IDtype, string idNum, string licenseNumber, string licenseExpiryDate, UserRating rating, double creditPoint);
    User(string username, string password, string fullName, string phoneNumber, string IDtype, string idNum, string licenseNumber, string licenseExpiryDate, double creditPoint);
    User(string username, string password, string fullName, string phoneNumber, string IDtype, string idNum, string licenseNumber, string licenseExpiryDate, double creditPoint, City city);
    User(string username, string password, string fullName, string phoneNumber, string IDtype, string idNum, string licenseNumber, string licenseExpiryDate, vector<UserRating> ratings, double creditPoint);
    string toStringAccount();
    string getUserName();
    bool login(const string &username, const string&pass, vector <User> &userList);
    bool registerAccount(const string &username, const string &password, const double &credit, vector<User> &userList, string fullName, string phoneNumber,  string Type, string idNum,string licenseNum, string licenseExdate);
    // vector <Motorbike> addOwnedMotorbike(Motorbike bike);
    // vector <Motorbike> rentBikes();
    // vector <Request> receiveRequest();
};

#endif
