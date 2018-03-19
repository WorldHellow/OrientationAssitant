//
//  Freshman.cpp
//  Orientation Assistant
//
//  Created by Talha Javed on 5/20/16.
//  Copyright © 2016 Talha Javed. All rights reserved.
//

#include "Freshman.hpp"
#include <iostream>
#include <fstream>
#include "Person.hpp"
using namespace std;


//constructor
Freshman::Freshman(){
    
}

//Get Registration Number
int Freshman::getRegNo(){
    return registrationNo;
}

//Get Name
string Freshman::getName(){
    return firstName + " " + lastName;
}

//Register a new freshman
void Freshman::Register(){
    cout << "Enter your first name" << endl;
    cin >> firstName;
    cout << "Enter your last name: " << endl;
    cin >> lastName;
    cout << "Enter your school. (Abbreviation in CAPS; eg, SCME)" <<endl;
    cin >> school;
    cout << "Enter number (on a scale of 1-9) corresponding to things you find interesting: " <<endl;
    
    for(int i = 0; i < 6; i++){
        cout << interestsList[i] << ": ";
        cin >> interestKeys[i];
    }
    
    /*At the end of data file, there is a new registration number stored for the next student to be registered. Here we are extracting that number and assigning to the student*/
    
    //open file that contains student data
    ifstream file("freshmen.csv");
    
    if(file.is_open()){
        
        file.seekg(0,ios::end);            //g pointer now points to one point before end of file
        char ch = ' ';
        
        while(ch != '\n'){          //until end of second last line is reached, keep moving g pointer one step backwards
            file.seekg(-2, ios::cur);
            
            if((int)file.tellg() <= 0){        //If passed the start of the file,
                file.seekg(0);                 //this is the start of the line
                break;
            }
            
            file.get(ch);
        }
        
        string x;
        getline(file,x);            //x stores the last line, which just holds a new registration number
        registrationNo = stoi(x);
        
        file.close();
        cout << "Your registration is " << registrationNo << " <-- Write this down for future login." << endl;
    }
    
    //store this new profile to csv file
    storeProfile();
}

//Log a Registered Member in
void Freshman::login(){
    string regNo;
    cout << "Enter your registration number: " <<endl;
    cin >> regNo;
    
    int flag = 0;
    string temp;
    ifstream file("freshmen.csv");
    
    if(file.is_open()){
        while(file.good()){
            getline(file,temp);
            getline(file,temp,',');
            if(temp == regNo){
                flag = 1;
                break;
            }
        }
        
        if(flag == 0){
            cout << "No Freshman registered under entered number" << endl;
        }
        else{
            registrationNo = stoi(regNo);
            getline(file,firstName,',');
            getline(file,lastName,',');
            getline(file,school,',');
            
            string x;
            for(int i = 0; i < 6; i++){
                getline(file, x, ',');
                interestKeys[i] = stoi(x);
            }
            
            for(int i = 0; i < 3; i++){
                getline(file,x,',');
                meetupInvites[i] = stoi(x);
            }
            
            for(int i = 0; i < 3; i++){
                getline(file,x,',');
                eventInvites[i] = stoi(x);
            }
        }
    }
    
    file.close();
}

//Print Freshman Data
void Freshman::showProfile(){
    cout << "-------------------" <<endl;
    cout << "Registration #: " << registrationNo << endl << "Name: " << firstName << " " << lastName  << endl << "School: " << school;
    cout << endl << "-------------------" <<endl;
}

//Store Freshman Data to file
void Freshman::storeProfile(){
    ofstream file("freshmen.csv", ios::app);
    
    //store all new data
    file << "," <<  firstName << "," << lastName << "," << school;
    for(int i = 0; i < 6; i++){
        file << "," << interestKeys[i];
    }
    
    for(int i = 0; i < 3; i++){
        file << "," << "00000000";
    }
    
    for(int i = 0; i < 3; i++){
        file << "," << "000";
    }
    
    //move to next line and set the next registration number
    file << "," << "\n" << registrationNo + 1;
}

//Get freshman by Inputting their Regn#
Freshman* Freshman::getProfileByRgn(string Regn){
    Freshman* x = new Freshman;
    
    int flag = 0;
    string temp;
    ifstream file("freshmen.csv");
    
    if(file.is_open()){
        while(file.good()){
            getline(file,temp);
            getline(file,temp,',');
            if(temp == Regn){
                flag = 1;
                break;
            }
        }
        
        if(flag == 0){
            cout << "No Freshman registered under entered number" << endl;
        }
        else{
            x->registrationNo = stoi(Regn);
            getline(file,x->firstName,',');
            getline(file,x->lastName,',');
            getline(file,x->school,',');
            
            string holder;
            for(int i = 0; i < 6; i++){
                getline(file, holder, ',');
                x->interestKeys[i] = stoi(holder);
            }
            
            for(int i = 0; i < 3; i++){
                getline(file,holder,',');
                x->meetupInvites[i] = stoi(holder);
            }
            
            for(int i = 0; i < 3; i++){
                getline(file,holder,',');
                x->eventInvites[i] = stoi(holder);
            }
        }
    }
    
    file.close();
    
    return x;
}

