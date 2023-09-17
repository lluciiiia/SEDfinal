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
    vector<Motorbike> OwnedMotorbikes = this->getOwned();

    cout << left << setw(12) << "Motorbike ID" << setw(20) << "Model" << setw(10) << "Color" << setw(10) << "Engine" << setw(15) << "Owner" << setw(12) << "Year" << setw(20) << "Description" << setw(8) << "Rating" << setw(8) << "City" << endl;
    cout << setfill('-') << setw(150) << "-" << setfill(' ') << endl;
    for (auto &bike : OwnedMotorbikes)
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

    int idToRemove;
    bool removed = false;
    while (!removed)
    {
        cout << "\nEnter the id of the bike to remove: ";
        cin >> idToRemove;

        for (int i = 0; i < bikes.size(); i++)
        {
            if (bikes[i].getMotorbikeId() == idToRemove)
            {
                // Remove the bike from the vector
                bikes.erase(bikes.begin() + i);
                cout << "Remove bike successfully!\n";
                removed = true;

                // TODO: update the bikes so the user can see the updated list
            }
        }
        cout << "Bike with ID " << idToRemove << " not found.\n";
    }
};

// TODO: Do we need this?
void User::addMotorInnitial(Motorbike motor)
{
    OwnedMotorbikes.push_back(motor);
}

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

// end register

// Rate user and motorbike
void User::rateUserAndMotorbike(User &ratedUser, Motorbike &ratedMotorbike)
{
    // Variables for score and comment
    float userScore = 0, motorbikeScore = 0;
    string userComment = "", motorbikeComment = "";

    // Rate user
    cout << "Enter score for user: ";
    cin >> userScore;
    cin.ignore();
    cout << "Enter comment for user: ";
    getline(cin, userComment);
    cout << endl;

    // Rate motorbike
    cout << "Enter score for motorbike: ";
    cin >> motorbikeScore;
    cin.ignore();
    cout << "Enter comment for motorbike " << ratedMotorbike.getMotorbikeId() << ": ";
    getline(cin, motorbikeComment);
    cout << endl;

    // Adding rating to list
    UserRating userRate(ratedUser.getUserName(), userScore, userComment);
    ratedUser.userRatings.push_back(userRate);

    MotorbikeRating motorbikeRate(ratedMotorbike.getMotorbikeId(), motorbikeScore, motorbikeComment);
    ratedMotorbike.getRatings().push_back(motorbikeRate);
}

void User::searchAvailableMotorbikes() {}

void User::setCreditPoint(double credit)
{
    this->creditPoint = credit;
}

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
    string input;
    while (true)
    {
        cout << "Enter the bike model you want to rent (Q to quit): ";
        getline(cin, input);

        if (input == "Q" || input == "q")
        {
            break;
        }
        else
        {
            for (auto &bi : bikes)
            {

                if (input == bi.getModel())
                {
                    while (true)
                    {
                        string rentdays;
                        cout << "How many days you want to rent? (Q to quit) ";
                        getline(cin, rentdays);

                        if (rentdays == "Q" || rentdays == "q")
                        {
                            cout << "Rent canceled! \n";
                            break;
                        }
                        else
                        {
                            double totalDays = stod(rentdays); // Convert to integer

                            if (this->creditPoint < bi.getConsumingPoints() * totalDays)
                            {
                                cout << "You don't have enough credit points to rent! Please lower your days or quit \n";
                            }
                            else
                            {
                                TimeSlot time(dayAndMon, rentdays);
                                RequestStatus status = RequestStatus::PENDING;

                                Request reque = Request(this->getUsername(), bi.getMotorbikeId(), time, status, bi);
                                bi.getRequests().push_back(reque);
                                requests.push_back(reque);
                                cout << "Rent successful! \n";
                            }
                            break;
                        }
                    }
                }
            }
            break;
        }
    }
};

void User::viewRequestsDash(vector<User> &userList)
{
    system("cls");
    int choice;
    bool dashboardRun = false;
    cout << "\n";
    cout << "----------------------------------------\n";
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
        this->viewBikeRequests(userList);
        break;
    case 3:
        dashboardRun = true;
        cout << "Logging out...\n";
        break;
    default:
        cout << "Invalid input! Please enter it correctly. \n";
    }
    cout << "Press Enter to continue...";
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
        cout << left << setw(12) << "Requester" << setw(20) << "MotorbikeID" << setw(10) << "Time Slot" << setw(10) << "Request Status" << setw(15) << endl;
        cout << setfill('-') << setw(60) << "-" << setfill(' ') << endl;

        for (const Request &request : this->sentRequests)
        {
            if (request.getStatus() == RequestStatus::PENDING)
            {
                cout << left << setw(12) << request.getRequester()
                     << setw(20) << request.getMotorbikeID()
                     << setw(10) << "Time Slot: " << request.getTimeSlot().getStartTime() << " - " << request.getTimeSlot().getEndTime() << "\n";
                std::string statusStr = statusToString(request.getStatus());
                cout << left << setw(10) << "Status: " << statusStr << std::endl;
            }
        }
    }
}

