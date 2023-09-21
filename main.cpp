
#include "Account/User.h"
#include "Account/Admin.h"
#include "savingToFile.h"
#include "Account/Account.h"
#include "City.h"
#include "Motorbike.h"
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <regex>
#include "Borrow.h"

using namespace std;

void guest_dashboard(vector<Motorbike> &bikes);
void user_dashboard(User &user, vector<Motorbike> &bikes, vector<User> &userList, vector<Request> &requests, vector<Borrow> &borrow, vector<UserRating> &userRatings, vector<MotorbikeRating> &ratings);
void admin_dashboard(Admin &admin, vector<Motorbike> &bikes, vector<User> &userList);
void viewGuestBikeDash(vector<Motorbike> &bikes, string city);
void viewBikeDash(User &user, vector<Motorbike> &bikes, vector<Request> &requests, vector<User> &userList);
void displayUserInfo(User &user, vector<User> &userList);
void addCredit(User &user, vector<User> &userList);
void searchEngine(User &user, vector<Motorbike> &bikes,vector< Request> &request);
void returnDashBoard(User &user, vector<User> &userList, vector<Motorbike> &bikes, vector<Request> &request, vector<Borrow> &borrow, vector<MotorbikeRating> &ratings);
int main()
{
    User user;
    Admin admin;
    saveToFile fileSave;
    vector<UserRating> uRatings;
    vector<MotorbikeRating> mRatings;
    vector<Borrow> borrowList = fileSave.loadBorrow();
    fileSave.loadRating(uRatings, mRatings);
    vector<Request> requests = fileSave.loadRequest();
    vector<Motorbike> motorbikeList = fileSave.loadMotor(requests, mRatings);
    vector<User> userList = fileSave.loadAccount(motorbikeList, requests, uRatings, borrowList);

    City city = City::Saigon;

    cout << "EEET2482/COSC2082 ASSIGNMENT"
         << "\n";
    cout << "MOTORBIKE RENTAL APPLICATION."
         << "\n\n";

    cout << "Instructor: Dr. Ling Huo-Chong"
         << "\n";
    cout << "Group: 3"
         << "\n";
    cout << "s3929218, Student Name: Huynh Tan Phat"
         << "\n";
    cout << "s3939114, Student Name: Seokyung Kim"
         << "\n";
    cout << "s3978268, Student Name: Nguyen Hoang Duy"
         << "\n";
    cout << "s3866724, Student Name: Minsung Kim"
         << "\n\n\n";

    bool exitProgram = false;

    while (!exitProgram)
    {
        string choice;
        
        cout << "MOTORBIKE RENTAL APPLICATION."
             << "\n\n";
        cout << "Login as: \n1. Guest  \n2. Member  \n3. Admin  \n4. Register  \n5. Exit the program\n\nEnter your choice: ";
        getline(cin,choice);

        if(choice == "1"){
            cout << "Logging in as a Guest \n";
            cout << "Your are on Guest Mode.\n";

            guest_dashboard(motorbikeList);
            system("cls");
        }else if (choice == "2"){
            cout << "Logging in as Member\n";
            cout << "Your are logging in.\n";
            if (login(user, userList, motorbikeList))
            {
                user_dashboard(user, motorbikeList, userList, requests, borrowList, uRatings,mRatings);
                system("cls");
            }
            else
            {
                system("cls");
                cout << "Login failed! Incorrect username or password! \n";
            }
            
        }else if(choice == "3"){
            cout << "Logging in as Admin \n";
            cout << "Your are on Admin Mode.\n";

            if (admin.adminLogin())
            {
                admin_dashboard(admin, motorbikeList, userList);
                system("cls");
            }
            else
            {
                cout << "Login failed! Incorrect admin username/password\n";
            }
        }else if(choice == "4"){
             if (user.registerAccount(userList))
            {
                cout << "Register successfully\n";
            }
            else
            {
                cout << "Fail\n";
            }
        }else if(choice == "5"){
            exitProgram = true;
            cout << "Bye! See you later!! \n";
            
        }else{
            cout << "Invalid input! Please try again. \n";
        }
        
    }

    fileSave.saveBorrowToFile(borrowList);
    fileSave.SaveAccountToFile(userList);
    fileSave.SaveMotobikeToFile(motorbikeList);
    fileSave.SaveRequestToFIle(requests);
    fileSave.saveRatingToFile(uRatings, mRatings);
    return 0;
}