//View matches
void Freshman::viewMatches(){
    ifstream file("freshmen.csv");  //load for reading
    string holder;                  //holds data from file

    
    //find out total number of lines(students) and make an array of that size
    int size = 0;
    while(getline(file,holder)){
        ++size;
    }
    size -= 3;
    float differenceFactors[2][size];         //one row holds regn no's and second holds difference factor
    
    //set get pointer again to start of file
    file.clear();
    file.seekg(0,ios::beg);
    
    string rNo = to_string(registrationNo);
    int i = 0;                              //counter
    float difference = 0;
    
    if(file.is_open()){
        getline(file,holder);       //first line has been read, now we can start reading from second line
        getline(file,holder,',');
        while(!file.eof()){
            if(holder != rNo){
                differenceFactors[0][i] = (float)stoi(holder);          //store reg #'s in first row of 2d array
                for(int j = 0; j < 3; j++){
                    getline(file,holder,',');       //move 3 columns forward
                }
                
                for(int k = 0; k < 6; k++){
                    getline(file,holder,',');
                    difference += abs(interestKeys[k] - stoi(holder));  //sum all the differences of corresponding interestKeys of the two freshman (the calling and the one whose reg # was just stored above
                }
                
                differenceFactors[1][i] = 100 - ((difference/48)*100);      //this gives match %age. store this in 2nd row of 2d array next to corresponding reg#
                
            }else{
                getline(file, holder);                  //get to next line
                getline(file,holder,',');               //get next reg no
                continue;
            }
            getline(file, holder);                  //get to next line
            getline(file,holder,',');               //get next reg no
            i++;
            difference = 0;                         //reset value for next iteration
        }
    }
    
    file.close();
    
    //sort the 2d array in decreasing order of match %ages
    float swap0;
    float swap1;
    for (int c = 0 ; c < ( size - 1 ); c++){
        for (int d = 0 ; d < size - c - 1; d++){
            if (differenceFactors[1][d] < differenceFactors[1][d+1]){
                //swap regn no's
                swap0       = differenceFactors[0][d];
                differenceFactors[0][d]   = differenceFactors[0][d+1];
                differenceFactors[0][d+1] = swap0;
                
                //swap corresponding factors
                swap1       = differenceFactors[1][d];
                differenceFactors[1][d]   = differenceFactors[1][d+1];
                differenceFactors[1][d+1] = swap1;
            }
        }
    }
    
    //give registration numbers of first 3 people freshman is compatible with
    cout << "Your interests match the most with: " <<endl;
    for(int i = 0; i < 3; i++){
        cout << "Regn #: " << (long)differenceFactors[0][i] << "  Compatibility %age:" << differenceFactors[1][i] << "%" <<endl;
    }
}

//Send meetup invite
void Freshman::sendMeetupInvite(){
    string regn;
    cout << "Enter registration number of freshman you would like to send an invite to: " <<endl;
    cin >> regn;
    
    fstream file("freshmen.csv", ios::in|ios::out);  //load for reading and writing (Regn# of inviter)
    string holder;                  //holds data from file
    
    if(file.is_open()){
        getline(file,holder);       //reach end of first line
        getline(file,holder,',');   //grab the regn# in second line
        while(holder != regn){          //loop will stop at the line which holds data of passed regn #
            getline(file,holder);       //reach end of current line
            getline(file,holder,',');   //grab the regn# in next line
        }
        
        for(int i = 0; i < 10; i++){    //reach the column which holds meetup invites
            getline(file,holder,',');
        }

        const char* caller = (to_string(registrationNo)).c_str();
        file.seekg(-9,ios::cur);   //move p pointer 9 characters back, to overwrite meetup inviter regn#
        for(int i = 0; i < 8; i++){ //overwrite regn#1 to inviters regn#
            file.put(caller[i]);
        }
        file.seekg(1,ios::cur);    //to skip the comma

        for(int i = 0; i < 2; i++){         //shift other two regn#'s forward
            string move = holder;
            getline(file,holder,',');
            file.seekg(-9,ios::cur);   //move p pointer 9 characters back, to overwrite meetup inviter regn#
            const char* compare = move.c_str();
            for(int i = 0; i < 8; i++){ //overwrite regn#1 to inviters regn#
                file.put(compare[i]);
            }
            file.seekg(1,ios::cur);    //to skip the comma

        }
        cout << "Invite has been sent" << endl;
    }
    
    file.close();
}

void Freshman::viewMeetupInvites(){
    ifstream file("freshmen.csv");
    string holder;
    
    const char* regn = to_string(registrationNo).c_str();
    
    if(file.is_open()){
        while(holder != regn){
            getline(file,holder);
            getline(file,holder,',');
        }
    }
    
    for(int i = 0; i < 10; i++){        //reach first invite regn#
        getline(file,holder,',');
    }
    
    cout << "You have been invited by: " <<endl;
    for(int i = 0; i < 3; i++){
        if(holder == "00000000"){
            if(i == 0){
                cout << "Nobody as of yet" <<endl;
            }
            else{
                break;
            }
        }
        else{
            cout << holder <<endl;
        }
        getline(file,holder,',');
    }
    
}

void Freshman::viewEventInvites(){
    ifstream file("freshmen.csv");
    string holder;
    
    const char* regn = to_string(registrationNo).c_str();
    
    if(file.is_open()){
        while(holder != regn){          //reach the callers' data row in the file
            getline(file,holder);
            getline(file,holder,',');
        }
    }
    
    for(int i = 0; i < 13; i++){        //reach first invite regn#
        getline(file,holder,',');
    }
    
    cout << "You have been invited to event no: " <<endl;
    for(int i = 0; i < 3; i++){
        if(holder == "000"){
            if(i == 0){
                cout << "Nobody as of yet" <<endl;
            }
            else{
                break;
            }
        }
        else{
            cout << holder <<endl;
        }
        getline(file,holder,',');
    }
    
}


void Freshman::inviteToEvent(int Ek){
    
}
