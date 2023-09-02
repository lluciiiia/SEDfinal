#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
using namespace std;

class Account{
    private: 
        std:: string username;
        std:: string password;
        std:: string fullName;
        std:: string phoneNumber;
        public:
        Account(std::string username, std::string password, std::string fullName, std::string phoneNumber);
    
    public: 

    string getUsername();
    string getPassword();
    string getFullName();
    string getPhoneNumber();

    void setUsername(string userName);

    void setPassword(string pass);
    void setFullName(string fullName);

    void setPhoneNumber(string phoneNumber);
};


#endif

