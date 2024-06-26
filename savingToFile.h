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

class saveToFile
{
    const string accountFile = "Account.txt";
    const string motobikeFile = "Motorbike.txt";
    const string requestFile = "Request.txt";
    const string borrowFile = "Borrow.txt";
    const string ratingFile = "Rating.txt";

public:
    void SaveAccountToFile(vector<User> &users);
    vector<User> loadAccount(vector<Motorbike> &moto, vector<Request> &requests, vector<UserRating> &ratings, vector<Borrow> &borrowList);
    void SaveMotobikeToFile(vector<Motorbike> &moto);
    vector<Motorbike> loadMotor(vector<Request> &requests, vector<MotorbikeRating> &ratings);
    void SaveRequestToFIle(vector<Request> &request);
    vector<Request> loadRequest();
    void saveBorrowToFile(vector<Borrow> &borrow);
    vector<Borrow> loadBorrow();
    void saveRatingToFile(vector<UserRating> &uraitngs, vector<MotorbikeRating> &mRatings);
    void loadRating(vector<UserRating> &uraitngs, vector<MotorbikeRating> &mRatings);
};

#endif
