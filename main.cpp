#include "Account/User.h"
#include "savingToFile.h"
#include "Account/Account.h"
#include "City.h"
#include "Motorbike.h"
// #include "Rating.h"
// #include "Request.h"
// #include "TimeSlot.h"
#include <iostream>
#include<cstdlib>
#include <iomanip>
// #include "Borrow.h"

using namespace std;

<<<<<<< Updated upstream
=======
void guest_dashboard(vector<Motorbike> &bikes);
void user_dashboard(User &user, vector<Motorbike> &bikes, vector<User> &userList);
void admin_dashboard(Admin &admin, vector<Motorbike> &bikes, vector<User> &userList);
void viewGuestBikeDash(vector<Motorbike> &bikes, string city);
void viewBikeDash(User &user, vector<Motorbike> &bikes);
void displayUserInfo(User &user, vector<User> &userList);
>>>>>>> Stashed changes


void user_dashboard(User &user, vector<Motorbike> &bikes);
void viewBikeDash(User &user,vector<Motorbike> &bikes);
int main()
{   
    User user;
    saveToFile fileSave;
    vector <Motorbike> motorbikeList=fileSave.loadMotor();
    vector<User> userList = fileSave.loadAccount(motorbikeList);
    
     City city= City:: Saigon;


    // User user1("john_doe", "password123", "John Doe", "1234567890", "Passport", "ID12345", "License67890", "2023-12-31", 100.0, city);

    // User user2("alice_smith", "securePass123", "Alice Smith", "9876543210", "Driver's License", "DL6789", "License98765", "2023-11-30", 150.0,city);

    // userList.push_back(user1);
    // userList.push_back(user2);
    
    cout<< "EEET2482/COSC2082 ASSIGNMENT"<< "\n";
    cout<< "MOTORBIKE RENTAL APPLICATION."<< "\n\n";

    cout<< "Instructor: Dr. Ling Hou Chong"<< "\n";
    cout<< "Group: 3"<< "\n";
    cout<< "s3929218, Student Name: Huynh Tan Phat"<< "\n";
    cout<< "s3929218, Student Name: Huynh Tan Phat"<< "\n";
    cout<< "s3929218, Student Name: Huynh Tan Phat"<< "\n";
    cout<< "s3929218, Student Name: Huynh Tan Phat"<< "\n\n\n";

    bool exitProgram= false;
    
    while (!exitProgram){
        int choice;
        cout<< "MOTORBIKE RENTAL APPLICATION."<< "\n\n";
        cout<< "Use the app as 1.Guest  2. Member  3.Admin  4.Register  5.Exit the program\n\n";
        cin>> choice;
        cin.ignore();
        switch(choice){
            case 1:{
                break;
            }
            case 2:{
                cout<< "Logging in \n";
                cout<< "Your are logging in.\n";
                if(login(user,userList)){
                    user_dashboard(user,motorbikeList );
                    system("cls");
                }else{
                    cout<< "Login fail! Wrong username or password! \n";
                }
                break;
            }
<<<<<<< Updated upstream
            case 3:{
                break;
=======
            break;
        }
        case 3:
        {
            // TODO: check if the login is admin account
            cout << "Logging in as a Admin \n";
            cout << "Your are on a Admin Mode.\n";

            if ( admin.adminLogin() ) {
                admin_dashboard(admin, motorbikeList, userList);
                system("cls");
            } 
            else {
                cout << "Login failed! Incorrect admin username/password\n";
>>>>>>> Stashed changes
            }
            case 4:{
                if(user.registerAccount(userList)){
                    cout<< "Register successfully\n";
                }else{
                    cout<< "Fail\n";
                }
                break;
            }
            case 5:{
                exitProgram= true;
                cout<< "Bye! See you later!! \n";
                break;
            }
        }
    }




    fileSave.SaveAccountToFile(userList);
    fileSave.SaveMotobikeToFile(motorbikeList);
    return 0;
}







void user_dashboard(User &user, vector<Motorbike> &bikes){
    int choice;
    bool dashboardRun= false;
    
    while (!dashboardRun) {
    
        system("cls");
        string model;
         for(auto &bike : bikes){
        if(bike.getOwner() == user.getUsername()){
            model=bike.getModel(); 
        }
    }
        // Display the user dashboard menu
        cout << "|==========================|\n";
<<<<<<< Updated upstream
        cout << "|      User Dashboard      |  Hello, "<< user.getUsername()<< "\n";
        cout << "|==========================|  Credit point: " << user.getCreditPoint()<< "\n";
        cout << "| 1. Add your motorbike    |  Your owned bike: " << model <<"\n";
        cout << "| 2. View Bikes to rent    |\n";
        cout << "| 3. View request          |\n";
        cout << "| 4. Logout                |\n";
=======
        cout << "|      User Dashboard      |  Hello, " << user.getUsername() << "\n";
        cout << "|==========================|  Credit point: " << user.getCreditPoint() << "\n";
        cout << "| 1. View your bio         |  Your owned bike: " << model << "\n";
        cout << "| 2. Add your motorbike    |\n";
        cout << "| 3. View Bikes to rent    |\n";
        cout << "| 4. View request          |\n";
        cout << "| 5. Logout                |\n";
>>>>>>> Stashed changes
        cout << "|==========================|\n";
        cout << "Enter your choice (1-5): ";

        cin >> choice;
        cin.ignore(); // Consume the newline character

<<<<<<< Updated upstream
        switch (choice) {
            case 1:
                
                user.addBike(bikes);
                
                break;
            case 2:
                viewBikeDash(user,bikes);
               
                break;
            case 3:
                
            
                break;
            case 4:
                dashboardRun= true;
                cout << "Logging out...\n";
                break;
            default:
                cout << "Invalid choice. Please enter a valid option (1-4).\n";
                break;
=======
        switch (choice)
        {
        case 1:
            displayUserInfo(user, userList);
            break;
        case 2:
            if(user.addBike(bikes)){
                cout<< "Add bike success ! \n";
            }else{
                cout<< "Failed to add bike\n";
            }
            break;

            
        case 3:
            viewBikeDash(user, bikes);

            break;
        case 4:

            break;
        case 5:
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
>>>>>>> Stashed changes
        }

        // Pause to allow the user to read the message
        cout << "Press Enter to continue...";
        cin.ignore();
    }

}



void viewBikeDash(User &user,vector<Motorbike> &bikes){
    system("cls");
    int choice;
    bool dashboardRun= false;
    cout << left << setw(12) << "Motorbike ID" << setw(20) << "Model" << setw(10) << "Color" << setw(10) << "Engine" << setw(15) << "Owner" << setw(12) << "Year" << setw(20) << "Description" << setw(8) << "Rating" << endl;
    cout << setfill('-') << setw(100) << "-" << setfill(' ') << endl;
<<<<<<< Updated upstream
    for ( Motorbike& bike : bikes) {
=======
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

void viewBikeDash(User &user, vector<Motorbike> &bikes)
{
    system("cls");
    int choice;
    bool dashboardRun = false;
    cout << left << setw(12) << "Motorbike ID" << setw(20) << "Model" << setw(10) << "Color" << setw(10) << "Engine" << setw(15) << "Owner" << setw(12) << "Year" << setw(20) << "Description" << setw(8) << "Rating" << endl;
    cout << setfill('-') << setw(100) << "-" << setfill(' ') << endl;
    for (Motorbike &bike : bikes)
    {
>>>>>>> Stashed changes
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
    while (!dashboardRun) {
        
        





        cout<< "Enter your choice: ";
        cin >> choice;
        cin.ignore();
    }
<<<<<<< Updated upstream
=======
}

void displayUserInfo(User &user, vector<User> &userList)
{
    system("cls");
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
    bool flag = false;
    int choice;
    while (!flag)
    {
        
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
>>>>>>> Stashed changes
}