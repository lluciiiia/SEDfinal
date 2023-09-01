#ifndef SAVINGTOFILE_H
#define SAVINGTOFILE_H

#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
#include "Motobike.h"
#include "Account/User.h"
#include "Borrow.h"
#include "Request.h"
using namespace std;



class saveToFile{
    const string accountFile= "Account.txt";
    const string motobikeFile= "Motobike.txt";
    const string requestFile= "Request.txt";
    const string borrowFile= "Borrow.txt";


    public: 
    void SaveAccountToFile( vector<User>&users) ;
    vector<User> loadAccount();
};


#endif


