#ifndef USER_H
#define USER_H

#include <string>
#include <vector>
#include "Account.h"
#include "../Rating.h"
#include "../Motorbike.h"
#include "../City.h"
#include "../TimeSlot.h"

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
    vector<Motorbike> OwnedMotorbikes;
    vector<Motorbike> RentingBikes;
    double creditPoint;
    City city;

public:
    User();
    User(string username, string password, string fullName, string phoneNumber, string IDtype, string idNum, string licenseNumber, string licenseExpiryDate, vector<UserRating> userRatings, double creditPoint);
    User(string username, string password, string fullName, string phoneNumber, string IDtype, string idNum, string licenseNumber, string licenseExpiryDate, double creditPoint);
    User(string username, string password, string fullName, string phoneNumber, string IDtype, string idNum, string licenseNumber, string licenseExpiryDate, double creditPoint, City city);
    
    string toStringAccount();
    string getUserName();
    bool login(const string &username, const string &pass, vector<User> &userList);
    bool registerAccount(const string &username, const string &password, const double &credit, vector<User> &userList, string fullName, string phoneNumber, string Type, string idNum, string licenseNum, string licenseExdate);

    // listMotorbike()
    // unlistMotorbike()
    void searchAvailableMotorbikes();
    void requestToRent(Motorbike &motorbike, TimeSlot timeSlot);
    void viewRequests();
    void acceptRequest(vector<Request> &requests, Request request);
    void rateUser();
    void rateMotorbike();

    // vector <Motorbike> addOwnedMotorbike(Motorbike bike);
    // vector <Motorbike> rentBikes();
    // vector <Request> receiveRequest();

    // Friend classes to access private attributes
    friend class Admin;
};

#endif
