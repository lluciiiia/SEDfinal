#include "Admin.h"
#include <iostream>

using namespace std;

Admin::Admin()
: Account("", "", "", "")
// TODO: default
{
    
}

Admin::Admin(string username,
             string password,
             string fullName,
             string phone_number,
             string adminID)
    : Account(username, password, fullName, phoneNumber), adminID(adminID)
{
    // Parameterized constructor implementation
}

void Admin::viewMemberInfo()
{
}

void Admin::viewMotorbikeInfo()
{
}

void Admin::viewAccounts()
{
}
