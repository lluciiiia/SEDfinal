//account_h
#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>


class Account{
    private: 
        std:: string username;
        std:: string password;
        std:: string full_name;
        std:: string phone_number;
        public:
        Account(std::string username, std::string password, std::string full_name, std:: string phone_number);
    

};






#endif