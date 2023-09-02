#include "Account/User.h"
#include "savingToFile.h"
#include "Account/Account.h"
#include "Rating.h"
#include "Request.h"
#include "TimeSlot.h"
#include <iostream>
#include "Borrow.h"







int main()
{   
    User user;
    saveToFile fileSave;
    std::vector<User> userList = fileSave.loadAccount();
    
    cout<< "EEET2482/COSC2082 ASSIGNMENT"<< "\n";
    cout<< "MOTORBIKE RENTAL APPLICATION."<< "\n\n";

    cout<< "Instructor: Dr. Ling Hou Chong"<< "\n";
    cout<< "Group: 3"<< "\n";
    cout<< "s3929218, Student Name: Huynh Tan Phat"<< "\n";
    cout<< "s3929218, Student Name: Huynh Tan Phat"<< "\n";
    cout<< "s3929218, Student Name: Huynh Tan Phat"<< "\n";
    cout<< "s3929218, Student Name: Huynh Tan Phat"<< "\n\n";


    int choice;
    cout<< "Use the app as 1.Guest  2. Member  3.Admin  4.Register\n\n";
    while (true){
        cout << "Enter your choice: ";
        cin>> choice;
        if(choice == 1){
            // display all bikes 
        }else if(choice == 2){
            string username;
            string pass;
            cout<< "Enter username: ";
            getline(cin,username);
            cout<< "Enter password: ";
            getline(cin, pass);
            if(user.login(username, pass, userList)){
                cout<< "Hahalo";
            }
        }else if(choice == 3){
            
        }else{
        
        }
    }




















    fileSave.SaveAccountToFile(userList);
    return 0;
}
