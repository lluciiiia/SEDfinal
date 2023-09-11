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
// #include "Borrow.h"

using namespace std;



void user_dashboard(User &user, vector<Motorbike> &bikes);

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
            case 3:{
                break;
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
        cout << "|      User Dashboard      |  Hello, "<< user.getUsername()<< "\n";
        cout << "|==========================|  Credit point: " << user.getCreditPoint()<< "\n";
        cout << "| 1. Add your motorbike    |  Your owned bike: " << model <<"\n";
        cout << "| 2. View Orders           |\n";
        cout << "| 3. Make a Reservation    |\n";
        cout << "| 4. Logout                |\n";
        cout << "|==========================|\n";
        cout << "Enter your choice (1-4): ";

        cin >> choice;
        cin.ignore(); // Consume the newline character

        switch (choice) {
            case 1:
                
                user.addBike(bikes);
                
                break;
            case 2:
                
               
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
        }

        // Pause to allow the user to read the message
        cout << "Press Enter to continue...";
        cin.ignore();
    }

}