// main.cpp
#include "Account/User.h"
#include "savingToFile.h"
#include "Account/Account.h"
#include<iostream>
int main() {
     User user1("User1", "Password1", "John Doe", "12345", "asd","ID1",  "License123", "2023-12-31", 100.0);
    User user2("User2", "Password2", "Jane Smith", "67890", "asd","ID2",  "License456", "2023-11-30", 150.0);

    // Create a vector to store User objects
    std::vector<User> users;
    users.push_back(user1);
    users.push_back(user2);

    // Create a SaveToFile object and save User objects to a file
    saveToFile fileSave;
    fileSave.SaveAccountToFile(users);
    User user;
std::vector<User> newUser= fileSave.loadAccount(); 
    while (true){
        int choice;
        cout<< "Choose 1 to register";
        cin>>choice;
        if(choice == 1){ 
            user.registerAccount("User1","123", 20,newUser,"Huynh","fasd","123123", "pass","123123","sadfla");
            break;
        }
    }
       
    for(auto user: newUser){
        cout<< user.toStringAccount()<< "\n";
    }
    cout<<" hello";
    return 0;
}
