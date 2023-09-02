#ifndef SAVINGTOFILE_H
#define SAVINGTOFILE_H

#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
#include "Motorbike.h"
#include "Account/User.h"
#include "Borrow.h"
#include "Request.h"
#include "Rating.h"
using namespace std;

class saveToFile{
    const string accountFile= "Account.txt";
    const string motobikeFile= "Motobike.txt";
    const string requestFile= "Request.txt";
    const string borrowFile= "Borrow.txt";
    const string ratingFile= "Ratting.txt";

    public: 
    void SaveAccountToFile( vector<User>&users) ;
    vector<User> loadAccount();
    void SaveMotobikeToFile(vector <Motorbike> &moto);
    vector<Motorbike> loadMotor();
    void SaveRequestToFIle(vector <Request> &request);
    vector <Request> loadRequest();
    void saveBorrowToFile(vector<Borrow> &borrow);
    vector <Borrow> loadBorrow();
    void saveRatingToFile(vector <Rating> &ratings);
    vector <Rating> loadRating();
};


#endif


