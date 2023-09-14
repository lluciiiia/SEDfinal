
#include "Account/User.h"
#include "Account/Admin.h"
#include "savingToFile.h"
#include "Account/Account.h"
#include "City.h"
#include "Motorbike.h"
// #include "Rating.h"
// #include "Request.h"
// #include "TimeSlot.h"
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <regex>
// #include "Borrow.h"

using namespace std;

void guest_dashboard(vector<Motorbike> &bikes);
void user_dashboard(User &user, vector<Motorbike> &bikes, vector<User> &userList,vector<Request> &requests);
void admin_dashboard(Admin &admin, vector<Motorbike> &bikes, vector<User> &userList);
void viewGuestBikeDash(vector<Motorbike> &bikes, string city);
void viewBikeDash(User &user, vector<Motorbike> &bikes,vector<Request> requests);
void displayUserInfo(User &user, vector<User> &userList);
void addCredit(User &user, vector<User> &userList);
void searchDisPlay(User &user, vector<Motorbike> &bikes);
int main()
{
    User user;
    Admin admin;
    saveToFile fileSave;
    vector <Request> requests;
    vector<Motorbike> motorbikeList = fileSave.loadMotor();
    vector<User> userList = fileSave.loadAccount(motorbikeList);

    City city = City::Saigon;

 

    cout << "EEET2482/COSC2082 ASSIGNMENT"
         << "\n";
    cout << "MOTORBIKE RENTAL APPLICATION."
         << "\n\n";

    cout << "Instructor: Dr. Ling Hou Chong"
         << "\n";
    cout << "Group: 3"
         << "\n";
    cout << "s3929218, Student Name: Huynh Tan Phat"
         << "\n";
    cout << "s3939114, Student Name: Seokyung Kim"
         << "\n";
    cout << "s3978268, Student Name: Nguyen Hoang Duy"
         << "\n";
    cout << "s3929218, Student Name: Huynh Tan Phat"
         << "\n\n\n";

    bool exitProgram = false;

    while (!exitProgram)
    {
        int choice;
        cout << "MOTORBIKE RENTAL APPLICATION."
             << "\n\n";
        cout << "Login as: \n1. Guest  \n2. Member  \n3. Admin  \n4. Register  \n5. Exit the program\n\nEnter your choice: ";
        cin >> choice;
        cin.ignore();
        switch (choice)
        {
        case 1:
        {
            cout << "Logging in as a Guest \n";
            cout << "Your are on Guest Mode.\n";

            guest_dashboard(motorbikeList);
            system("cls");

            break;
        }
        case 2:
        {
            cout << "Logging in as Member\n";
            cout << "Your are logging in.\n";
            if (login(user, userList))
            {
                user_dashboard(user, motorbikeList, userList,requests);
                system("cls");
            }
            else
            {
                cout << "Login failed! Incorrect username or password! \n";
            }
            break;
        }
        case 3:
        {
            // check if the login is admin account
            cout << "Logging in as Admin \n";
            cout << "Your are on Admin Mode.\n";

            if ( admin.adminLogin() ) {
                admin_dashboard(admin, motorbikeList, userList);
                system("cls");
            } 
            else {
                cout << "Login failed! Incorrect admin username/password\n";
            }
            break;
        }
        case 4:
        {
            if (user.registerAccount(userList))
            {
                cout << "Register successfully\n";
            }
            else
            {
                cout << "Fail\n";
            }
            break;
        }
        case 5:
        {
            exitProgram = true;
            cout << "Bye! See you later!! \n";
            break;
        }
        default:{
            cout<< "Invalid input! Please try again. \n";
            cin>> choice;
        }
        }
    }

    fileSave.SaveAccountToFile(userList);
    fileSave.SaveMotobikeToFile(motorbikeList);
    fileSave.SaveRequestToFIle(requests);
    return 0;
}