void guest_dashboard(vector<Motorbike> &bikes)
{
    string choice;
    bool dashboardRun = false;

    while (!dashboardRun)
    {

        system("cls");
        // Display the user dashboard menu
        cout << "|==========================|\n";
        cout << "|      Guest Dashboard     |  Hello, Guest\n";
        cout << "|==========================| \n";
        cout << "| 1. View Bikes in Ha Noi  |  You can only view motorbikes by cities\n";
        cout << "| 2. View Bikes in Saigon  |\n";
        cout << "| 3. Logout                |\n";
        cout << "|==========================|\n";
        cout << "Enter your choice (1-3): ";

        getline(cin,choice);

        if(choice == "1"){
            viewGuestBikeDash(bikes, "Hanoi");
        }else if(choice== "2"){
            viewGuestBikeDash(bikes, "Saigon");
        }else if(choice == "3"){
            dashboardRun = true;
            cout << "Logging out...\n";
        }else{ 
            cout << "Invalid choice. Please enter a valid option (1-3).\n";
        }
        
        // Pause to allow the user to read the message
        cout << "Press Enter to continue...";
        cin.ignore();
    }
}

void user_dashboard(User &user, vector<Motorbike> &bikes, vector<User> &userList, vector<Request> &request, vector<Borrow> &borrow, vector<UserRating> &userRatings, vector<MotorbikeRating> &ratings)
{
    string choice;
    bool dashboardRun = false;

    while (!dashboardRun)
    {
        // get owned bikes
        system("cls");
        string model;
        int i = 0;
        for (int i = 0; i < user.getOwned().size(); i++)
        {
            if (user.getOwned()[i].getOwner() == user.getUsername())
            {
                if (i > 0)
                {
                    model += ", ";
                }
                model += user.getOwned()[i].getModel();
                i++;
            }
        }

        // Display the user dashboard menu
        cout << "|==========================|\n";
        cout << "|      User Dashboard      |  Hello, " << user.getUsername() << "\n";
        cout << "|==========================|  Credit point: " << user.getCreditPoint() << "\n";
        cout << "| 1. View your bio         |  Your owned bike: " << model << "\n";
        cout << "| 2. Your bike             |  Your rating: " << user.getRating() << "\n";
        cout << "| 3. View my ratings       |\n";
        cout << "| 4. Add credit points     |\n";
        cout << "| 5. View Bikes to rent    |\n";
        cout << "| 6. View request          |\n";
        cout << "| 7. Return motorbike      |\n";
        cout << "| 8. Logout                |\n";
        cout << "|==========================|\n";
        cout << "Enter your choice (1-8): ";

       getline(cin,choice);

        if (choice == "1") {
            displayUserInfo(user, userList);
        } else if (choice == "2") {
            user.viewOwnedBike(bikes, borrow, userRatings);
        } else if (choice == "3") {
            user.viewMyReviews(userRatings);
        } else if (choice == "4") {
            addCredit(user, userList);
        } else if (choice == "5") {
             viewBikeDash(user, bikes, request, userList);
        } else if (choice == "6") {
            user.viewRequestsDash(userList, borrow, bikes, userRatings, request);
        } else if (choice == "7") {
             returnDashBoard(user, userList, bikes, request, borrow, ratings);
        } else if (choice == "8") {
            user = User();
             dashboardRun = true;
            cout << "Logging out...\n";
        } else {
             cout << "Invalid choice. Please enter a valid option (1-8).\n";
        }
        cout << "Press Enter to continue...";
        cin.ignore();
    }
}

