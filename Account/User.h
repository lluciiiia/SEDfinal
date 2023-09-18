#ifndef USER_H
#define USER_H

#include <string>
#include <vector>
#include "Account.h"
#include "../Rating.h"
#include "../Motorbike.h"
#include "../City.h"
#include "../TimeSlot.h"
#include "User.h"
#include "../Request.h"
#include "../RequestStatus.h"
#include "../Borrow.h"

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
    vector<Request> sentRequests;
    double creditPoint;
    City city;

public:
    User();
    User(string username, string password, string fullName, string phoneNumber, string IDtype, string idNum, string licenseNumber, string licenseExpiryDate, vector<UserRating> userRatings, double creditPoint, vector<Motorbike> owm, vector<Request> sentRequests);
    User(string username, string password, string fullName, string phoneNumber, string IDtype, string idNum, string licenseNumber, string licenseExpiryDate, double creditPoint);
    User(string username, string password, string fullName, string phoneNumber, string IDtype, string idNum, string licenseNumber, string licenseExpiryDate, double creditPoint, City city, vector<Motorbike> owm);
    User(string username, string password, string fullName, string phoneNumber, string IDtype, string idNum, string licenseNumber, string licenseExpiryDate, double creditPoint, City city);

    // getters
    string getUserName();
    string getIdType();
    string getIdNum();
    string getLicenseNum();
    double getRating();
    vector<UserRating> &getRatings();
    string getExDate();
    double getCreditPoint();
    City getCity();
    vector<Motorbike> getOwnedMotorbike();
    vector<Motorbike> &getOwned();
    vector<Request> &getSentRequests();

    // setters
    void setOwnedBikes(vector<Motorbike> &bikes);
    void setUserRating(vector<UserRating> &ratings);
    void setSentRequest(vector<Request> &requsest);
    void setCreditPoint(double credit);

    // account methods
    string toStringAccount();
    friend bool login(User &cus, vector<User> &userList, vector<Motorbike> &bikes);
    bool registerAccount(vector<User> &userList);

    // view methods
    void searchAvailableMotorbikes();
    void viewRequestsDash(vector<User> &userList, vector<Borrow> &bo, vector<Motorbike> &bikes);
    void viewSentRequests();
    void viewBikeRequests(vector<User> &userList, vector<Borrow> &bo, vector<Motorbike> &bikes);
    void viewReviews(vector<Motorbike> &bikes);

    // request methods
    void requestToRent(vector<Motorbike> &bike, vector<Request> &requests);
    void acceptRequest(User *requester, vector<Request> &requests, Request &request, vector<User> &users, vector<Borrow> &bo);
    void rejectRequest(Request &request, vector<Motorbike> &bikes);

    // return and review methods
    void returnBikes(User &user, vector<User> &userList, vector<Request> &re, vector<Borrow> &bo, vector<Motorbike> &bikes);
    void rateUserAndMotorbike(User &ratedUser, Motorbike &ratedMotorbike);

    // owned motorbike methods
    bool addBike(vector<Motorbike> &bikes);    // = list
    void removeBike(vector<Motorbike> &bikes); // = unlist

    friend class Admin;
};

#endif