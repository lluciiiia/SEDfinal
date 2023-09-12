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

// Make change parameter -> vector
void Admin::viewMotorbikeInfo(Motorbike motorbike)
{
    // model, motorbikeID, color, engineSize, city, owner, transmissionMode, yearMade , description, consumingPoints, rentalAmount, motorbikeRating, requests, availability
    
    // those attributes are private cannot access directly like that
    
    // cout << "\nMotorbike information:\n";
    // cout << "Model: " << motorbike.getMode() << endl;
    // cout << "Motorbike ID: " << motorbike.getMotorbikeId() << endl;
    // cout << "Color: " << motorbike. << endl;
    // cout << "Engine size: " << motorbike.engineSize << endl;
    // cout << "City: " << __STRINGIFY(motorbike.city) << endl;
    // cout << "Owner name: " << motorbike.owner << endl;
    // cout << "Transmission mode: " << motorbike.transmissionMode << endl;
    // cout << "Year made: " << motorbike.yearMade << endl;
    // cout << "Description: " << motorbike.description << endl;
    // cout << "Consuming points: " << motorbike.consumingPoints << endl;
    // cout << "Rental amount: " << motorbike.rentalAmount << endl;
    // cout << "Rating: " << motorbike.motorbikeRating << endl;
    // cout << "Availability: " << motorbike.getAvailability()<< endl;
}

// View a specific account (Might change parameter -> vector)
void Admin::viewAccounts(Account account)
{
    // username, password, fullName, phoneNumber
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

bool adminLogin() {
	//Temporary admin user and pass
	string providedAdminUsername = "admin"; 
	string providedAdminPass = "admin";
	string username; 
	string pass;
	bool usernameFlag = false;
	bool passFlag = false;
while (!usernameFlag) {
	cout << "Enter admin username: ";
	getline(cin, username);

	if (username.empty()) 
	{
		cout << "Username cannot be empty!\n";
	}
	else
		{
		if (username.compare(providedUsername) == 0) 
		{
		usernameFlag = true;
		break;
		}
	}

while (!passwordFlag) {
	cout << "Enter admin password: ";
	getline(cin, pass);
		if (pass.compare(providedPass) == 0)
		{
		//Not sure about this so i comment it out for now
		//admin = Admin( username, pass, admin.getFullName(), admin.getPhoneNumber(), admin.getAdminID() ); 
		//load admin dashboard (will see how)
		passFlag = true;
		break;
		} 
		else 
		{
			cout << "Incorrect password!\n";
		}
	}
}
	system("cls");
	if (usernameFlag == true && passFlag == true)
	{
		return true;
	}

	return false;
}