void User::viewBikeRequests(vector<User> &userList)
{
    // view the list of owned motorbikes
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
    // choose the motorbike id
    int IDtoView;
    bool foundMotorbike = false;
    while (!foundMotorbike)
    {
        cout << "Enter a motorbike ID to view: ";
        cin >> IDtoView;
        for (auto &bike : OwnedMotorbikes)
        {
            int bikeID = bike.getMotorbikeId();
            if (IDtoView == bikeID)
            {
                vector<Request> bikeRequests = bike.getRequests();

                if (bikeRequests.empty())
                {
                    std::cout << "The motorbike doesn't have reviews yet." << std::endl;
                }
                else
                {
                    cout << left << setw(12) << "Request ID" << setw(20) << "Requester" << setw(10) << "TimeSlot" << setw(20) << "Status" << endl;
                    cout << setfill('-') << setw(100) << "-" << setfill(' ') << endl;

                    // for (const Request &bikeRequest : bikeRequests)
                    // {
                    for (int i = 0; i < bikeRequests.size(); i++)
                    {
                        Request &bikeRequest = bikeRequests[i];
                        cout << left << setw(12) << i + 1
                             << setw(20) << bikeRequest.getRequester()
                             << setw(10) << bikeRequest.getTimeSlot().getStartTime()
                             << " - " << bikeRequest.getTimeSlot().getEndTime() << "\n";
                        string statusStr = statusToString(bikeRequest.getStatus());
                        cout << left << setw(10) << statusStr
                             << endl;
                    }
                }
                // choose a request (i-1) from the request list -> accept / reject
                // choose the motorbike id
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
                            User requester;
                            for (auto &user : userList)
                            {
                                if (user.getUserName() == requesterStr)
                                {
                                    requester = user;
                                }

                                cout << "Enter 1 to accept, 2 to reject\n";
                                int choice;
                                cin >> choice;
                                cin.ignore();
                                switch (choice)
                                {
                                case 1:
                                    this->acceptRequest(requester, bikeRequests, bikeRequest, userList);
                                    break;
                                case 2:
                                    // TODO
                                    // this->rejectRequest(bikeRequest);
                                    break;
                                default:
                                    cout << "Invalid input! Please enter it correctly. \n";
                                }
                                cout << "Press Enter to continue...";
                                cin.ignore();
                                bool foundRequest = true;
                                break;
                            }
                        }
                        if (foundRequest)
                        {
                            break;
                        }
                        cout << "Invalid ID format! Please enter a valid ID from the list!\n";
                    }
                }
                cout << "Invalid ID format! Please enter a valid ID from the list!\n";
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

    // choose a request (i-1) from the request list -> accept / reject
}

void User::setOwnedBikes(vector<Motorbike> &bikes)
{
    this->OwnedMotorbikes = bikes;
}

void User::viewReviews(vector<Motorbike> &bikes)
{
    // TODO: select motorbikeID to view
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

                    for (const Rating &bikeRating : bikeRatings)
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
                return true;
            }
        }
    }

    return false;
}

// bool User::processPayment(User &requester, Request request) {
//     // double rentalAmount = calculateRentalAmount(request);
//     int bikeIDtoRent = request.getMotorbikeID();

//     if (requester.getCreditPoint() >= rentalAmount) {
//         double newRequesterCredit = requester.getCreditPoint() - rentalAmount;
//         requester.setCreditPoint(newRequesterCredit);

//         return true;
//     } else {
//         std::cout << "Insufficient credit to make the payment." << std::endl;
//         return false;
//     }
// }

// //error on request
double User::calculateRentalAmount(Request &request)
{
    Motorbike bikeToRent = request.getMotorbike();

    double dailyRentalPrice = bikeToRent.getConsumingPoints();

    string startTime = request.getTimeSlot().getStartTime();
    string endTime = request.getTimeSlot().getEndTime();

    // Convert start and end times to hours and minutes
    int startHour, startMinute, endHour, endMinute;
    sscanf(startTime.c_str(), "%d:%d", &startHour, &startMinute);
    sscanf(endTime.c_str(), "%d:%d", &endHour, &endMinute);

    int rentalDurationInHours = (endHour - startHour) + ((endMinute - startMinute) / 60);
    if (rentalDurationInHours <= 0)
    {
        // If the duration is less than or equal to 0, consider it as 1 day.
        rentalDurationInHours = 24;
    }

    // Calculate the rental amount based on the daily rate
    double rentalAmount = rentalDurationInHours * dailyRentalPrice;

    return rentalAmount;
}

void User::acceptRequest(User &requester, vector<Request> &requests, Request &request, vector<User> &users)
{
    // Calculate the rental amount
    double rentalAmount = calculateRentalAmount(request);

    // Check if the requester has sufficient credits to make the payment
    if (requester.getCreditPoint() >= rentalAmount)
    {
        // Deduct the rental amount from the requester's credits
        double requesterCredit = requester.getCreditPoint();
        requesterCredit -= rentalAmount;
        requester.setCreditPoint(requesterCredit);

        // Find the owner of the motorbike and increase their credits
        Motorbike bikeToAccept = request.getMotorbike();
        string ownerName = bikeToAccept.getOwner();
        User owner;

        for (auto &user : users)
        {
            if (user.getUserName() == ownerName)
            {
                owner = user;
                break;
            }
        }

        double ownerCredit = owner.getCreditPoint();
        ownerCredit += rentalAmount;
        owner.setCreditPoint(ownerCredit);

        bikeToAccept.setAvailability(false);

        request.setStatus(RequestStatus::ACCEPTED);

        requests.push_back(request);

        cout << "Request from " << requester.getUserName() << " to rent motorbike " << bikeToAccept.getMotorbikeId() << " has been accepted." << endl;
    }
    else
    {
        cout << "Payment was not successful. Request cannot be accepted." << endl;
    }
}
// void User::rejectRequest(User &requester, Request &request) {
//     request.setStatus(RequestStatus::REJECTED);
// }

// vector<Motorbike> User::rentBikes()
// {
//     return vector<Motorbike>();
// }

// vector<Request> User::receiveRequest()
// {
//     return vector<Request>();
// }
