#include<iostream>
#include <fstream>
#include "savingToFile.h"
#include "Account/User.h"
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

void saveToFile::SaveMotobikeToFile(vector<Motobike> &moto)
{
}

vector<Motobike> saveToFile::loadMotor()
{
    return vector<Motobike>();
}

void saveToFile::SaveRequestToFIle(vector<Request> &request)
{
}

vector<Request> saveToFile::loadRequest()
{
    return vector<Request>();
}

void saveToFile::saveBorrowToFile(vector<Borrow> &borrow)
{
}

vector<Borrow> saveToFile::loadBorrow()
{
    return vector<Borrow>();
}

void saveToFile::saveRatingToFile(vector<Rating> &ratings)
{
}

vector<Rating> saveToFile::loadRating()
{
    return vector<Rating>();
}
