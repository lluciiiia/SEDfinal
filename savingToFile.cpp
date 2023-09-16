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

vector<User> saveToFile::loadAccount(vector<Motorbike> &moto, vector <Request> &requests)
{
    vector<User> users;
    fstream myFile(accountFile, ios::in);
    string line;

    while (getline(myFile, line))
    {
        stringstream ss(line);
        vector<string> tokens;
        string token;
        while (getline(ss, token, ','))
        {
            tokens.push_back(token);
        }

        if (tokens.size() == 10) 
        {
            double creditPoint = stod(tokens[8]); 
            City myCity;
            if (tokens[9] == "Saigon")
            {
                myCity = City::Saigon;
            }
            else if (tokens[9] == "Hanoi")
            {
                myCity = City::Hanoi;
            }
            User user(tokens[0], tokens[1], tokens[2], tokens[3], tokens[4], tokens[5], tokens[6], tokens[7], creditPoint, myCity);
            users.push_back(user);
        }
    }


    for(auto &user : users){
        for(auto &mot : moto){
            if(user.getUsername() == mot.getOwner()){
                user.getOwned().push_back(mot);
            }
        }
    }
  
     for(auto &user : users){
        for(auto &re : requests){
            if(user.getUsername() == re.getRequester()){
                user.getSentRequests().push_back(re);
            }
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

vector<Motorbike> saveToFile::loadMotor(vector<Request> &requests)
{
    vector <Motorbike> motors;
    fstream myFile(motobikeFile, ios:: in);
    string line;


    while(getline(myFile, line)){
        stringstream ss(line);
        vector<string> tokens;
        string token;
        while(getline(ss,token,',')){
            tokens.push_back(token);
        }

        if(tokens.size()== 15){
            int motorBike= stoi(tokens[1]);
            int yearMade= stoi(tokens[7]);
            double consumingPoints= stod(tokens[9]);
            double retalAmount = stod(tokens[10]);
            double minRating= stod(tokens[11]);
            City myCity;
            if (tokens[4] == "Saigon")
            {
                myCity = City::Saigon;
            }
            else if (tokens[4] == "Hanoi")
            {
                myCity = City::Hanoi;
            }
            bool avai;
            if(tokens[12] == "true"){
                avai =true;
            }else if(tokens[12] == "false"){
                avai= false;
            }
            TimeSlot time= TimeSlot(tokens[13],tokens[14]);
            Motorbike motor = Motorbike(tokens[0], motorBike, tokens[2], tokens[3], myCity, tokens[5], tokens[6], yearMade, tokens[8], consumingPoints, retalAmount,minRating,avai,time);
            motors.push_back(motor);

        }
    }
    
    for(auto &mo : motors){
        for(auto &re : requests){
            if(mo.getMotorbikeId() == re.getMotorbikeID()){
                mo.getRequests().push_back(re);
            }
        }
    }
    myFile.close();
    return motors;
}

void saveToFile::SaveRequestToFIle(vector<Request> &request)
{
    ofstream myFile(requestFile);
    if(myFile.is_open()){
        for(Request &re: request){
                myFile << re.requestToString()<<"\n";
        }
        myFile.close();
    }else{
        cerr<< "Error opening account file";
    }
}

vector<Request> saveToFile::loadRequest()
{
    vector<Request> requests;
    fstream myFile(requestFile, ios:: in);
    string line;
while(getline(myFile, line)){
        stringstream ss(line);
        vector<string> tokens;
        string token;
        while(getline(ss,token,',')){
            tokens.push_back(token);
        }

        if(tokens.size()== 5){
            TimeSlot time= TimeSlot(tokens[3],tokens[4]);
            RequestStatus sta;
            if (tokens[2] == "PENDING")
            {
                sta = RequestStatus::PENDING;
            }
            else if (tokens[2] == "ACCEPTED")
            {
                sta = RequestStatus::ACCEPTED;
            }else if(tokens[2] == "REJECTED"){
                sta = RequestStatus::REJECTED;
            }
            int motobikeID= stoi(tokens[1]);
            Request reque = Request(tokens[0],motobikeID,time,sta);
            requests.push_back(reque);
        }
    }

    myFile.close();
    
    return requests;
    
}

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
