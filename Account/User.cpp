#include <iostream>
#include <vector>
#include <regex>

#include "Account.h"
#include "../Rating.h"
#include "User.h"
#include "../Motorbike.h"
#include "../Request.h"
#include "../RequestStatus.h"
#include <cstdlib>
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


string User::getUserName()
{
    return Account:: getUsername();
}
string User::getIdType()
{
    return this->IDtype;
}

string User::getIdNum()
{
    return this->idNum;
}

string User::getLicenseNum()
{
    return this->licenseNumber;
}

string User::getExDate()
{
    return this->licenseExpiryDate;
}

double User::getCreditPoint()
{
    return this->creditPoint;
}

City User::getCity()
{
    return this->city;
}

bool login(User &cus, vector<User> &userList)
{
    string username;
    string pass;
    bool usernameFlag= false;
    bool passFlag= false;
    while (!usernameFlag) {
        cout << "Enter your username: ";
        getline(cin, username);

        if (username.empty()) {
            cout << "Username cannot be empty! \n";
        } else {
            for (auto &user : userList)
            {
                if (user.getUserName() == username )
                {
                    usernameFlag= true;
                    break;
                }
            }
        }
    }
    cout<< "Enter your password: ";
    getline(cin,pass);
        for (auto &user : userList)
            {
                if ( user.getPassword() == pass)
                    {
                        cus= User(username,pass,user.getFullName(),
                        user.getPhoneNumber(),
                        user.getIdType(),
                        user.getIdNum(),
                        user.getLicenseNum(),
                        user.getExDate(),
                        user.getCreditPoint(),
                        user.getCity());
                        passFlag= true;
                        break;
                    }
            }
    system("cls");
    if(usernameFlag== true && passFlag== true){
        return true;
    } 
    
    return false;
   
}


 bool User::registerAccount(vector <User>& userList)
{
    system("cls");
    string username, password, fullname, phoneNumber, idtype, idnum, licenseNum, licenseExdate;
    double creditpoint;
    bool flag=true;
    cout<< "Starting to register. \n";

    while (true) {
        cout << "Enter your username: ";
        getline(cin, username);

        if (username.empty()) {
            cout << "Username cannot be empty! \n";
        } else {
            bool usernameExists = false;

            for ( auto& user : userList) {
                if (username == user.getUserName()) {
                    usernameExists = true;
                    break; 
                }
            }

            if (usernameExists) {
                cout << "Sorry! Username already exists! Please use another one! \n";
            } else {
                break;
            }
        }
    }

    while(true){
        cout<< "Enter your password: ";
        getline(cin, password);
        if(password.empty()){
            cout<< "Password cannot be empty! \n";
        }else{
            break;
        }
    }

    while(true){
        cout<< "Enter your full name: \n";
        getline(cin, fullname);
        if(fullname.empty()){
            cout<< "Full name cannot be empty! \n";
        }else{
            break;
        }
    }

    while(true){
        cout<< "Enter your phone number: \n";
        getline(cin, phoneNumber);
        if(phoneNumber.empty()){
            cout<< "Phone Number cannot be empty! \n";
        }else{
            break;

        }
    }

    int choice;
    while(true){
        cout<< "Enter your ID type: \n";
        cout<< "Enter 1: Citizen ID \n";
        cout<< "Enter 2: Passport\n";
        cin>> choice;
        cin.ignore();
        string choiceString= to_string(choice);
        if(choiceString.empty()){
            cout<< "Its cannot be empty! \n";
        }else{
            if(choice == 1 ){
                idtype = "Citizen ID";
                break;
            }else if( choice == 2){
                idtype = "Passport";
                break;
            }else{
                cout<< "Invalid input !\n";
            }
        }
    }

    if(choice == 1){
        while(true){
            cout<< "Enter citizen ID: ";
            getline(cin, idnum);
            if(idnum.empty()){
                cout<< "Id num cannot be empty!! \n";
            }else{
                break;
            }
        }
    }else if(choice == 2){
        while(true){
            cout<< "Enter passport: ";
            getline(cin, idnum);
            if(idnum.empty()){
                cout<< "Id num cannot be empty!! \n";
            }else{
                break;
            }
        }
    }

    while(true){
        cout<< "Enter your expiry date: \n";
        getline(cin, licenseExdate);
        if(licenseExdate.empty()){
            cout<< "License Expiry Date cannot be empty! \n";
        }else{
            break;
        }
    }

    while(true){
        cout<< "Enter your license number: \n";
        getline(cin, licenseNum);
        if(licenseNum.empty()){
            cout<< "License Number cannot be empty! \n";
        }else{
            break;
        }
    }

    regex regexp("^(-?)(0|([1-9][0-9]*))(\\.[0-9]+)?$");
    bool addSuccess=false;
    while(true){
        cout<< "In order to register, you need to add to your balance (At least 20$ for first register)\n";
        cout<< "Please enter the money you want to add: ";
        cin>> creditpoint;
        cin.ignore();
        string creditToString = to_string(creditpoint);
        if(!regex_match(creditToString, regexp)){
            cout<< "Invalid input! Please input the right amount of money!\n ";
        }else{
            if(creditpoint >= 20){
                cout<<"Register successfully! You can now log in to the program\n";
                addSuccess = true;
                break;
            }else{
                char decision;
                cout<< "You can only add at least 20$ to sign up for the first time! \n";
                cout<< "Continue? (Y/N)";
                cin>> decision;
                cin.ignore();
                if(decision == 'Y' || decision == 'y'){
                    cout<< "Please do as the instruction\n";
                }else if(decision == 'N' || decision == 'n'){
                    cout<< "Thank you for your time! See you again! \n";
                    break;
                }
            }
        }
    }

    City city = City::Hanoi;

    if(addSuccess){
        User user23(username, password, fullname, phoneNumber, idtype, idnum, licenseNum, licenseExdate, creditpoint, city);
        userList.push_back(user23);
        return true;
    }

    return false;
}

// listMotorbike()
// unlistMotorbike()
void User::searchAvailableMotorbikes(){};

// void User::requestToRent(Motorbike &motorbike, TimeSlot timeSlot)
// {
//     Request request(this, &motorbike, timeSlot);
//     motorbike.addRequest(request);
// }

void User::viewRequests(){};

// void User::acceptRequest(vector<Request> &requests, Request request){
//     // 1. change the request status to Accepted
//     request.setStatus(RequestStatus::ACCEPTED);

//     // 2. change the availability of the motorbike
//     // Motorbike* motorbikeToRequest = request.getMotorbike();
//     // motorbikeToRequest->setAvailability(false);

//     // 3. payment from the requester
    
//     // 4. increase the credits ($1 = 1 credit point) for both requester and the owner

// };
void User::rateUser(){};
void User::rateMotorbike(){}


// listMotorbike()
// unlistMotorbike()


// void User::requestToRent(Motorbike &motorbike, TimeSlot timeSlot)
// {
//     // Request request(this, &motorbike, timeSlot);
//     //motorbike.addRequest(request);
// }

// void User::viewRequests(){};

// void User::acceptRequest(vector<Request> &requests, Request request){
//     // 1. change the request status to Accepted
//    request.setStatus(RequestStatus::ACCEPTED);

//   // 2. change the availability of the motorbike
// //   Motorbike* motorbikeToRequest = request.getMotorbike();
// // motorbikeToRequest->setAvailability(false);

// // 3. payment from the requester
    
// // 4. increase the credits ($1 = 1 credit point) for both requester and the owner

// };


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


