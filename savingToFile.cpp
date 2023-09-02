#include<iostream>
#include <fstream>
#include "savingToFile.h"
#include "Account/User.h"
#include "Motorbike.h"
using namespace std;

void saveToFile::SaveAccountToFile(vector<User>& users)
{
    ofstream myFile(accountFile);
    if(myFile.is_open()){
        for(User &user: users){
                myFile << user.toStringAccount()<<"\n";
        }
        myFile.close();
    }else{
        cout<< "Error opening account file";
    }
}

vector<User> saveToFile::loadAccount()
{
    vector <User> users;
    fstream myFile(accountFile, ios::in);
    string line;
    
    while(getline(myFile,line)){
        stringstream ss(line);
        vector<string> tokens;
        string token;
        while(getline(ss, token,',')){
            tokens.push_back(token);
        }

        if(tokens.size() == 9){
            double creaditPoint = stod(tokens[8]);
            User user(tokens[0],tokens[1],tokens[2],tokens[3], tokens[4],tokens[5], tokens[6],tokens[7], creaditPoint);
            users.push_back(user);
        }
    }
        myFile.close();
    return users;
}

void saveToFile::SaveMotobikeToFile(vector<Motorbike> &moto)
{
    ofstream myFile(motobikeFile);
    if(myFile.is_open()){
        for(auto &motor: moto ){
            myFile<< motor.toStringMotorBike()<< "\n";
        }
        myFile.close();
    }else{
        cout<< "Error opening motorbike file";
    }
}

// vector<Motorbike> saveToFile::loadMotor()
// {
//     vector <Motorbike> motors;
//     fstream myFile(motobikeFile, ios:: in);
//     string line;


//     while(getline(myFile, line)){
//         stringstream ss(line);
//         vector<string> tokens;
//         string token;
//         while(getline(ss,token,',')){
//             tokens.push_back(token);
//         }

//         if(tokens.size()== 11){
//             // double yearMade= stod(tokens[5]);
//             // double consumingPoints= stod(tokens[7]);
//             // double retalAmount = stod(tokens[8]);
//             // double minRenterRating= stod (tokens[9]);
//             // double motorBikeRating= stod (tokens[10]);
//             // Motorbike motor(tokens[0],tokens[1],tokens[2],tokens[3],tokens[4],yearMade,tokens[6],consumingPoints,retalAmount,minRenterRating,motorBikeRating);
//         }
//     }
// }

// void saveToFile::SaveRequestToFIle(vector<Request> &request)
// {
// }

// vector<Request> saveToFile::loadRequest()
// {
//     return vector<Request>();
// }

// void saveToFile::saveBorrowToFile(vector<Borrow> &borrow)
// {
// }

// vector<Borrow> saveToFile::loadBorrow()
// {
//     return vector<Borrow>();
// }

// void saveToFile::saveRatingToFile(vector<Rating> &ratings)
// {
// }

// vector<Rating> saveToFile::loadRating()
// {
//     return vector<Rating>();
// }
