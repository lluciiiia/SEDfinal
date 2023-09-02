#include "Account.h"
#include <iostream>
using namespace std;


Account::Account(std::string username, std::string password, std::string full_name, std:: string phone_number): username(username), password(password),full_name(full_name),phone_number(phone_number){}

    string Account::getUsername(){
        return username;
    }

    string Account::getPassword(){
        return password;
    }


    string Account:: getFull_Name(){
        return full_name;
    }

    string Account:: getPhoneNumber(){
        return phone_number;
    }


    
    void Account:: setUsername(string userName){
        this->username= userName;
    }

    void Account::setPassword(string pass){
        this->password = pass;
    }
    void Account::setFull_Name(string full_name){
        this->full_name =full_name;
    }

    void Account::setPhone_number(string phone_Number){
        this-> phone_number = phone_Number;
    }