void guest_dashboard(vector<Motorbike> &bikes)
{
    int choice;
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

        cin >> choice;
        cin.ignore(); // Consume the newline character

        switch (choice)
        {
        case 1:
            viewGuestBikeDash(bikes, "Ha noi"); // TODO: Ha noi
            break;
        case 2:
            viewGuestBikeDash(bikes, "Saigon"); // TODO: Ho Chi Minh
            break;
        case 3:

            dashboardRun = true;
            cout << "Logging out...\n";
            break;
        default:
            cout << "Invalid choice. Please enter a valid option (1-3).\n";
            break;
        }
        // Pause to allow the user to read the message
        cout << "Press Enter to continue...";
        cin.ignore();
    }
}

void user_dashboard(User &user, vector<Motorbike> &bikes, vector<User> &userList, vector<Request> &request)
{
    int choice;
    bool dashboardRun = false;

    while (!dashboardRun)
    {

        system("cls");
        string model;
        // if (!user.getOwnedMotorbike().empty()) {
        //     model = user.getOwnedMotorbike()[0].getModel();
        //     cout << "Motorbike model: " << model << endl;
        // } else {
        //     cout << "No owned motorbikes." << endl;
        // }

        for (auto &bike : bikes)
        {
            if (bike.getOwner() == user.getUsername())
            {
                model = bike.getModel();
            }
        }
        // Display the user dashboard menu
        cout << "|==========================|\n";
        cout << "|      User Dashboard      |  Hello, " << user.getUsername() << "\n";
        cout << "|==========================|  Credit point: " << user.getCreditPoint() << "\n";
        cout << "| 1. View your bio         |  Your owned bike: " << model << "\n";
        cout << "| 2. Add your motorbike    |\n";
        cout << "| 3. Add credit points     |\n";
        cout << "| 4. View Bikes to rent    |\n";
        cout << "| 5. View request          |\n";
        cout << "| 6. Logout                |\n";
        cout << "|==========================|\n";
        cout << "Enter your choice (1-6): ";

        cin >> choice;
        cin.ignore(); // Consume the newline character

        switch (choice)
        {
        case 1:
            displayUserInfo(user, userList);
            
            break;
        case 2:
            if(user.addBike(bikes)){
                cout<< "Add bike succesfully ! \n";
            }else{
                cout<< "Failed to add bike \n";
            }

            break;
        case 3:
            addCredit(user,userList);

            break;
        case 4:
            viewBikeDash(user, bikes, request);
            break;
        case 5:
            
            break;
        case 6: 
            user = User();
            dashboardRun = true;
            cout << "Logging out...\n";
            break;
        default:
            cout << "Invalid choice. Please enter a valid option (1-4).\n";
            break;
        }

        // Pause to allow the user to read the message
        cout << "Press Enter to continue...";
        cin.ignore();
    }
}

void admin_dashboard(Admin &admin, vector<Motorbike> &bikes, vector<User> &userList) {
    int choice;
    bool dashboardRun = false;

    while (!dashboardRun)
    {

        system("cls");

        // Display the admin dashboard menu
        cout << "|==========================|\n";
        cout << "|      Admin Dashboard     |  Hello, " << "\n"; // TODO: Admin info
        cout << "|==========================|\n";
        cout << "| 1. View all users        |\n";
        cout << "| 2. View all motorbikes   |\n";
        cout << "| 3. Logout                |\n";
        cout << "|==========================|\n";
        cout << "Enter your choice (1-3): ";

        cin >> choice;
        cin.ignore(); // Consume the newline character

        switch (choice)
        {
        case 1:
        system("cls");
            admin.viewAccounts(userList);
            //viewAdminUserDash(userList);
            break;
        case 2:
            system("cls");
            admin.viewMotorbikeInfo(bikes);
            // viewAdminBikeDash(bikes);
            break;
        case 3:
            dashboardRun = true;
            cout << "Logging out...\n";
            break;
        default:
            cout << "Invalid choice. Please enter a valid option (1-4).\n";
            break;
        }

        // Pause to allow the user to read the message
        cout << "Press Enter to continue...";
        cin.ignore();
    }

};

