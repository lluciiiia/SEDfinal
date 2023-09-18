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

// TODO: do we need this? - Lucia
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

// TODO: choose one of these
vector<Motorbike> User::getOwnedMotorbike()
{
    return this->OwnedMotorbikes;
}

vector<UserRating> &User::getRatings()
{
    return this->userRatings;
};

// TODO: choose one of these
vector<Motorbike> &User::getOwned()
{
    return this->OwnedMotorbikes;
}

bool User::addBike(vector<Motorbike> &bikes)
{
    // for (auto &ownedBike : this->getOwned())
    // {
    //     cout << ownedBike.getModel();
    // }
    // cout << "owned bikes: " << this->getOwned().size() << "\n";
    if (this->OwnedMotorbikes.size() == 1) // TODO: it's not working
    {
        cout << "You can own only one bike." << endl;
        return false;
    }

    regex regexp("^(-?)(0|([1-9][0-9]*))(\\.[0-9]+)?$");
    string model, color, enginSize, transmissionmode;
    string description = "";
    int yearMade;
    cout << "Please enter all of needed informations: \n";
    // Model
    while (true)
    {
        cout << "Enter your model: ";
        getline(cin, model);
        if (model.empty())
        {
            cout << "Password cannot be empty! \n";
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
            cout << "Password cannot be empty! \n";
        }
        else
        {
            break;
        }
    }
    // Engine size
    while (true)
    {
        cout << "Enter your engine size: ";
        getline(cin, enginSize);
        if (enginSize.empty())
        {
            cout << "Password cannot be empty! \n";
        }
        else
        {
            break;
        }
    }
    // Year made
    while (true)
    {
        cout << "Enter year made: ";
        cin >> yearMade;
        cin.ignore();
        string num = to_string(yearMade);
        if (!regex_match(num, regexp))
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
            cout << "Password cannot be empty! \n";
        }
        else
        {
            break;
        }
    }
    // Motorbike Description
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

    int motorbikeID = bikes.size() + 1;
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
            cout << "Invalid input for ratings! Please enter agian. ";
        }
        else
        {
            break;
        }
        // Available TimeSlot
        while (true)
        {
            // Make sure dates follow format (mm/dd/yyyy)
            static const std::regex dateRegex("^(0[1-9]|1[0-2])/(0[1-9]|[1-2][0-9]|3[0-1])/(\\d{4})$");
            string startTime = "", endTime = "";

            while (!regex_match(startTime, dateRegex))
            {
                cout << "Enter start time for bike rental period in the format (mm/dd/yyyy): ";
                cin >> startTime;
                if (!regex_match(startTime, dateRegex))
                {
                    cout << "Start time is in the wrong format! Please try again.\n";
                }
            }

            while (!regex_match(endTime, dateRegex))
            {
                cout << "Enter end time for bike retal period in the format (mm/dd/yyyy): ";
                cin >> endTime;
                if (!regex_match(endTime, dateRegex))
                {
                    cout << "End time is in the wrong format! Please try again.\n";
                }
            }

            cout << "Your motorbike is available for rental from: " << startTime << " - " << endTime << endl;
            break;
        }
    }

    Motorbike motor(model, motorbikeID,
                    color, enginSize,
                    selectedCity,
                    Account::getUsername(),
                    transmissionmode,
                    yearMade,
                    description, consumingPoints, 0, minRate, true);
    bikes.push_back(motor);
    OwnedMotorbikes.push_back(motor);
    return true;
}

void User::removeBike(vector<Motorbike> &bikes)
{
    system("cls");

    string idToRemove;

    while (true)
    {
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
        cout << "You can only add only one bike. \n";
        cout << "1.Add a bike: \n";
        cout << "2.Delete your bike \n";
        cout << "3.Exit";
        cout << "\nEnter your choice: ";
        getline(cin, idToRemove);

        if (idToRemove == "1")
        {
            this->addBike(bikes);
        }
        else if (idToRemove == "2")
        {
            int bikeId;
            for (int i = 0; i < 1; i++)
            {
                bikeId = this->OwnedMotorbikes[i].getMotorbikeId();
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
            }
        }
        else if (idToRemove == "3")
        {
            break;
        }
        else
        {
            cout << "Invalid input. Please try again! \n";
        }
    }
};

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

