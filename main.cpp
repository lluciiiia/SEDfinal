#include "Account/User.h"
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
// #include "Borrow.h"

using namespace std;

void guest_dashboard(vector<Motorbike> &bikes);
void user_dashboard(User &user, vector<Motorbike> &bikes, vector<User> &userList);
void admin_dashboard(vector<Motorbike> &bikes, vector<User> &userList);
void viewGuestBikeDash(vector<Motorbike> &bikes, string city);
void viewAdminBikeDash(vector<Motorbike> &bikes);
void viewAdminUserDash(vector<User> &userList);
void viewBikeDash(User &user, vector<Motorbike> &bikes);
void displayUserInfo(User &user, vector<User> &userList);

int main()
{
    User user;
    saveToFile fileSave;
    vector<Motorbike> motorbikeList = fileSave.loadMotor();
    vector<User> userList = fileSave.loadAccount(motorbikeList);

    City city = City::Saigon;

    // User user1("john_doe", "password123", "John Doe", "1234567890", "Passport", "ID12345", "License67890", "2023-12-31", 100.0, city);

    // User user2("alice_smith", "securePass123", "Alice Smith", "9876543210", "Driver's License", "DL6789", "License98765", "2023-11-30", 150.0,city);

    // userList.push_back(user1);
    // userList.push_back(user2);

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
    cout << "s3929218, Student Name: Huynh Tan Phat"
         << "\n";
    cout << "s3929218, Student Name: Huynh Tan Phat"
         << "\n\n\n";

    bool exitProgram = false;

    while (!exitProgram)
    {
        int choice;
        cout << "MOTORBIKE RENTAL APPLICATION."
             << "\n\n";
        cout << "Use the app as 1. Guest  2. Member  3.Admin  4.Register  5. Exit the program\n\n";
        cin >> choice;
        cin.ignore();
        switch (choice)
        {
        case 1:
        {
            cout << "Logging in as a Guest \n";
            cout << "Your are on a Guest Mode.\n";

            guest_dashboard(motorbikeList);
            system("cls");

            break;
        }
        case 2:
        {
            cout << "Logging in as a Member\n";
            cout << "Your are logging in.\n";
            if (login(user, userList))
            {
                user_dashboard(user, motorbikeList, userList);
                system("cls");
            }
            else
            {
                cout << "Login fail! Wrong username or password! \n";
            }
            break;
        }
        case 3:
        {
            // TODO: check if the login is admin account
            cout << "Logging in as a Admin \n";
            cout << "Your are on a Admin Mode.\n";

            admin_dashboard(motorbikeList, userList);
            system("cls");
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
        }
    }

    fileSave.SaveAccountToFile(userList);
    fileSave.SaveMotobikeToFile(motorbikeList);
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

void user_dashboard(User &user, vector<Motorbike> &bikes, vector<User> &userList)
{
    int choice;
    bool dashboardRun = false;

    while (!dashboardRun)
    {

        system("cls");
        string model;
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
        cout << "| 1. Add your motorbike    |  Your owned bike: " << model << "\n";
        cout << "| 2. View Bikes to rent    |\n";
        cout << "| 3. View request          |\n";
        cout << "| 4. Logout                |\n";
        cout << "|==========================|\n";
        cout << "Enter your choice (1-4): ";

        cin >> choice;
        cin.ignore(); // Consume the newline character

        switch (choice)
        {
        case 1:
            //displayUserInfo(user, userList);
            user.addBike(bikes);
            break;
        case 2:
            viewBikeDash(user, bikes);

            break;
        case 3:
            

            break;
        case 4:
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

void admin_dashboard(vector<Motorbike> &bikes, vector<User> &userList) {
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
            viewAdminUserDash(userList);
            break;
        case 2:
            viewAdminBikeDash(bikes);
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

void viewAdminBikeDash(vector<Motorbike> &bikes)
{
    system("cls");
    int choice;
    bool dashboardRun = false;
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

void viewAdminUserDash(vector<User> &users) 
{
    system("cls");
    int choice;
    bool dashboardRun = false;
    
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


void viewBikeDash(User &user, vector<Motorbike> &bikes)
{
    system("cls");
    int choice;
    bool dashboardRun = false;
    cout << left << setw(12) << "Motorbike ID" << setw(20) << "Model" << setw(10) << "Color" << setw(10) << "Engine" << setw(15) << "Owner" << setw(12) << "Year" << setw(20) << "Description" << setw(8) << "Rating" << endl;
    cout << setfill('-') << setw(100) << "-" << setfill(' ') << endl;
    for (Motorbike &bike : bikes)
    {
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
    while (!dashboardRun)
    {

        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();
    }
}

void displayUserInfo(User &user, vector<User> &userList)
{
    bool flag = false;
    int choice;
    while (!flag)
    {
        cout << "Username: " << user.getUsername() << endl;
        cout << "Full Name: " << user.getFullName() << endl;
        cout << "Phone Number: " << user.getPhoneNumber() << endl;
        cout << "ID Type: " << user.getIdType() << endl;
        cout << "ID Number: " << user.getIdNum() << endl;
        cout << "License Number: " << user.getLicenseNum() << endl;
        cout << "License Expiry Date: " << user.getExDate() << endl;
        cout << "City: " << (user.getCity() == City::Saigon ? "Saigon" : "Hanoi") << endl;
        cout << "----------------------------------" << endl;
        cout << "1.Change your password. \n";
        cout << "2.Return. \n";
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case 1:
        {
            string pass;
            cout << "Enter your old password: ";
            getline(cin, pass);
            if (pass == user.getPassword())
            {
                string passw;
                cout << "Enter your new password: ";
                getline(cin, passw);
                user.setPassword(passw);
                cout << "Change password sucessfully. ";
                for (auto &u : userList)
                {
                    if (user.getUsername() == u.getUsername())
                    {
                        u.setPassword(passw);
                    }
                }
            }
            else
            {
                cout << "Wrong password. \n";
            }
            break;
        }

        case 2:
            flag = true;
            break;
        }
    }
}