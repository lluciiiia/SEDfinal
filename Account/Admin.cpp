#include "Admin.h"
#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

Admin::Admin()
    : Account("", "", "", "") {}

Admin::Admin(string username,
             string password,
             string fullName,
             string phoneNumber,
             string adminID)
    : Account(username, password, fullName, phoneNumber), adminID(adminID)
{
    this->adminID = adminID;
}

// Getter
string Admin::getAdminID() const
{
    return adminID;
}

// Setter
void Admin::setAdminID(string adminID)
{
    this->adminID = adminID;
}

// Dash board for admins to view all the bikes' information
void Admin::viewMotorbikeInfo(vector<Motorbike> &bikes)
{
    cout << left << setw(12) << "Motorbike ID" << setw(20) << "Model" << setw(10) << "Color" << setw(10) << "Engine" << setw(15) << "Owner" << setw(12) << "Year" << setw(20) << "Description" << setw(8) << "Rating" << setw(8) << "City" << endl;
    cout << setfill('-') << setw(150) << "-" << setfill(' ') << endl;
    for (Motorbike &bike : bikes)
    {
        string cityStr = cityToString(bike.getCity());
        cout << left << setw(12) << bike.getMotorbikeId()
             << setw(20) << bike.getModel()
             << setw(10) << bike.getColor()
             << setw(10) << bike.getEngine()
             << setw(15) << bike.getOwner()
             << setw(12) << bike.getYear()
             << setw(20) << bike.getDes()
             << setw(8) << bike.getRating()
             << setw(8) << cityStr
             << endl;
    }
}

// Dash board for admins to view all the members' information
void Admin::viewAccounts(vector<User> &users)
{
    cout << left << setw(30) << "User name"
         << setw(20) << "Full name"
         << setw(15) << "Phone number"
         << setw(20) << "Id type"
         << setw(15) << "Id number"
         << setw(15) << "License number"
         << setw(25) << "License expiry date"
         << setw(25) << "Credit points"
         << setw(15) << "City"
         << setw(15) << "Owned motorbike" << endl;

    cout << setfill('-') << setw(200) << "-" << setfill(' ') << endl;

    for (User &user : users)
    {
        string city = cityToString(user.getCity());
        vector<Motorbike> motorbikes = user.getOwned();
        string motorbikeModel = "";

        int count = 0;
        for (auto &bike : motorbikes)
        {
            if (count > 0)
            {
                motorbikeModel += ", ";
            }
            motorbikeModel += bike.getModel();
            count++;
        }

        cout << left << setw(30) << user.getUserName()
             << setw(20) << user.getFullName()
             << setw(15) << user.getPhoneNumber()
             << setw(20) << user.getIdType()
             << setw(15) << user.getIdNum()
             << setw(15) << user.getLicenseNum()
             << setw(25) << user.getExDate()
             << setw(20) << user.getCreditPoint()
             << setw(15) << city
             << setw(15) << motorbikeModel
             << endl;
    }
}

// Method for admins to log in
bool Admin::adminLogin()
{
    // Temporary admin user and pass
    string providedAdminUsername = "admin";
    string providedAdminPass = "admin";
    // What the user enters
    string username;
    string pass;
    bool usernameFlag = false;
    bool passFlag = false;

    // Check username
    while (!usernameFlag)
    {
        cout << "Enter admin username: ";
        getline(cin, username);

        if (username.empty())
        {
            cout << "Username cannot be empty!\n";
        }
        else
        {
            if (username.compare(providedAdminUsername) == 0)
            {
                usernameFlag = true;
                break;
            }
        }
    }

    // Check password
    while (!passFlag)
    {
        cout << "Enter admin password: ";
        getline(cin, pass);
        if (pass.compare(providedAdminPass) == 0)
        {
            passFlag = true;
            break;
        }
        else
        {
            cout << "Incorrect password!\n";
        }
    }
    system("cls");
    if (usernameFlag == true && passFlag == true)
    {
        return true;
    }
    return false;
}