void User::rateBike(Motorbike &ratedMotorbike)
{
    // Variables for score and comment
    float motorbikeScore = 0;
    string motorbikeComment = "";

    // Rate motorbike
    cout << "Enter score for motorbike: ";
    cin >> motorbikeScore;
    cin.ignore();
    cout << "Enter comment for motorbike " << ratedMotorbike.getMotorbikeId() << ": ";
    getline(cin, motorbikeComment);
    cout << endl;

    MotorbikeRating motorbikeRate(ratedMotorbike.getMotorbikeId(), motorbikeScore, motorbikeComment);
    ratedMotorbike.getRatings().push_back(motorbikeRate);
}

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

void User::setCreditPoint(double credit)
{
    this->creditPoint = credit;
}

// TODO: Add timeslot feature (Duy: I'm thinking how to implement it into this)
void User::requestToRent(vector<Motorbike> &bikes, vector<Request> &requests)
{
    system("cls");

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

    for (Motorbike &bike : bikes)
    {
        // TODO: city filter!!
        if (bike.getAvailability() == true && this->creditPoint >= bike.getConsumingPoints() && this->city == bike.getCity())
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
        }
    }

    regex regexp("^(-?)(0|([1-9][0-9]*))(\\.[0-9]+)?$");
    while (true)
    {
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
                            else
                            {
                                TimeSlot time(dayAndMon, days);
                                RequestStatus status = RequestStatus::PENDING;
                                Request reque = Request(this->getUsername(), bike.getMotorbikeId(), time, status);
                                bike.getRequests().push_back(reque);
                                requests.push_back(reque);
                                cout << "Rent successful!\n";
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

void User::viewRequestsDash(vector<User> &userList, vector<Borrow> &bo, vector<Motorbike> &bikes)
{
    system("cls");
    int choice;
    bool dashboardRun = false;
    cout << "1. View requests that I sent. \n";
    cout << "2. View requests for my motorbikes. \n";
    cout << "3. Exit\n";
    cout << "Enter your choice(1-3): ";
    cin >> choice;
    cin.ignore();
    switch (choice)
    {
    case 1:
        this->viewSentRequests();
        break;
    case 2:
        this->viewBikeRequests(userList, bo, bikes);
        break;
    case 3:
        dashboardRun = true;
        cout << "Logging out...\n";
        break;
    default:
        cout << "Invalid input! Please enter it correctly. \n";
    }
    cin.ignore();
};

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
            if (request.getStatus() == RequestStatus::PENDING)
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
void User::viewBikeRequests(vector<User> &userList, vector<Borrow> &bo, vector<Motorbike> &bikes)
{
    vector<Motorbike> ownedBikes = this->OwnedMotorbikes;
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

    string IDtoView;
    bool foundMotorbike = false;
    while (!foundMotorbike)
    {
        cout << "Enter a motorbike ID to view (Q to quit): ";
        cin >> IDtoView;
        if (IDtoView == "Q" || IDtoView == "q")
        {
            foundMotorbike = true;
            break;
        }
        for (auto &bike : OwnedMotorbikes)
        {
            int bikeID = bike.getMotorbikeId();
            if (stoi(IDtoView) == bikeID)
            {
                vector<Request> bikeRequests = bike.getRequests();

                if (bikeRequests.empty())
                {
                    cout << "The motorbike doesn't have requests yet." << endl;
                    break;
                }
                else
                {
                    cout << left << setw(12) << "Request ID" << setw(20) << "Requester" << setw(10) << "TimeSlot" << setw(20) << "Status" << endl;
                    cout << setfill('-') << setw(100) << "-" << setfill(' ') << endl;

                    for (int i = 0; i < bikeRequests.size(); i++)
                    {
                        Request &bikeRequest = bikeRequests[i];
                        cout << left << setw(12) << i + 1
                             << setw(20) << bikeRequest.getRequester()
                             << bikeRequest.getTimeSlot().getStartTime()
                             << " + " << bikeRequest.getTimeSlot().getEndTime() << " days";
                        string statusStr = statusToString(bikeRequest.getStatus());
                        cout << left << "   " << statusStr << endl;
                    }
                }

                int requestIndex;
                bool foundRequest = false;
                while (!foundRequest)
                {
                    cout << "Enter a Request ID to view: ";
                    cin >> requestIndex;
                    for (int i = 0; i < bikeRequests.size(); i++)
                    {
                        if (i == requestIndex - 1)
                        {
                            Request &bikeRequest = bikeRequests[i];
                            string requesterStr = bikeRequest.getRequester();
                            User *requester = nullptr;

                            for (auto &user : userList)
                            {
                                if (user.getUserName() == requesterStr)
                                {
                                    requester = &user;
                                    break;
                                }
                            }

                            if (requester == nullptr)
                            {
                                cout << "Requester not found." << endl;
                                break;
                            }

                            cout << "Enter 1 to accept, 2 to reject, 3 to quit: ";
                            int choice;
                            cin >> choice;
                            cin.ignore();
                            switch (choice)
                            {
                            case 1:
                                this->acceptRequest(requester, bikeRequests, bikeRequest, userList, bo);
                                break;
                            case 2:
                                this->rejectRequest(bikeRequest, bikes);
                                break;
                            case 3:
                                foundRequest = true;
                                break;
                            default:
                                cout << "Invalid choice. Please try again." << endl;
                                break;
                            }
                            foundRequest = true;
                            break;
                        }
                    }
                    if (!foundRequest)
                    {
                        cout << "Invalid Request ID. Please try again." << endl;
                    }
                    else
                    {
                        break; // Exit the while loop after accepting or rejecting a request
                    }
                }
                foundMotorbike = true;
                break;
            }
        }
        if (!foundMotorbike)
        {
            cout << "Invalid motorbike ID. Please try again." << endl;
        }
    }
}

void User::setOwnedBikes(vector<Motorbike> &bikes)
{
    this->OwnedMotorbikes = bikes;
}

void User::setUserRating(vector<UserRating> &ratings)
{
    this->userRatings = ratings;
}

void User::returnBikes(User &user, vector<User> &userList, vector<Request> &re, vector<Borrow> &bo, vector<Motorbike> &bikes)
{
    int choice;
    bool confirmation = false;

    cout << "Enter the motorbike you want to return: ";
    cin >> choice;
    cin.ignore();

    for (int i = 0; i < bo.size(); i++)
    {
        if (bo[i].getMotorbikeID() == choice && user.getUsername() == bo[i].getUsername())
        {
            while (true)
            {
                string decision;
                cout << "Are you sure that you want to return it right now? (Y/N) ";
                getline(cin, decision);
                if (decision == "Y" || decision == "y")
                {
                    confirmation = true;
                    // TODO: do sth for the owner to review the renter
                    bo.erase(bo.begin() + i);
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
        }
    }
    if (!confirmation)
    {
        cout << "Motorbike not found or not eligible for return. \n";
    }
}

void User::setSentRequest(vector<Request> &requsest)
{
    this->sentRequests = requsest;
}

void User::viewReviews(vector<Motorbike> &bikes)
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
    if (count == 0) { // no user ratings for the corresponding user
        cout << "You don't have any reviews yet!\n";
    }
    cout << "\nEnter to exit." << endl;
};

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

void User::acceptRequest(User *requester, vector<Request> &requests, Request &request, vector<User> &users, vector<Borrow> &bo)
{
    double price = OwnedMotorbikes[0].getConsumingPoints();

    double rentalAmount = 0;
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

    RequestStatus reSta;
    string startdate;
    string endDate;
    requester->setCreditPoint(requester->getCreditPoint() + rentalAmount);
    for (auto &v : requests)
    {
        if (v.getRequester() == requester->getUserName())
        {
            reSta = RequestStatus::ACCEPTED;
            v.setStatus(reSta);
            startdate = v.getTimeSlot().getStartTime();
            endDate = v.getTimeSlot().getEndTime();
        }
        else
        {
            reSta = RequestStatus::REJECTED;
            v.setStatus(reSta);
        }
    }

    for (int i = 0; i < requester->getSentRequests().size(); i++)
    {
        if (requester->getUserName() == requester->getSentRequests()[i].getRequester())
        {
            requester->getSentRequests()[i].setStatus(reSta);
            break;
        }
    }

    TimeSlot time(startdate, endDate);
    int bikeid = requester->getOwned()[0].getMotorbikeId();

    Borrow b1o = Borrow(time, requester->getUserName(), bikeid, rentalAmount, "RENTING");
    bo.push_back(b1o);
    cout << "Successfully accepted the request!" << endl;
}

void User::rejectRequest(Request &request, vector<Motorbike> &bikes)
{
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