void viewGuestBikeDash(vector<Motorbike> &bikes, string cityStr)
{
    system("cls");
    int choice;
    bool dashboardRun = false;
    City city;
    if (cityStr == "Ha noi") {
        city = City::Hanoi;
    }
    else {
        city = City::Saigon;
    }

    cout << left << setw(12) << "Motorbike ID" << setw(20) << "Model" << setw(10) << "Color" << setw(10) << "Engine" << setw(15) << "Owner" << setw(12) << "Year" << setw(20) << "Description" << setw(8) << "Rating" << endl;
    cout << setfill('-') << setw(100) << "-" << setfill(' ') << endl;
    for (Motorbike &bike : bikes)
    {
        if (bike.getCity() == city) {
             cout << left << setw(12) << bike.getMotorbikeId()
             << setw(20) << bike.getModel()
             << setw(10) << bike.getColor()
             << setw(10) << bike.getEngine()
             << setw(15) << bike.getOwner()
             << setw(12) << bike.getYear()
             << setw(20) << bike.getDes()
             << setw(8) << bike.getRating()
             << "\n";
        }
    }
}

void viewBikeDash(User &user, vector<Motorbike> &bikes,vector<Request> requests)
{
    system("cls");
    int choice; 
    bool dashboardRun= false;

    while(!dashboardRun){
        cout << left << setw(12) << "Motorbike ID" << setw(20) << "Model" << setw(10) << "Color" << setw(10) << "Engine" << setw(15) << "Owner" << setw(12) << "Year" << setw(20) << "Description" << setw(8) << "Rating" << endl;
        cout << setfill('-') << setw(100) << "-" << setfill(' ') << endl;
    for (Motorbike &bike : bikes)
    {
        // TODO: city filter!!
        cout << left << setw(12) << bike.getMotorbikeId()
             << setw(20) << bike.getModel()
             << setw(10) << bike.getColor()
             << setw(10) << bike.getEngine()
             << setw(15) << bike.getOwner()
             << setw(12) << bike.getYear()
             << setw(20) << bike.getDes()
             << setw(8) << bike.getRating()
             << endl;
    }
    cout<<"\n\n";
    cout<< "1.Search for the bike. \n";
    cout<< "2.Rent a bike. \n";
    cout<< "3.Exit\n";
    cout<< "Enter your choice(1-3): ";
    cin>>choice;
    cin.ignore();
    switch(choice){
        case 1: 
            searchDisPlay(user,bikes);
            break;
        case 2:

        break;
        case 3:
            dashboardRun = true;
            cout << "Logging out...\n";
            break;
        default: 
            cout<< "Invalid input! Please enter it correctly. \n";
    }
    cout << "Press Enter to continue...";
    cin.ignore();
    }
    
}

void displayUserInfo(User &user, vector<User> &userList)
{
    system("cls");
    bool flag = false;
    int choice;
        cout << "Username: " << user.getUsername() << endl;
        cout << "Full Name: " << user.getFullName() << endl;
        cout << "Phone Number: " << user.getPhoneNumber() << endl;
        cout << "ID Type: " << user.getIdType() << endl;
        cout << "ID Number: " << user.getIdNum() << endl;
        cout << "License Number: " << user.getLicenseNum() << endl;
        cout << "License Expiry Date: " << user.getExDate() << endl;
        cout << "City: " << (user.getCity() == City::Saigon ? "Saigon" : "Hanoi") << endl;
        cout << "----------------------------------" << endl;
        
        
    while (true) {
    cout << "Choose an option:\n";
    cout << "1. Change Password\n";
    cout << "2. Exit\n";
    cout<< "Enter your choice: ";
    cin >> choice;
    cin.ignore();

    switch (choice) {
        case 1: {
            string oldPass;
            cout << "Enter your old password: ";
            getline(cin, oldPass);

            if (oldPass == user.getPassword()) {
                string newPass;
                cout << "Enter your new password: ";
                getline(cin, newPass);

                user.setPassword(newPass);
                cout << "Password changed successfully.\n";

                
                for (auto &u : userList) {
                    if (user.getUsername() == u.getUsername()) {
                        u.setPassword(newPass);
                        break; 
                    }
                }
            } else {
                cout << "Incorrect old password. Password not changed.\n";
            }
            break;
        }

        case 2:
            return; 
    }
}

}

