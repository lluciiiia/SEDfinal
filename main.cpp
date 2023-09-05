#include "Account/User.h"
#include "savingToFile.h"
#include "Account/Account.h"
#include "City.h"
// #include "Rating.h"
// #include "Request.h"
// #include "TimeSlot.h"
#include <iostream>
// #include "Borrow.h"


int main()
{   
    
    User user;
    saveToFile fileSave;
    std::vector<User> userList = fileSave.loadAccount();
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
        cout<< "Use the app as 1.Guest  2. Member  3.Admin  4.Register  5.Exit the program\n\n";
        cin>> choice;
        cin.ignore();
        switch(choice){
            case 1:{
                break;
            }
            case 2:{
                cout<< "Logging in \n";
                cout<< "Please enter your account\n";
                
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
    return 0;
}
