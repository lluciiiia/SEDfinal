#include "User.h"
#include <iostream>

User::User()
    : Account("", "", "", ""),
      passportType(""),
      idNum(""),
      licenseNumber(""),
      licenseExpiryDate(""),
      creditPoint(0.0)
{
}

User::User(string username,
           string password,
           string fullName,
           string phone_number,
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
           string phone_number,
           string passportType,
           string idNum,
           string licenseNumber,
           string licenseExpiryDate,
           double creditPoint) : Account(username,
                                         password,
                                         fullName,
                                         phone_number)
{
    this->passportType = passportType;
    this->idNum = idNum;
    this->licenseNumber = licenseNumber;
    this->licenseExpiryDate = licenseExpiryDate;
    this->userRatings = userRatings;
    this->creditPoint = creditPoint;
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
    return Account::getUsername() + "," +
           Account::getPassword() + "," +
           Account::getFullName() + "," +
           Account::getPhoneNumber() + "," +
           this->passportType + "," +
           this->idNum + "," +
           this->licenseNumber + "," +
           this->licenseExpiryDate + "," +
           to_string(this->creditPoint);
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
