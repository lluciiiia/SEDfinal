#include "Account.h"
#include <iostream>
#include <vector>
using namespace std;

Account::Account(std::string username, std::string password, std::string fullName, std::string phoneNumber) : username(username), password(password), fullName(fullName), phoneNumber(phoneNumber) {}

// Getters
string Account::getUsername()
{
    return username;
}

string Account::getPassword()
{
    return password;
}

string Account::getFullName()
{
    return fullName;
}

string Account::getPhoneNumber()
{
    return phoneNumber;
}

// Setters
void Account::setUsername(string userName)
{
    this->username = userName;
}

void Account::setPassword(string pass)
{
    this->password = pass;
}
void Account::setFullName(string fullName)
{
    this->fullName = fullName;
}

void Account::setPhoneNumber(string phoneNumber)
{
    this->phoneNumber = phoneNumber;
}

