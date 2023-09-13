#include "Admin.h"
#include <iostream>
#include <cstdlib>
#include <iomanip>

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

// Might change parameter -> vector
void Admin::viewMemberInfo(User user)
{
    // Print userID, IDtype, licenseNumber, licenseExpiryDate, creditPoits, city
    //(Might add motorbike, motorbikeRatings and userRatings if necessary)
    cout << "\nMember information:\n";
    cout << "User name: " << user.getUserName() << endl;
    cout << "ID Type: " << user.IDtype << endl;
    cout << "License Number: " << user.licenseNumber << endl;
    cout << "License Expiry Date: " << user.licenseExpiryDate << endl;
    cout << "Credit points: " << user.creditPoint << endl;
    cout << "City: " << __STRINGIFY(user.city) << endl;
    cout << "\n";
}


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

    cout << setfill('-') << setw(170) << "-" << setfill(' ') << endl;

    for (User &user : users)
    {
        string city = cityToString(user.getCity());
        vector<Motorbike> motorbikes = user.getOwnedMotorbike();
        string motorbikeModel = "";
        if (motorbikes.size() > 0) {
            motorbikeModel = motorbikes[0].getModel();
        };
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

string Admin::getAdminID() const
{
    return adminID;
}

void Admin::setAdminID(string adminID)
{
    this->adminID = adminID;
}

bool Admin::adminLogin() {
	//Temporary admin user and pass
	string providedAdminUsername = "admin"; 
	string providedAdminPass = "admin";
	//What the user enters
	string username; 
	string pass;
	bool usernameFlag = false;
	bool passFlag = false;

//Check username
while (!usernameFlag) {
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

//Check password
while (!passFlag) {
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
