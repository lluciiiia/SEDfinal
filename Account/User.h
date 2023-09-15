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

        string getUserName();
    string getIdType();
    string getIdNum();
    string getLicenseNum();
    double getRating();
    string getExDate();
    double getCreditPoint();
    City getCity();
    vector<Motorbike> getOwnedMotorbike();
    vector<Motorbike> &getOwned();
    vector<Request> &getSentRequests();

    string toStringAccount();
    friend bool login(User &cus, vector<User> &userList, vector<Motorbike> &bikes);
    bool registerAccount(vector<User> &userList);
    void searchAvailableMotorbikes();
    void setCreditPoint(double credit);
    void requestToRent(vector<Motorbike> &bike, vector<Request> &requests);
    void viewRequestsDash();
    void viewSentRequests();
    void viewBikeRequests();
    bool processPayment(User &requester, Request request);
    double calculateRentalAmount(Request &request);
    void acceptRequest(User &requester, vector<Request> &requests, Request &request, vector<User> &users);
    void addRequest(const Request &request);
    // void acceptRequest(vector<Request> &requests, Request request, s);
    void setOwnedBikes(vector <Motorbike> &bikes);
    void viewReviews(vector<Motorbike> &bikes);
    void rateUserAndMotorbike(User &ratedUser, Motorbike &ratedMotorbike);
    bool addBike(vector<Motorbike> &bikes);    // = list
    void removeBike(vector<Motorbike> &bikes); // = unlist
    void addMotorInnitial(Motorbike motor);
    // bool login(User &cus); // TODO: do we need this?
    // bool login(const string &username,
    //            const string &pass,
    //            vector<User> &userList); // TODO: do we need this?
    // vector <Motorbike> rentBikes();
    // vector <Request> receiveRequest();

    friend class Admin;
};

#endif
