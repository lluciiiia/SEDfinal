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
             string phoneNumber,
             string adminID)
    : Account(username, password, fullName, phoneNumber), adminID(adminID)
{
    this->adminID = adminID;
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

string Admin::getAdminID() const
{
}

void Admin::setAdminID(string adminID)
{
    this->adminID = adminID;
}
