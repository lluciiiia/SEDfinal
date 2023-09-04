#ifndef USER_H
#define USER_H

#include <string>
#include <vector> // Add this line
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
    string passportType;
    string idNum;
    string licenseNumber;
    string licenseExpiryDate;
    vector<UserRating> userRatings;
    vector<Motorbike> OwnedMotorbikes;
    vector<Motorbike> RentingBikes;
    double creditPoint;
    vector<Motorbike> listOwnedMotorbike;
    vector <Motorbike> listrentingBike;
    vector <Request> listOfRequest;
    City city;
public:
    User();
    User(string username, string password, string fullName, string phoneNumber, string passportType, string idNum, string licenseNumber, string licenseExpiryDate, UserRating rating, double creditPoint);
    
    
    User(string username, string password, string fullName, string phoneNumber, string passportType, string idNum, string licenseNumber, string licenseExpiryDate, double creditPoint);
     User(string username, string password, string fullName, string phoneNumber, string passportType, string idNum, string licenseNumber, string licenseExpiryDate, double creditPoint,City city);
    User(string username, string password, string fullName, string phoneNumber, string passportType, string idNum, string licenseNumber, string licenseExpiryDate, vector<UserRating> ratings, double creditPoint);
    string toStringAccount();
    string getUserName();
    bool login(const string &username, const string &pass, vector<User> &userList);
    bool registerAccount(vector <User> &userList);

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
};

#endif