void admin_dashboard(Admin &admin, vector<Motorbike> &bikes, vector<User> &userList)
{
    string choice;
    bool dashboardRun = false;

    while (!dashboardRun)
    {
        system("cls");

        // Display the admin dashboard menu
        cout << "|==========================|\n";
        cout << "|      Admin Dashboard     |  Hello, Admin!"
             << "\n";
        cout << "|==========================|\n";
        cout << "| 1. View all users        |\n";
        cout << "| 2. View all motorbikes   |\n";
        cout << "| 3. Logout                |\n";
        cout << "|==========================|\n";
        cout << "Enter your choice (1-3): ";

        getline(cin, choice); 

        if (choice == "1")
        {
            system("cls");
            admin.viewAccounts(userList);
        }
        else if (choice == "2")
        {
            system("cls");
            admin.viewMotorbikeInfo(bikes);
        }
        else if (choice == "3")
        {
            dashboardRun = true;
            cout << "Logging out...\n";
        }
        else
        {
            cout << "Invalid choice. Please enter a valid option (1-3).\n";
        }

        
        cout << "Press Enter to continue...";
        cin.ignore();
    }
}


void viewGuestBikeDash(vector<Motorbike> &bikes, string cityStr)
{
    system("cls");
    int choice;
    bool dashboardRun = false;
    City city = stringToCity(cityStr);

    cout << left << setw(12) << "MotorbikeID" << setw(20) << "Model" << setw(10) << "Color" << setw(10) << "Engine" << setw(15) << "Owner" << setw(12) << "Year" << setw(15) << "Start Day" << setw(15) << "End Day" << setw(20) << "Description" << setw(8) << "Rating" << endl;
    cout << setfill('-') << setw(100) << "-" << setfill(' ') << endl;
    for (Motorbike &bike : bikes)
    {
        if (bike.getCity() == city)
        {
            cout << left << setw(12) << bike.getMotorbikeId()
            << setw(20) << bike.getModel()
            << setw(10) << bike.getColor()
             << setw(10) << bike.getEngine()
            << setw(15) << bike.getOwner()
            << setw(12) << bike.getYear()
             << setw(15) << bike.getAvailableTimeSlot().getStartTime()
             << setw(15) << bike.getAvailableTimeSlot().getEndTime()
             << setw(20) << bike.getDes()
             << setw(8) << bike.getRating()
            << endl;
        }
    }
}

void viewBikeDash(User &user, vector<Motorbike> &bikes, vector<Request> &requests, vector<User> &userList)
{
    system("cls");
    string choice;
    bool dashboardRun = false;

    cout<<"--------------------\n";
    cout<<"----Motorbikes---\n";
    cout<< "Here are the motorbikes on the system. \n";

    while (!dashboardRun)
    {
    cout << left << setw(12) << "MotorbikeID" << setw(20) << "Model" << setw(10) << "Color" << setw(10) << "Engine" << setw(15) << "Owner" << setw(12) << "Year" << setw(15) << "Start Day" << setw(15) << "End Day" << setw(20) << "Description" << setw(8) << "Rating" << endl;

    cout << setfill('-') << setw(100) << "-" << setfill(' ') << endl;
    for (Motorbike &bike : bikes)
    {
        cout << left << setw(12) << bike.getMotorbikeId()
         << setw(20) << bike.getModel()
         << setw(10) << bike.getColor()
         << setw(10) << bike.getEngine()
         << setw(15) << bike.getOwner()
         << setw(12) << bike.getYear()
         << setw(15) << bike.getAvailableTimeSlot().getStartTime()
         << setw(15) << bike.getAvailableTimeSlot().getEndTime()
         << setw(20) << bike.getDes()
         << setw(8) << bike.getRating()
         << endl;
    }
        cout << "\n\n";
        cout << "1. Search for all available suitable motorbikes for a particular city. \n";
        cout << "2. Rent a bike. \n";
        cout << "3. View a review of a bike. \n";
        cout << "4. Exit\n";
        cout << "Enter your choice(1-4): ";
        getline(cin,choice);
        if (choice == "1") {
            searchEngine(user, bikes, requests);
        } else if (choice == "2") {
             user.requestToRent(bikes, requests);
        } else if (choice == "3") {
             user.viewBikeReviews(bikes);
             cin.ignore();
        } else if (choice == "4") {
            dashboardRun = true;
                cout << "Logging out...\n";
        } else {
            cout << "Invalid input! Please enter it correctly. \n";
        }       

            cout << "Press Enter to continue..." << endl;
            cin.ignore();

    }
}

