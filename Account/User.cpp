#include "User.h"
#include <iostream>
#include "Account.h"
#include "../Rating.h"
#include "../Motorbike.h"

// TODO: Add City attribute 
User::User()
    : Account("", "", "", ""),
      IDtype(""),
      passportType(""),
      idNum(""),
      licenseNumber(""),
      licenseExpiryDate(""),
      creditPoint(0.0)
{
}
 // TODO: Add ITtype attribute
User::User(string username,
           string password,
           string fullName,
           string phoneNumber,
           string passportType,
           string idNum,
           string licenseNumber,
           string licenseExpiryDate,
           UserRating rating,
           double creditPoint) : Account(username,
                                         password,
                                         fullName,
                                         phoneNumber)
{
    this->passportType = passportType;
    this->idNum = idNum;
    this->licenseNumber = licenseNumber;
    this->licenseExpiryDate = licenseExpiryDate;
    userRatings.push_back(rating);
    this->creditPoint = creditPoint;
}

User::User(string username,
           string password,
           string fullName,
           string phoneNumber,
           string passportType,
           string idNum,
           string licenseNumber,
           string licenseExpiryDate,
           double creditPoint) : Account(username,
                                         password,
                                         fullName,
                                         phoneNumber)
{
    this->passportType = passportType;
    this->idNum = idNum;
    this->licenseNumber = licenseNumber;
    this->licenseExpiryDate = licenseExpiryDate;
    this->userRatings = userRatings;
    this->creditPoint = creditPoint;
}

User::User(string username, string password, string fullName, string phoneNumber, string passportType, string idNum, string licenseNumber, string licenseExpiryDate, double creditPoint, City city):Account(username,
              password,
              fullName,
              phoneNumber)
{
    this->passportType = passportType;
    this->idNum = idNum;
    this->licenseNumber = licenseNumber;
    this->licenseExpiryDate = licenseExpiryDate;
    this->creditPoint = creditPoint;
    this->city = city;
}

User::User(string username,
           string password,
           string fullName,
           string phone_number,
           string passportType,
           string idNum,
           string licenseNumber,
           string licenseExpiryDate,
           vector<UserRating> ratings,
           double creditPoint)
    : Account(username,
              password,
              fullName,
              phone_number)
{
    this->passportType = passportType;
    this->idNum = idNum;
    this->licenseNumber = licenseNumber;
    this->licenseExpiryDate = licenseExpiryDate;
    this->creditPoint = creditPoint;
}

string User::toStringAccount()
{
    string cityStr;
    switch (city) {
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
           this->passportType + "," +
           this->idNum + "," +
           this->licenseNumber + "," +
           this->licenseExpiryDate + "," +
           to_string(this->creditPoint)+","+
           cityStr;
}

bool User::login(const string &username, const string &pass, vector<User> &userList)
{
    for(auto &user: userList){
        if(user.getUserName() == username && user.getPassword() == pass){
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
                           string Type,
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
            this->passportType = Type;
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
