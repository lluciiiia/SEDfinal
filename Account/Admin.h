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

    void viewMemberInfo();
    void viewMotorbikeInfo();
    void viewAccounts();

    // TODO: getters/setters
};

#endif