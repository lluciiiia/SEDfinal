#include <iostream>
#include <vector>
#include <regex>
#include <iomanip>
#include <ctime>
#include <chrono>
#include <cstdlib>
#include "User.h"
class UserRating;
class MotorbikeRating;
class savingToFile;

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
           double creditPoint, vector<Motorbike> own,
           vector<Request> sentRequests) : Account(username,
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
    this->OwnedMotorbikes = own;
    this->sentRequests = sentRequests;
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
           City city, vector<Motorbike> owm) : Account(username,
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
    this->OwnedMotorbikes = owm;
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
    string cityStr = cityToString(city);
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

// Getters
string User::getUserName()
{
    return Account::getUsername();
}

string User::getIdType()
{
    return this->IDtype;
}

string User::getIdNum()
{
    return this->idNum;
}

double User::getRating()
{
    if (userRatings.size() == 0)
    {
        return 0.0;
    }
    double average = 0;
    double total = 0;
    for (auto rating : userRatings)
    {
        total += rating.getScore();
    }
    average = total / userRatings.size();
    return average;
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

vector<Request> &User::getSentRequests()
{
    return this->sentRequests;
}

vector<Motorbike> &User::getRentingBikes()
{
    return RentingBikes;
}

vector<UserRating> &User::getRatings()
{
    return this->userRatings;
};

vector<Motorbike> &User::getOwned()
{
    return this->OwnedMotorbikes;
}

// Setter
void User::setCreditPoint(double credit)
{
    this->creditPoint = credit;
}

void User::setOwnedBikes(vector<Motorbike> &bikes)
{
    this->OwnedMotorbikes = bikes;
}

void User::setUserRating(vector<UserRating> &ratings)
{
    this->userRatings = ratings;
}

void User::setSentRequest(vector<Request> &requsest)
{
    this->sentRequests = requsest;
}

// Method to list their bikes on the market
void User::listBike(Motorbike *bike, Motorbike *bike2, bool &taken)
{
    system("cls");
    char choice;
    cout << "The bike's available start date: " << bike->getAvailableTimeSlot().getStartTime() << "\n";
    cout << "The bikes's available end date: " << bike->getAvailableTimeSlot().getEndTime() << "\n";
    if (bike2->getAvailability())
    {
        cout << "Your bike is on the market. \n";
    }
    else
    {
        cout << "Your bike is not on the market. \n";
    }
    // cout<<"Availability changed to: " << (bike2->getAvailability() ? "On the market" : "Not on the market") << endl;
    bool dashborad = false;
    while (!dashborad)
    {

        if (bike2->getAvailability())
        {
            cout << "1. Unlist your bike on the market.\n";
        }
        else
        {
            cout << "1. List your motorbike on the market. \n";
        }
        cout << "2. Enter new time slot for the bike. \n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case '1':
            if (taken)
            {
                cout << "Bike is being rented by other user. Cannot change avaiability right now! \n";
            }
            else
            {
                bike->setAvailability(!bike->getAvailability());
                bike2->setAvailability(!bike2->getAvailability());
                // cout<<"Availability changed to: " << (bike2->getAvailability() ? "On the market" : "Not on the market") << endl;
                // cout << "Availability changed to: " << (bike->getAvailability() ? "On the market" : "Not on the market") << endl;
            }
            break;
        case '2':
        {
            TimeSlot availableTimeSlot;
            while (true)
            {
                // Make sure dates follow format (dd/mm)
                static const std::regex dateRegex("^(0[1-9]|[1-2][0-9]|3[0-1])/(0[1-9]|1[0-2])$");
                string startTime = "", endTime = "";
                cout << "Enter new start time for the motorbike (dd/mm): ";
                cin >> startTime;
                cin.ignore();
                if (!regex_match(startTime, dateRegex))
                {
                    cout << "Start time is in the wrong format! Please try again.\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    continue;
                }

                cout << "Enter new end time for the motorbike (dd/mm): ";
                cin >> endTime;
                if (!regex_match(endTime, dateRegex))
                {
                    cout << "End time is in the wrong format! Please try again.\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    continue;
                }

                availableTimeSlot = TimeSlot(startTime, endTime);
                bike->setAvailableTimeSlot(availableTimeSlot);
                bike2->setAvailableTimeSlot(availableTimeSlot);
                break;
            }
            break;
        }

        case '3':
            dashborad = true;
            break;
        }
    }
}

// Method to add their bike
bool User::addBike(vector<Motorbike> &bikes)
{

    if (this->OwnedMotorbikes.size() == 1)
    {
        cout << "You can own only one bike." << endl;
        return false;
    }

    regex regexp("^(-?)(0|([1-9][0-9]*))(\\.[0-9]+)?$");
    string model, color, enginSize, transmissionmode;
    string description = "";
    int yearMade;
    TimeSlot availableTimeSlot;
    cout << "Please enter all of needed informations: \n";
    // Model
    while (true)
    {
        cout << "Enter your model: ";
        getline(cin, model);
        if (model.empty())
        {
            cout << "Model cannot be empty! \n";
        }
        else
        {
            break;
        }
    }
    // Color
    while (true)
    {
        cout << "Enter your color: ";
        getline(cin, color);
        if (color.empty())
        {
            cout << "Color cannot be empty! \n";
        }
        else
        {
            break;
        }
    }
    // Engine size (Can only be integers. Example: 50 or 175)
    static const std::regex engineSizeRegex("^[1-9]\\d*$");
    while (true)
    {
        cout << "Enter your engine size(eg.100,200): ";
        getline(cin, enginSize);
        if (enginSize.empty())
        {
            cout << "Engine size cannot be empty! \n";
        }
        else if (!regex_match(enginSize, engineSizeRegex))
        {
            cout << "Invalid engine size, engine sizes must be a positive integer.\n";
        }
        else
        {
            break;
        }
    }
    // Year made (Must be a valid year, be int only, have max 4 digits)
    static const std::regex yearMadeRegex("^[0-9]{4}$");
    while (true)
    {
        cout << "Enter year made: ";
        cin >> yearMade;
        cin.ignore();
        string num = to_string(yearMade);
        if (!regex_match(num, yearMadeRegex))
        {
            cout << "Invalid input for year made! Please enter agian. ";
        }
        else
        {
            break;
        }
    }
    // Transmission mode
    while (true)
    {
        cout << "Enter your transmission mode: ";
        getline(cin, transmissionmode);
        if (transmissionmode.empty())
        {
            cout << "Transmission mode cannot be empty! \n";
            continue;
        }
        else
        {
            break;
        }
    }
    // Motorbike Description (Max: 150 words)
    cout << "Add some description for the bike: ";
    getline(cin, description);
    std::string cityStr;
    City selectedCity;
    // City
    while (true)
    {
        std::cout << "Enter your city (Saigon or Hanoi): ";
        std::cin >> cityStr;

        selectedCity = stringToCity(cityStr);

        if (selectedCity != static_cast<City>(-1))
        {
            break;
        }

        std::cout << "Invalid city. Please enter Saigon or Hanoi.\n";
    }

    int consumingPoints;
    // Bike price
    while (true)
    {
        cout << "Enter the price for the bike: ";
        cin >> consumingPoints;
        cin.ignore();
        string num = to_string(consumingPoints);
        if (!regex_match(num, regexp))
        {
            cout << "Invalid input for price! Please enter agian. ";
        }
        else
        {
            break;
        }
    }
    // Rating
    int minRate;
    while (true)
    {
        cout << "Enter the minimum ratings for renters: ";
        cin >> minRate;
        cin.ignore();
        string num = to_string(minRate);
        if (!regex_match(num, regexp))
        {
            cout << "Invalid input for ratings! Please enter again. ";
        }
        else
        {
            break;
        }
    }

    // Available TimeSlot
    while (true)
    {
        // Make sure dates follow format (dd/mm)
        static const std::regex dateRegex("^(0[1-9]|[1-2][0-9]|3[0-1])/(0[1-9]|1[0-2])$");
        string startTime = "", endTime = "";
        cout << "Enter start time for bike rental period in the format (dd/mm): ";
        cin >> startTime;
        cin.ignore();
        if (!regex_match(startTime, dateRegex))
        {
            cout << "Start time is in the wrong format! Please try again.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        cout << "Enter end time for bike rental period in the format (dd/mm): ";
        cin >> endTime;
        if (!regex_match(endTime, dateRegex))
        {
            cout << "End time is in the wrong format! Please try again.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        availableTimeSlot = TimeSlot(startTime, endTime);
        break;
    }
    // checking for the id
    int motorbikeID = bikes.size() + 1;
    bool uniqueIDFound = false;

    while (!uniqueIDFound)
    {
        // Check if motorbikeID already exists in the bikes vector
        bool found = false;
        for (auto &moto : bikes)
        {
            if (motorbikeID == moto.getMotorbikeId())
            {
                found = true;
                break;
            }
        }

        if (!found)
        {
            uniqueIDFound = true;
        }
        else
        {
            motorbikeID++;
        }
    }
    Motorbike motor(model, motorbikeID,
                    color, enginSize,
                    selectedCity,
                    Account::getUsername(),
                    transmissionmode,
                    yearMade,
                    description, consumingPoints, 0, minRate, true, availableTimeSlot);
    bikes.push_back(motor);
    OwnedMotorbikes.push_back(motor);
    return true;
}

// Method to view their owned bikes
void User::viewOwnedBike(vector<Motorbike> &bikes, vector<Borrow> &borrow, vector<UserRating> &ratings)
{
    Motorbike *temp;
    Motorbike *temp2;
    bool taken = false;
    system("cls");
    int id;
    if (!this->OwnedMotorbikes.empty())
    {
        for (int i = 0; i < 1; i++)
        {
            id = this->OwnedMotorbikes[i].getMotorbikeId();
            temp = &OwnedMotorbikes[i];
        }
    }
    else
    {
        cout << "You have not pocess any bike yet. \n";
    }

    for (auto &b : bikes)
    {
        if (id == b.getMotorbikeId())
        {
            temp2 = &b;
            break;
        }
    }
    for (auto &bo : borrow)
    {
        if (id == bo.getMotorbikeID() && bo.getBorrowSta() == "RENTING")
        {
            taken = true;
            break;
        }
    }
    string idToRemove;
    cout << left << setw(12) << "Motorbike ID" << setw(20) << "Model" << setw(10) << "Color" << setw(10) << "Engine" << setw(15) << "Owner" << setw(12) << "Year" << setw(20) << "Description" << setw(8) << "Rating" << setw(8) << "City" << endl;
    cout << setfill('-') << setw(150) << "-" << setfill(' ') << endl;
    for (auto &bike : this->OwnedMotorbikes)
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
    cout << "You can only add only one bike. \n\n";
    while (true)
    {

        cout << "Welcome to your bike's information\n";
        cout << "1.Add a bike \n";
        cout << "2.Delete your bike \n";
        cout << "3.List your bike or change available date. \n";
        cout << "4.Rate the renter of your bike. \n";
        cout << "5.Exit\n";
        cout << "\nEnter your choice: ";
        getline(cin, idToRemove);

        if (idToRemove == "1")
        {
            system("cls");
            this->addBike(bikes);
            cin.ignore();
        }
        else if (idToRemove == "2")
        {
            int bikeId;
            if (!this->OwnedMotorbikes.empty())
            {
                for (int i = 0; i < 1; i++)
                {
                    bikeId = this->OwnedMotorbikes[i].getMotorbikeId();
                }
            }
            else
            {
                cout << "You have not owned any motorbike to remove! \n";
            }
            for (int i = 0; i < bikes.size(); i++)
            {
                if (bikes[i].getMotorbikeId() == bikeId)
                {
                    // Remove the bike from the vector
                    bikes.erase(bikes.begin() + i);
                    cout << "Remove bike successfully!\n";
                    OwnedMotorbikes.clear();

                    // TODO: update the bikes so the user can see the updated list
                }
                else
                {
                    cout << "You have no bike to remove. ";
                }
            }
        }
        else if (idToRemove == "3")
        {
            this->listBike(temp, temp2, taken);
        }
        else if (idToRemove == "4")
        {
            cout << "Borrowing history: \n";
            for (int i = 0; i < borrow.size(); i++)
            {
                if (borrow[i].getMotorbikeID() == id && borrow[i].getBorrowSta() == "RENTED")
                {
                    cout << "Renter: " << borrow[i].getUsername() << "\n";
                    cout << "Total amount: " << borrow[i].getPrice() << '\n';
                    string username;

                    while (true)
                    {
                        cout << "Enter name of the renter to rate them: ";
                        getline(cin, username);

                        if (username == borrow[i].getUsername())
                        {
                            float score;
                            string comment;

                            cout << "Enter score for the renter: ";

                            while (!(cin >> score))
                            {
                                cin.clear();
                                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                cout << "Invalid input. Enter a valid score: ";
                            }

                            cin.ignore();

                            cout << "Do you have any comments for the previous renter: ";
                            cin.ignore(); // Clear newline character
                            getline(cin, comment);

                            UserRating urating(username, score, comment);
                            ratings.push_back(urating);
                            borrow.erase(borrow.begin() + i);
                            break;
                        }
                        else
                        {
                            cout << "Renter not found in the borrowing history. Try again." << endl;
                        }
                    }
                }
            }
        }
        else if (idToRemove == "5")
        {
            break;
        }
        else
        {
            cout << "Invalid input. Please try again! \n";
        }
    }
};

// Dash board for users to register a new account
bool User::registerAccount(vector<User> &userList)
{
    system("cls");
    string username, password, fullname, phoneNumber, idtype, idnum, licenseNum, licenseExdate;
    double creditpoint;
    bool flag = true;
    cout << "Starting to register. \n";

    while (true)
    {
        cout << "Enter your username: ";
        getline(cin, username);

        if (username.empty())
        {
            cout << "Username cannot be empty! \n";
        }
        else
        {
            bool usernameExists = false;

            for (auto &user : userList)
            {
                if (username == user.getUserName())
                {
                    usernameExists = true;
                    break;
                }
            }

            if (usernameExists)
            {
                cout << "Sorry! Username already exists! Please use another one! \n";
            }
            else
            {
                break;
            }
        }
    }

    while (true)
    {
        cout << "Enter your password: ";
        getline(cin, password);
        if (password.empty())
        {
            cout << "Password cannot be empty! \n";
        }
        else
        {
            break;
        }
    }

    while (true)
    {
        cout << "Enter your full name: \n";
        getline(cin, fullname);
        if (fullname.empty())
        {
            cout << "Full name cannot be empty! \n";
        }
        else
        {
            break;
        }
    }

    while (true)
    {
        cout << "Enter your phone number: \n";
        getline(cin, phoneNumber);
        if (phoneNumber.empty())
        {
            cout << "Phone Number cannot be empty! \n";
        }
        else
        {
            break;
        }
    }

    int choice;
    while (true)
    {
        cout << "Enter your ID type: \n";
        cout << "Enter 1: Citizen ID \n";
        cout << "Enter 2: Passport\n";
        cin >> choice;
        cin.ignore();
        string choiceString = to_string(choice);
        if (choiceString.empty())
        {
            cout << "Its cannot be empty! \n";
        }
        else
        {
            if (choice == 1)
            {
                idtype = "Citizen ID";
                break;
            }
            else if (choice == 2)
            {
                idtype = "Passport";
                break;
            }
            else
            {
                cout << "Invalid input !\n";
            }
        }
    }

    if (choice == 1)
    {
        while (true)
        {
            cout << "Enter citizen ID: ";
            getline(cin, idnum);
            if (idnum.empty())
            {
                cout << "Id num cannot be empty!! \n";
            }
            else
            {
                break;
            }
        }
    }
    else if (choice == 2)
    {
        while (true)
        {
            cout << "Enter passport: ";
            getline(cin, idnum);
            if (idnum.empty())
            {
                cout << "Id num cannot be empty!! \n";
            }
            else
            {
                break;
            }
        }
    }

    while (true)
    {
        cout << "Enter your expiry date: \n";
        getline(cin, licenseExdate);
        if (licenseExdate.empty())
        {
            cout << "License Expiry Date cannot be empty! \n";
        }
        else
        {
            break;
        }
    }

    while (true)
    {
        cout << "Enter your license number: \n";
        getline(cin, licenseNum);
        if (licenseNum.empty())
        {
            cout << "License Number cannot be empty! \n";
        }
        else
        {
            break;
        }
    }
    std::string cityStr;
    City selectedCity;

    while (true)
    {
        std::cout << "Enter your city (Saigon or Hanoi): ";
        std::cin >> cityStr;

        selectedCity = stringToCity(cityStr);

        if (selectedCity != static_cast<City>(-1))
        {
            break;
        }

        std::cout << "Invalid city. Please enter Saigon or Hanoi.\n";
    }

    regex regexp("^(-?)(0|([1-9][0-9]*))(\\.[0-9]+)?$");
    bool addSuccess = false;
    while (true)
    {
        cout << "In order to register, you need to add to your balance (At least 20$ for first register)\n";
        cout << "Please enter the money you want to add: ";
        cin >> creditpoint;
        cin.ignore();
        string creditToString = to_string(creditpoint);
        if (!regex_match(creditToString, regexp))
        {
            cout << "Invalid input! Please input the right amount of money!\n ";
        }
        else
        {
            if (creditpoint >= 20)
            {
                cout << "Register successfully! You can now log in to the program\n";
                addSuccess = true;
                break;
            }
            else
            {
                char decision;
                cout << "You can only add at least 20$ to sign up for the first time! \n";
                cout << "Continue? (Y/N)";
                cin >> decision;
                cin.ignore();
                if (decision == 'Y' || decision == 'y')
                {
                    cout << "Please do as the instruction\n";
                }
                else if (decision == 'N' || decision == 'n')
                {
                    cout << "Thank you for your time! See you again! \n";
                    break;
                }
            }
        }
    }

    if (addSuccess)
    {
        User user23(username, password, fullname, phoneNumber, idtype, idnum, licenseNum, licenseExdate, creditpoint, selectedCity);
        userList.push_back(user23);
        return true;
    }

    return false;
}

// Method for users to rate bikes
void User::rateBike(Motorbike *ratedMotorbike, vector<MotorbikeRating> &ratings)
{
    float motorbikeScore = 0;
    string motorbikeComment = "";

    // Define a regex pattern for a valid float score (e.g., 0.0 to 10.0)
    static const std::regex scoreRegex("^([0-9](\\.[0-9])?|10(\\.0)?)$");

    while (true)
    {
        cout << "Enter score for motorbike (0.0 to 10.0): ";
        string input;
        getline(cin, input);

        if (!regex_match(input, scoreRegex))
        {
            cout << "Invalid input for score! Please enter a valid score between 0.0 and 10.0.\n";
            continue;
        }

        motorbikeScore = stof(input);
        break;
    }

    cout << "Enter comment for motorbike " << ratedMotorbike->getMotorbikeId() << ": ";
    getline(cin, motorbikeComment);
    cout << endl;

    MotorbikeRating motorbikeRate(ratedMotorbike->getMotorbikeId(), motorbikeScore, motorbikeComment);
    ratedMotorbike->getRatings().push_back(motorbikeRate);
    ratings.push_back(motorbikeRate);
}

// Method for owners to rate their renters
void User::rateRenter(User &ratedUser)
{
    // Variables for score and comment
    float userScore = 0;
    string userComment = "";

    // Rate user
    cout << "Enter score for user: ";
    cin >> userScore;
    cin.ignore();
    cout << "Enter comment for user: ";
    getline(cin, userComment);
    cout << endl;

    // Adding rating to list
    UserRating userRate(ratedUser.getUserName(), userScore, userComment);
    ratedUser.userRatings.push_back(userRate);
}

// Method for members to send a request to the owner of the bike
void User::requestToRent(vector<Motorbike> &bikes, vector<Request> &requests)
{
    system("cls");
    cout << "--------------------\n";
    cout << "----Renting bikes---\n";
    cout << "Here are some available bikes that fit you. \n";
    time_t now = time(0);
    int thisid;
    tm *ltm = localtime(&now);
    if (!OwnedMotorbikes.empty())
    {
        thisid = OwnedMotorbikes[0].getMotorbikeId();
    }
    else
    {
        thisid = 0;
    }
    string day = to_string(ltm->tm_mday);
    string month = to_string(1 + ltm->tm_mon);
    if (day.length() == 1)
    {
        day = "0" + day;
    }
    if (month.length() == 1)
    {
        month = "0" + month;
    }
    string dayAndMon = day + "/" + month;
    bool found = false;
    for (Motorbike &bike : bikes)
    {
        if (bike.getAvailability() == true && this->creditPoint >= bike.getConsumingPoints() && this->city == bike.getCity() && bike.getMotorbikeId() != thisid)
        {
            cout << left << setw(12) << bike.getMotorbikeId()
                 << setw(20) << bike.getModel()
                 << setw(10) << bike.getColor()
                 << setw(10) << bike.getEngine()
                 << setw(15) << bike.getYear()
                 << setw(12) << bike.getConsumingPoints()
                 << setw(20) << bike.getDes()
                 << setw(8) << bike.getRating()
                 << endl;
            found = true;
        }
    }
    if (!found)
    {
        cout << "There is no motorbike that is currently fit you. Sorry please come back later.\n\n";
    }
    regex regexp("^(-?)(0|([1-9][0-9]*))(\\.[0-9]+)?$");
    while (true)
    {
        bool twice = false;
        bool already = false;
        string input;
        cout << "Enter the bike id you want to rent (Q to quit): ";
        getline(cin, input);

        if (input == "q" || input == "Q")
        {
            break;
        }
        else if (!regex_match(input, regexp))
        {
            cout << "Invalid input. Please provide another input! \n";
        }
        else
        {
            for (auto &v : requests)
            {
                if (v.getMotorbikeID() == stoi(input) && this->getUsername() == v.getRequester() && v.getStatus() == RequestStatus::PENDING)
                {
                    twice = true;
                }
                if (v.getMotorbikeID() == stoi(input) && this->getUsername() == v.getRequester() && v.getStatus() == RequestStatus::ACCEPTED)
                {
                    already = true;
                }
            }
            bool quit = false;
            while (!quit)
            {
                bool bikeExists = false;
                for (Motorbike &bike : bikes)
                {
                    if (bike.getAvailability() == true && this->creditPoint >= bike.getConsumingPoints() && this->city == bike.getCity())
                    {
                        if (bike.getMotorbikeId() == stoi(input))
                        {
                            bikeExists = true;
                            string days;
                            cout << "How many days you want to rent the bike? (Q to quit): ";
                            getline(cin, days);

                            if (days == "q" || days == "Q")
                            {
                                quit = true;
                                break;
                            }

                            if (this->creditPoint < bike.getConsumingPoints() * stoi(days))
                            {
                                cout << "You don't have enough credit points to rent! Please lower your days or quit\n";
                            }
                            else if (!regex_match(days, regexp) || stoi(days) <= 0)
                            {
                                cout << "Invalid input! Please provide a valid day!\n";
                            }
                            else if (twice)
                            {
                                cout << "You already sent a request for this bike! \n";
                            }
                            else if (already)
                            {
                                cout << "You are already renting the bike! \n";
                            }
                            else
                            {
                                TimeSlot time(dayAndMon, days);
                                RequestStatus status = RequestStatus::PENDING;
                                Request reque = Request(this->getUsername(), bike.getMotorbikeId(), time, status);
                                bike.getRequests().push_back(reque);
                                this->sentRequests.push_back(reque);
                                requests.push_back(reque);
                                cout << "Sent request succesful!\n";
                                quit = true;
                            }
                        }
                    }
                }
                if (!bikeExists)
                {
                    cout << "No bike with the entered ID exists. Please try again.\n";
                    quit = true;
                }
            }
        }
    }
}

// Dash board for members to view all the requests
void User::viewRequestsDash(vector<User> &userList, vector<Borrow> &bo, vector<Motorbike> &bikes, vector<UserRating> &userRatings, vector<Request> &requests)
{
    bool dashboardRun = false;

    while (!dashboardRun)
    {
        system("cls");
        string choice;

        cout << "1. View requests that I sent. \n";
        cout << "2. View requests for my motorbikes. \n";
        cout << "3. Exit\n";
        cout << "Enter your choice(1-3): ";
        getline(cin, choice);

        if (choice == "1")
        {
            this->viewSentRequests();
        }
        else if (choice == "2")
        {
            this->viewBikeRequests(userList, bo, bikes, userRatings, requests);
        }
        else if (choice == "3")
        {
            dashboardRun = true;
            cout << "Logging out...\n";
        }
        else
        {
            cout << "Invalid input! Please enter it correctly. \n";
        }

        cin.ignore();
    }
}

// Dash board for members to view the sent requests
void User::viewSentRequests()
{
    if (this->sentRequests.empty())
    {
        std::cout << "You have no requests." << std::endl;
    }
    else
    {
        cout << left << setw(12) << "Requester" << setw(20) << "MotorbikeID" << setw(15) << "Time Slot" << setw(10) << "Status" << endl;
        cout << setfill('-') << setw(60) << "-" << setfill(' ') << endl;

        for (const Request &request : this->sentRequests)
        {
            if (request.getStatus() == RequestStatus::PENDING || request.getStatus() == RequestStatus::REJECTED)
            {
                cout << left << setw(12) << request.getRequester()
                     << setw(20) << request.getMotorbikeID()
                     << request.getTimeSlot().getStartTime() << " + " << request.getTimeSlot().getEndTime() << "days";
                std::string statusStr = statusToString(request.getStatus());
                cout << left << "   " << statusStr << std::endl;
            }
        }
    }
}

// Dash board for members to view the requests to their bikes
void User::viewBikeRequests(vector<User> &userList, vector<Borrow> &bo, vector<Motorbike> &bikes, vector<UserRating> &userRatings, vector<Request> &requests)
{
    vector<Motorbike> ownedBikes = this->OwnedMotorbikes;
    string IDtoView;
    bool foundMotorbike = false;

    while (!foundMotorbike)
    {
        system("cls"); // Clear the screen
        cout << left << setw(12) << "\nMotorbike ID" << setw(20) << "Model" << setw(10) << "Color" << setw(10) << "Requests" << endl;
        cout << setfill('-') << setw(70) << "-" << setfill(' ') << endl;

        for (Motorbike &bike : ownedBikes)
        {
            int count = 0;
            for (Request &request : bike.getRequests())
            {
                count++;
            }
            cout << left << setw(12) << bike.getMotorbikeId()
                 << setw(20) << bike.getModel()
                 << setw(10) << bike.getColor()
                 << setw(10) << count
                 << endl;
        }

        cout << "Enter a motorbike ID to view (Q to quit): ";
        cin >> IDtoView;
        cin.ignore(); // Consume newline character
        regex regexcheck("^[0-9Qq]$");

        if (IDtoView == "Q" || IDtoView == "q")
        {
            foundMotorbike = true;
            cout << "Enter to continue....";
            break;
        }
        else if (!regex_match(IDtoView, regexcheck))
        {
            cout << "Invalid input! Please try again!  \n";
        }
        else
        {
            int thisBikeid;
            if (!this->OwnedMotorbikes.empty())
            {
                thisBikeid = OwnedMotorbikes[0].getMotorbikeId();
            }
            else
            {
                cout << "You dont have a bike to see the request !\n";
            }
            for (auto &bike : bikes)
            {
                int bikeID = bike.getMotorbikeId();
                if (stoi(IDtoView) == bikeID && stoi(IDtoView) == thisBikeid)
                {
                    if (bike.getRequests().empty())
                    {
                        cout << "The motorbike doesn't have requests yet." << endl;
                        cout << "Press Enter to continue...";
                        cin.ignore();
                    }
                    else
                    {
                        // Display requests for the selected motorbike
                        cout << left << setw(12) << "Request ID" << setw(20) << "Requester" << setw(10) << "Date Sent and Date want to rent" << setw(29) << "Status" << endl;
                        cout << setfill('-') << setw(100) << "-" << setfill(' ') << endl;

                        for (int i = 0; i < bike.getRequests().size(); i++)
                        {
                            if (bike.getRequests()[i].getStatus() == RequestStatus::PENDING)
                            {
                                Request &bikeRequest = bike.getRequests()[i];
                                cout << left << setw(12) << i + 1
                                     << setw(20) << bikeRequest.getRequester()
                                     << bikeRequest.getTimeSlot().getStartTime()
                                     << " + " << bikeRequest.getTimeSlot().getEndTime() << " days";
                                string statusStr = statusToString(bikeRequest.getStatus());
                                cout << left << "   " << statusStr << endl;
                            }
                        }
                    }

                    int requestIndex;
                    bool foundRequest = false;

                    while (!foundRequest)
                    {
                        std::string input;

                        std::cout << "Enter a Request ID to view (0 to quit): ";
                        std::cin >> input;
                        std::cin.ignore(); // Consume newline character

                        if (input == "0")
                        {
                            foundRequest = true;
                            break;
                        }

                        if (!regex_match(input, std::regex("^[0-9]+$")))
                        {
                            std::cout << "Invalid input. Please enter a numeric Request ID." << std::endl;
                            continue; // Go back to the request ID input
                        }

                        requestIndex = std::stoi(input);

                        if (requestIndex < 1 || requestIndex > bike.getRequests().size())
                        {
                            std::cout << "Invalid Request ID. Please try again." << std::endl;
                            continue; // Go back to the request ID input
                        }

                        Request &bikeRequest = bike.getRequests()[requestIndex - 1]; // Subtract 1 to convert to 0-based index
                        std::string requesterStr = bikeRequest.getRequester();
                        User *requester = nullptr;
                        Motorbike *bi = nullptr;

                        // Search for the requester and motorbike
                        for (auto &user : userList)
                        {
                            if (user.getUserName() == requesterStr)
                            {
                                requester = &user;
                                break;
                            }
                        }

                        for (auto &bi1 : bikes)
                        {
                            if (bikeRequest.getMotorbikeID() == bi1.getMotorbikeId())
                            {
                                bi = &bi1;
                                break;
                            }
                        }

                        if (requester == nullptr)
                        {
                            std::cout << "Requester not found." << std::endl;
                        }
                        else
                        {
                            std::string choice;
                            std::cout << "Enter 1 to accept, 2 to reject, 3 to view the renter's reviews, 4 to quit: ";
                            std::cin >> choice;
                            std::cin.ignore();

                            if (choice == "1")
                            {
                                this->acceptRequest(requester, bike.getRequests(), bikeRequest, userList, bo, requests, bi);
                                foundRequest = true;
                            }
                            else if (choice == "2")
                            {
                                this->rejectRequest(bikeRequest, bikes, requests);
                                foundRequest = true;
                            }
                            else if (choice == "3")
                            {
                                viewRequesterReviews(requesterStr, userRatings);
                            }
                            else if (choice == "4")
                            {
                                foundRequest = true;
                            }
                            else
                            {
                                std::cout << "Invalid choice. Please try again." << std::endl;
                            }
                        }
                    }
                    foundMotorbike = true;
                    break;
                }
            }
        }

        if (!foundMotorbike)
        {
            cout << "Invalid motorbike ID. Please try again." << endl;
        }
    }
}

// Method for members to return the bike
void User::returnBikes(User &user, vector<User> &userList, vector<Request> &re, vector<Borrow> &bo, vector<Motorbike> &bikes, vector<MotorbikeRating> &ratings)
{
    int choice;
    bool confirmation = false;
    Motorbike *bike;

    cout << "Enter the motorbike id you want to return: ";
    cin >> choice;
    cin.ignore();

    for (int i = 0; i < bo.size(); i++)
    {
        if (bo[i].getMotorbikeID() == choice && user.getUsername() == bo[i].getUsername() && bo[i].getBorrowSta() == "RENTING")
        {
            while (true)
            {
                string decision;
                cout << "Are you sure that you want to return it right now? (Y/N) ";
                getline(cin, decision);
                if (decision == "Y" || decision == "y")
                {

                    for (int i = 0; i < this->RentingBikes.size(); i++)
                    {
                        RentingBikes.erase(RentingBikes.begin() + i);
                    }
                    bo[i].setBorrowStatus("RENTED");
                    for (auto &bi : bikes)
                    {
                        if (bi.getMotorbikeId() == choice)
                        {
                            bi.setAvailability(true);
                            bike = &bi;
                            break;
                        }
                    }
                    for (int i = 0; i < re.size(); i++)
                    {
                        if (re[i].getMotorbikeID() == choice && user.getUsername() == re[i].getRequester() && re[i].getStatus() == RequestStatus::ACCEPTED)
                        {
                            re.erase(re.begin() + i);
                        }
                    }
                    confirmation = true;

                    cout << "Successfully returned the bike! \n";
                    break;
                }
                else if (decision == "n" || decision == "N")
                {
                    cout << "Failed to return the bike. \n";
                    break;
                }
                else
                {
                    cout << "Invalid input! Please enter 'Y' or 'N'. \n";
                }
            }
            break;
        }
    }
    if (confirmation)
    {
        // TODO: call rate Bike
        rateBike(bike, ratings);
    }
    if (!confirmation)
    {
        cout << "Motorbike not found or not eligible for return. \n";
    }
}

// Method for users to view reviews of a bike
void User::viewBikeReviews(vector<Motorbike> &bikes)
{
    int IDtoView;
    bool foundMotorbike = false;
    while (!foundMotorbike)
    {
        cout << "Enter a motorbike ID to view: ";
        cin >> IDtoView;
        for (auto &bike : bikes)
        {
            int bikeID = bike.getMotorbikeId();
            if (IDtoView == bikeID)
            {
                vector<MotorbikeRating> bikeRatings = bike.getRatings();

                if (bikeRatings.empty())
                {
                    std::cout << "The motorbike doesn't have reviews yet." << std::endl;
                }
                else
                {
                    cout << left << setw(12) << "MotorbikeID" << setw(20) << "Score" << setw(10) << "Comment" << endl;
                    cout << setfill('-') << setw(80) << "-" << setfill(' ') << endl;

                    for (Rating &bikeRating : bikeRatings)
                    {
                        cout << left << setw(12) << bike.getMotorbikeId()
                             << setw(20) << bikeRating.getScore()
                             << setw(10) << bikeRating.getComment() << endl;
                    }
                }
                foundMotorbike = true;
                break;
            }
        }
        if (foundMotorbike)
        {
            break;
        }
        cout << "Invalid ID format! Please enter a valid ID from the list!\n";
    }
}

// Method for members to view reviews of a requester
void User::viewRequesterReviews(string requesterName, vector<UserRating> &userRatings)
{
    system("cls");
    cout << "Reviews of " << requesterName << "\n";
    cout << left << setw(12) << "Score" << setw(10) << "Comment" << endl;
    cout << setfill('-') << setw(80) << "-" << setfill(' ') << endl;
    int count = 0;

    for (auto &userRating : userRatings)
    {
        if (userRating.getUsername() == requesterName)
        {
            cout << left << setw(12) << userRating.getScore()
                 << setw(10) << userRating.getComment() << endl;
            count++;
        }
    }
    if (count == 0)
    { // no user ratings for the corresponding user
        cout << "There is no review for the requester yet!\n";
    }
    cout << "\nEnter to exit." << endl;
}

// Dash board for members to view their own reviews
void User::viewMyReviews(vector<UserRating> &userRatings)
{
    system("cls");

    cout << left << setw(12) << "Score" << setw(10) << "Comment" << endl;
    cout << setfill('-') << setw(80) << "-" << setfill(' ') << endl;
    int count = 0;

    for (auto &userRating : userRatings)
    {
        if (userRating.getUsername() == this->getUserName())
        {
            cout << left << setw(12) << userRating.getScore()
                 << setw(10) << userRating.getComment() << endl;
            count++;
        }
    }
    if (count == 0)
    { // no user ratings for the corresponding user
        cout << "You don't have any reviews yet!\n";
    }
    cout << "\nEnter to exit." << endl;
};

// Method to log in
bool login(User &cus, vector<User> &userList, vector<Motorbike> &bikes)
{
    string username;
    string pass;
    bool usernameFlag = false;
    bool passFlag = false;

    while (!usernameFlag)
    {
        cout << "Enter your username: ";
        getline(cin, username);

        if (username.empty())
        {
            cout << "Username cannot be empty! \n";
        }
        else
        {
            for (auto &user : userList)
            {
                if (user.getUserName() == username)
                {
                    usernameFlag = true;
                    break;
                }
            }
        }
    }

    cout << "Enter your password: ";
    getline(cin, pass);

    if (usernameFlag)
    {
        for (auto &user : userList)
        {
            if (user.getUserName() == username && user.getPassword() == pass)
            {
                cus = User(username, pass, user.getFullName(),
                           user.getPhoneNumber(), user.getIdType(),
                           user.getIdNum(), user.getLicenseNum(),
                           user.getExDate(), user.getCreditPoint(),
                           user.getCity());
                cus.setOwnedBikes(user.getOwned());
                cus.setUserRating(user.getRatings());
                cus.setSentRequest(user.getSentRequests());
                return true;
            }
        }
    }

    return false;
}

// Method for members to accept the requests to their bikes
void User::acceptRequest(User *requester, vector<Request> &requests, Request &request, vector<User> &users, vector<Borrow> &bo, vector<Request> &totalRequest, Motorbike *bike)
{
    double price;
    double bikeID;
    if (!this->OwnedMotorbikes.empty())
    {
        price = OwnedMotorbikes[0].getConsumingPoints();
        bikeID = OwnedMotorbikes[0].getMotorbikeId();
    }
    else
    {
        cerr << "There is no bikes \n";
    }
    double rentalAmount = 0;
    time_t now = time(0);

    tm *ltm = localtime(&now);

    string day = to_string(ltm->tm_mday);
    string month = to_string(1 + ltm->tm_mon);
    if (day.length() == 1)
    {
        day = "0" + day;
    }
    if (month.length() == 1)
    {
        month = "0" + month;
    }
    string dayAndMon = day + "/" + month;
    Borrow *b1o;
    Borrow temp;
    bool oldcus = false;
    for (auto &u : bo)
    {
        if (u.getMotorbikeID() == bikeID && u.getUsername() == requester->getUsername() && u.getBorrowSta() == "RENTED")
        {
            oldcus = true;
            b1o = &u;
            break;
        }
    }

    for (auto &re : requests)
    {
        if (re.getRequester() == requester->getUserName())
        {
            rentalAmount = price * (double)stoi(re.getTimeSlot().getEndTime());
            break;
        }
    }

    if (rentalAmount > requester->getCreditPoint())
    {
        cout << "Payment was not successful. Request cannot be accepted." << endl;
        return;
    }
    requester->setCreditPoint(requester->getCreditPoint() - rentalAmount);
    for (auto &u : users)
    {
        if (u.getUsername() == this->getUsername())
        {
            u.setCreditPoint(u.getCreditPoint() + rentalAmount);
        }
    }
    this->creditPoint = this->creditPoint + rentalAmount;
    RequestStatus reSta;
    string startdate;
    string endDate;

    for (auto &v : totalRequest)
    {
        if (v.getRequester() == requester->getUserName() && v.getMotorbikeID() == bikeID && v.getStatus() == RequestStatus::PENDING && oldcus == false)
        {
            reSta = RequestStatus::ACCEPTED;
            v.setStatus(reSta);
            startdate = dayAndMon;
            endDate = v.getTimeSlot().getEndTime();
            bike->setAvailability(false);
            requester->RentingBikes.push_back(*bike);
            TimeSlot time(startdate, endDate);
            int bikeid = requester->getOwned()[0].getMotorbikeId();
            temp = Borrow(time, requester->getUserName(), bikeID, rentalAmount, "RENTING");
            bo.push_back(temp);
        }
        else if (v.getRequester() == requester->getUserName() && v.getMotorbikeID() == bikeID && v.getStatus() == RequestStatus::PENDING && oldcus == true)
        {
            reSta = RequestStatus::ACCEPTED;
            v.setStatus(reSta);
            startdate = dayAndMon;
            endDate = v.getTimeSlot().getEndTime();
            requester->RentingBikes.push_back(*bike);
            TimeSlot time(startdate, endDate);
            b1o->setTimeSlot(time);
            b1o->setBorrowStatus("RENTING");
            b1o->setPrice(rentalAmount);
        }

        if (v.getRequester() != requester->getUserName() && v.getMotorbikeID() == bikeID && v.getStatus() == RequestStatus::PENDING)
        {
            cout << "Rejecting request with ID: " << v.getMotorbikeID() << endl; // Debugging statement
            reSta = RequestStatus::REJECTED;
            v.setStatus(reSta);
            bike->setAvailability(false);
            startdate = dayAndMon;
            endDate = v.getTimeSlot().getEndTime();
        }
    }
    {
    }

    for (int i = 0; i < requester->getSentRequests().size(); i++)
    {
        if (requester->getUserName() == requester->getSentRequests()[i].getRequester())
        {
            requester->getSentRequests()[i].setStatus(reSta);
            break;
        }
    }

    cout << "Successfully accepted the request!" << endl;
}

// Method for members to reject the requests to their bikes
void User::rejectRequest(Request &request, vector<Motorbike> &bikes, vector<Request> &totalrequest)
{
    int bikeid;
    if (!this->OwnedMotorbikes.empty())
    {
        bikeid = this->OwnedMotorbikes[0].getMotorbikeId();
    }

    for (auto &v : totalrequest)
    {
        if (v.getMotorbikeID() == bikeid && v.getRequester() == request.getRequester())
        {
            v.setStatus(RequestStatus::REJECTED);
            break;
        }
    }
    // 1. change the request status to rejected
    request.setStatus(RequestStatus::REJECTED);
    // 2. remove the request from the request list of the motorbike
    int bikeIdToReject = request.getMotorbikeID();
    for (auto &bike : bikes)
    {
        if (bikeIdToReject == bike.getMotorbikeId())
        {
            vector<Request> &requestsToRemove = bike.getRequests();
            // Find and remove the request from the vector
            requestsToRemove.erase(
                remove(requestsToRemove.begin(), requestsToRemove.end(), request),
                requestsToRemove.end());
            cout << "Successfully rejected the request!" << endl;
            return;
        }
    }
    cout << "Failed to reject the request." << endl;
}
