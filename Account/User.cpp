#include <iostream>
#include <vector>
#include "Account.h"
#include "../Rating.h"
#include "User.h"
#include "../Motorbike.h"
#include "../Request.h"

class UserRating;
class MotorbikeRating;

User::User()
    : Account("", "", "", ""),
      IDtype(""),
      idNum(""),
      licenseNumber(""),
      licenseExpiryDate(""),
      creditPoint(0.0)
{
}
// Including userRatings
User::User(string username,
           string password,
           string fullName,
           string phoneNumber,
           string IDtype,
           string idNum,
           string licenseNumber,
           string licenseExpiryDate,
           std::vector<UserRating> userRatings,
           double creditPoint) : Account(username,
                                         password,
                                         fullName,
                                         phoneNumber)
{
    this->IDtype = IDtype;
    this->idNum = idNum;
    this->licenseNumber = licenseNumber;
    this->licenseExpiryDate = licenseExpiryDate;
    this->userRatings = userRatings;
    this->creditPoint = creditPoint;
};

User::User(string username,
           string password,
           string fullName,
           string phoneNumber,
           string IDtype,
           string idNum,
           string licenseNumber,
           string licenseExpiryDate,
           double creditPoint) : Account(username,
                                         password,
                                         fullName,
                                         phoneNumber)
{
    this->IDtype = IDtype;
    this->idNum = idNum;
    this->licenseNumber = licenseNumber;
    this->licenseExpiryDate = licenseExpiryDate;
    this->creditPoint = creditPoint;
}

// Including City
User::User(string username,
           string password,
           string fullName,
           string phoneNumber,
           string IDtype,
           string idNum,
           string licenseNumber,
           string licenseExpiryDate,
           double creditPoint,
           City city) : Account(username,
                                password,
                                fullName,
                                phoneNumber)
{
    this->IDtype = IDtype;
    this->idNum = idNum;
    this->licenseNumber = licenseNumber;
    this->licenseExpiryDate = licenseExpiryDate;
    this->creditPoint = creditPoint;
    this->city = city;
}

string User::toStringAccount()
{
    string cityStr;
    switch (city)
    {
    case City::Saigon:
        cityStr = "Saigon";
        break;
    case City::Hanoi:
        cityStr = "Hanoi";
        break;
    // Handle other cases if needed
    default:
        cityStr = "Unknown";
    }
    return Account::getUsername() + "," +
           Account::getPassword() + "," +
           Account::getFullName() + "," +
           Account::getPhoneNumber() + "," +
           this->IDtype + "," +
           this->idNum + "," +
           this->licenseNumber + "," +
           this->licenseExpiryDate + "," +
           to_string(this->creditPoint) + "," +
           cityStr;
}

bool User::login(const string &username,
                 const string &pass,
                 vector<User> &userList)
{
    for (auto &user : userList)
    {
        if (user.getUserName() == username && user.getPassword() == pass)
        {
            return true;
        }
    }
    return false;
}

bool User::registerAccount(const string &username,
                           const string &password,
                           const double &credit,
                           vector<User> &userList,
                           string fullName,
                           string phoneNumber,
                           string Idtype,
                           string idNum,
                           string licenseNum,
                           string licenseExdate)
{
    for (User &user : userList)
    {
        if (user.getUserName() == username)
        {
            cout << "Username " << username << " already exists.";
            return false;
        }
        else
        {
            Account::setUsername(username);
            Account::setPassword(password);
            Account::setFullName(fullName);
            Account ::setPhoneNumber(phoneNumber);
            this->IDtype = IDtype;
            this->idNum = idNum;
            this->licenseNumber = licenseNum;
            this->licenseExpiryDate = licenseExdate;
            this->creditPoint = credit;
            userList.push_back(*this);
            cout << "Register successfully! ";
        }
    }
    return true;
}

// listMotorbike()
// unlistMotorbike()
void User::searchAvailableMotorbikes(){};

void User::requestToRent(Motorbike &motorbike, TimeSlot timeSlot)
{
    Request request(this, &motorbike, timeSlot);
    motorbike.addRequest(request);
}

void User::viewRequests(){};
void User::acceptRequest(vector<Request> &requests, Request request){

};
void User::rateUser(){};
void User::rateMotorbike(){};

// vector<Motorbike> User::addOwnedMotorbike(Motorbike bike)
// {
//     return vector<Motorbike>();
// }

// vector<Motorbike> User::rentBikes()
// {
//     return vector<Motorbike>();
// }

// vector<Request> User::receiveRequest()
// {
//     return vector<Request>();
// }
