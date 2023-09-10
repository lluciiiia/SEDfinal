#include "Admin.h"
#include <iostream>

using namespace std;

Admin::Admin()
    : Account("", "", "", "")
// TODO: default
{
}

Admin::Admin(string username,
             string password,
             string fullName,
             string phoneNumber,
             string adminID)
    : Account(username, password, fullName, phoneNumber), adminID(adminID)
{
    this->adminID = adminID;
}

//Might change parameter -> vector
void Admin::viewMemberInfo(User user)
{    
    //Print userID, IDtype, licenseNumber, licenseExpiryDate, creditPoits, city 
    //(Might add motorbike, motorbikeRatings and userRatings if necessary)
    cout << "\nMember information:\n";
    cout << "User ID: " << user.userID << endl;
    cout << "ID Type: " << user.IDtype << endl;
    cout << "License Number: " << user.licenseNumber << endl;
    cout << "License Expiry Date: " << user.licenseExpiryDate << endl;
    cout << "Credit points: " << user.creditPoint << endl;
    cout << "City: " << user.city << endl;
    cout << "\n";    
}

//Make change parameter -> vector
void Admin::viewMotorbikeInfo(Motorbike motorbike)
{
    //model, motorbikeID, color, engineSize, city, owner, transmissionMode, yearMade , description, consumingPoints, rentalAmount, motorbikeRating, requests, availability
    cout << "\nMotorbike information:\n";
    cout << "Model: " << motorbike.model << endl;
    cout << "Motorbike ID: " << motorbike.motorbikeID << endl;
    cout << "Color: " << motorbike.color << endl; 
    cout << "Engine size: " << motorbike.engineSize << endl;
    cout << "City: " << motorbike.city << endl;
    cout << "Owner ID: << motorbike.owner.userID << endl;
    cout << "Transmission mode: " << motorbike.transmissionMode << endl;
    cout << "Year made: " << motorbike.yearMade << endl;
    cout << "Description: " << motorbike.description << endl;
    cout << "Consuming points: " << motorbike.consumingPoints << endl;
    cout << "Rental amount: " << motorbike.rentalAmount << endl;
    cout << "Rating: " << motorbike.motorbikeRating << endl;
    cout << "Availability: " << motorbike.availability << endl;
}

//View a specific account (Might change parameter -> vector)
void Admin::viewAccounts(Account account)
{
    //username, password, fullName, phoneNumber
    cout << "\nAccount information:\n";
    cout << "Username: " << account.getUsername() << endl;
    cout << "Password: " << account.getPassword() << endl;
    cout << "Full name: " << account.getFullName() << endl;
    cout << "Phone number: " << account.getPhoneNumber() << endl;
    cout << "\n";
}

string Admin::getAdminID() const
{
    return adminID;
}

void Admin::setAdminID(string adminID)
{
    this->adminID = adminID;
}
