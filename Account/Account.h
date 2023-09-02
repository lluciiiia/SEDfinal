//account_h
#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
using namespace std;

class Account{
    private: 
        std:: string username;
        std:: string password;
        std:: string full_name;
        std:: string phone_number;
        public:
        Account(std::string username, std::string password, std::string full_name, std:: string phone_number);
    
    public: 

    string getUsername();

    string getPassword();


    string getFull_Name();

    string getPhoneNumber();

    void setUsername(string userName);

    void setPassword(string pass);
    void setFull_Name(string full_name);

    void setPhone_number(string phone_Number);
};






#endif