void displayUserInfo(User &user, vector<User> &userList)
{
    system("cls");
    bool flag = false;
    string choice;
    cout << "Username: " << user.getUsername() << endl;
    cout << "Full Name: " << user.getFullName() << endl;
    cout << "Phone Number: " << user.getPhoneNumber() << endl;
    cout << "ID Type: " << user.getIdType() << endl;
    cout << "ID Number: " << user.getIdNum() << endl;
    cout << "License Number: " << user.getLicenseNum() << endl;
    cout << "License Expiry Date: " << user.getExDate() << endl;
    cout << "City: " << (user.getCity() == City::Saigon ? "Saigon" : "Hanoi") << endl;
    cout << "----------------------------------" << endl;

    while (true)
    {
        cout << "Choose an option:\n";
        cout << "1. Change Password\n";
        cout << "2. Exit\n";
        cout << "Enter your choice: ";
        getline(cin,choice);

        if (choice == "1") {
        string oldPass;
        cout << "Enter your old password: ";
        getline(cin, oldPass);

    if (oldPass == user.getPassword()) {
        string newPass;
        cout << "Enter your new password: ";
        getline(cin, newPass);
        if(newPass.empty()){
            cout<<"It cannot be empty! \n";
        }else{
            user.setPassword(newPass);
            cout << "Password changed successfully.\n";
            for (auto &u : userList) {
            if (user.getUsername() == u.getUsername()) {
                u.setPassword(newPass);
                break;
            }
        }
        }   
        

        
    } else {
        cout << "Incorrect old password. Password not changed.\n";
    }
} else if (choice == "2") {
    return;
}

    }
}

void addCredit(User &user, vector<User> &userList)
{
    string input;
    regex regexp("^(-?)(0|([1-9][0-9]*))(\\.[0-9]+)?$");
    while (true)
    {
        cout << "Enter amount of points (Q to quit): ";
        getline(cin, input);
        if (input == "Q" || input == "q")
        {
            break;
        }
        else
        {
            if (!regex_match(input, regexp))
            {
                cout << "Invalid input! Please enter again!";
            }
            else
            {
                double credit = stod(input);
                if (credit <= 0)
                {
                    cout << "Please input a valid amount. \n";
                }
                else
                {
                    user.setCreditPoint(user.getCreditPoint() + credit);
                    for (auto &u : userList)
                    {
                        if (user.getUserName() == u.getUserName())
                        {
                            u.setCreditPoint(u.getCreditPoint() + credit);
                            cout << "Add money successfully! ";
                            break;
                        }
                    }
                    break;
                }
            }
        }
    }
}