void addCredit(User &user, vector<User> &userList)
{
    string input;
    regex regexp("^(-?)(0|([1-9][0-9]*))(\\.[0-9]+)?$");
    while (true) {
        cout << "Enter amount of points (Q to quit): ";
        getline(cin, input);
        if (input == "Q" || input == "q") {
            break;
        } else {
            if (!regex_match(input, regexp)) {
                cout << "Invalid input! Please enter again!";
            } else {
                double credit = stod(input);
                if (credit <= 0) {
                    cout << "Please input a valid amount. \n";
                } else {
                    user.setCreditPoint(user.getCreditPoint() + credit);
                    for (auto& u : userList) {
                        if (user.getUserName() == u.getUserName()) {
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

void searchDisPlay(User &user, vector<Motorbike> &bikes){
    system("cls");
    int choice;
    bool dashboardRun = false;
    // TODO: Search engine implementation (member’s credit points / rating / city)
    double desiredPoints = -1.0; // default minimum value
    double desiredRating = -1.0; // default minimum value
    string desiredCity = ""; // default value

    cout << "Do you want to use the search filter?\n"
         << endl;
    cout << "Please enter 1 to use the search filter\n"
         << endl;
    cout << "             2 not to use the search filter\n"
         << endl;
    string searchFilterUsage;
    cin >> searchFilterUsage;

    if (searchFilterUsage == "1")
    {
        cout << "    Search Filter    \n";
        cout << "======================\n";

        while (true)
        {
            cout << "Enter desired points (>=0): ";
            cin >> desiredPoints;

            if (desiredPoints >= 0)
            {
                break;
            }

            std::cout << "Invalid point value. Please enter a positive number.\n";
        }

        while (true)
        {
            cout << "Enter desired rating (>=0): ";
            cin >> desiredRating;

            if (desiredRating >= 0)
            {
                break;
            }

            std::cout << "Invalid rating value. Please enter a positive number.\n";
        }

        while (true)
        {
            std::cout << "Enter your city (Saigon or Hanoi): ";
            std::cin >> desiredCity;

            if (desiredCity == "Saigon" || desiredCity == "Hanoi")
            {
                break;
            }

            std::cout << "Invalid city. Please enter Saigon or Hanoi.\n";
        }
    }

    cout << left << setw(12) << "Motorbike ID" << setw(20) << "Model" << setw(10) << "Color" << setw(10) << "Engine" << setw(15) << "Owner" << setw(12) << "Year" << setw(20) << "Description" << setw(8) << "Rating" << endl;
    cout << setfill('-') << setw(100) << "-" << setfill(' ') << endl;
    for (Motorbike &bike : bikes)
    {
        // TODO: city filter!!
        if (bike.getConsumingPoints() >= desiredPoints && bike.getRating() >= desiredRating) {
            cout << left << setw(12) << bike.getMotorbikeId()
             << setw(20) << bike.getModel()
             << setw(10) << bike.getColor()
             << setw(10) << bike.getEngine()
             << setw(15) << bike.getOwner()
             << setw(12) << bike.getYear()
             << setw(20) << bike.getDes()
             << setw(8) << bike.getRating()
             << endl;
        }  
    }
    while (!dashboardRun)
    {

        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();
    }
}