#ifndef ADMIN_H
#define ADMIN_H

#include <string>
#include <vector>
#include "Account.h"

class Admin : public Account
{
private:
    string adminID;

public:
    Admin();
    Admin(string username,
          string password,
          string fullName,
          string phoneNumber,
          string adminID);

    //Need to implment adminList, maybe have a file containing pre-provided admin info and load from that file
    bool login(Admin &admin, vector<Admin> adminList); 
    void viewMemberInfo(User user);
    void viewMotorbikeInfo(Motorbike motorbike);
    void viewAccounts(Account account);

    string getAdminID() const;
    void setAdminID(string adminID);
};

#endif