void searchEngine(User &user, vector<Motorbike> &bikes,vector<Request> &request)
{
    system("cls");
    string choice;
    bool dashboardRun = false;

    string desiredCity = "";
    City city;
    double userPoints = user.getCreditPoint();
    double userRating = user.getRating();
    
    // search by city
    while (true)
    {
        std::cout << "Enter the city to search in (Saigon or Hanoi): ";
        std::cin >> desiredCity;
        
        if (desiredCity == "Saigon" || desiredCity == "Hanoi")
        {
            cin.ignore();
            break;
        }

        std::cout << "Invalid city. Please enter Saigon or Hanoi.\n";
    }
    string date;
    regex dateRegex("^(0[1-9]|[1-2][0-9]|3[0-1])/(0[1-9]|1[0-2])$");

    // search by renting date
    while (true) {
        cout << "Enter the date to search (dd/mm): ";
        getline(std::cin, date);

        if (regex_match(date, dateRegex)) {
        
            break; 
        } else {
            cout << "\nInvalid date format. Please use (dd/mm) format." << std::endl;
        }
    }

    if (desiredCity == "Saigon")
    {
        city = City::Saigon;
    }
    else
    {
        city = City::Hanoi;
    }   

    // automatically take userPoints and userRating into account
    cout << "My credit point: " << userPoints << "\n";
    cout << "My rating score: " << userRating << "\n";

    cout << left << setw(12) << "Motorbike ID" << setw(20) << "Model" << setw(10) << "Color" << setw(10) << "Engine" << setw(15) << "Owner" << setw(12) << "Year" << setw(15) << "Start Day" << setw(15) << "End Day" << setw(20) << "Description" << setw(8) << "Rating" << endl;
    cout << setfill('-') << setw(100) << "-" << setfill(' ') << endl;
    bool found =false;
    for (Motorbike &bike : bikes)
    {
        if (bike.getCity() == city && bike.getAvailableTimeSlot().isDateInRange(date))
        {
            if (bike.getConsumingPoints() <= userPoints && bike.getRating() <= userRating)
            {
                cout << left << setw(12) << bike.getMotorbikeId()
            << setw(20) << bike.getModel()
            << setw(10) << bike.getColor()
             << setw(10) << bike.getEngine()
            << setw(15) << bike.getOwner()
            << setw(12) << bike.getYear()
             << setw(15) << bike.getAvailableTimeSlot().getStartTime()
             << setw(15) << bike.getAvailableTimeSlot().getEndTime()
             << setw(20) << bike.getDes()
             << setw(8) << bike.getRating()
            << endl;
            found =true;
            }
        }
    }
    if(!found){
        cout<< "There is no bike that fits your search. Sorry! \n\n";
    }
    cout << "\n1. Rent a bike\n2. Return to previous page. \n";
    cout<< "Enter choice: ";
    getline(cin,choice);
    if (choice == "1") {
    user.requestToRent(bikes, request);
} else if (choice == "2") {
    dashboardRun = true;
} else {
    cout << "Invalid input! Please enter it correctly. \n";
}

}

void returnDashBoard(User &user, vector<User> &userList, vector<Motorbike> &bikes, vector<Request> &request, vector<Borrow> &borrow, vector <MotorbikeRating> &ratings)
{
    system("cls");
    string choice;
    bool dashboard = false;
    bool found = false;
    for (auto &bo : borrow)
    {
        if (bo.getUsername() == user.getUsername())
        {
            found = true;
        }
    }
    if (!found)
    {
        cout << "Hello, " << user.getUsername() << "\n";
        cout << "You are not renting any motorbikes yet\n";
    }
    else
    {
        cout << "     Your motorbike renting list      \n";
        cout << "--------------------------------------\n";
        for (auto &bo : borrow)
        {
            for (auto &v : bikes)
            {
                if (bo.getMotorbikeID() == v.getMotorbikeId() && user.getUsername() == bo.getUsername() && bo.getBorrowSta() == "RENTING")
                {
                    cout << "Bike name: " << v.getModel() << "\t  Bike id is " << v.getMotorbikeId() << "\n";
                    cout << "You must return in " << bo.getTimeSlot().addDayToDate() << "\n\n";
                }
            }
        }
        while (!dashboard)
        {
            cout<< "Enter your choice: \n";
            cout << "1.Return motorbike. \n";
            cout << "2.Quit. \n";
            cout << "Enter your choice: ";
            getline(cin, choice);
            if (choice == "1")
            {
                user.returnBikes(user, userList, request, borrow, bikes,ratings);
            }
            else if (choice == "2")
            {

                dashboard = true;
            }
        }
    }
}
