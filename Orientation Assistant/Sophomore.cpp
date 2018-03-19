//
//  Sophomore.cpp
//  Orientation Assistant
//
//  Created by Talha Javed on 5/20/16.
//  Copyright © 2016 Talha Javed. All rights reserved.
//

#include "Sophomore.hpp"
#include <fstream>

//constructor
Sophomore::Sophomore(){
    
}

//Get Name
string Sophomore::getName(){
    return firstName + " " + lastName;
}

//Get Registration Number
int Sophomore::getRegNo(){
    return registrationNo;
}

//Register a new Sophomore
void Sophomore::Register(){
    cout << "Enter your first name: " << endl;
    cin >> firstName;
    cout << "Enter your last name: " << endl;
    cin >> lastName;
    cout << "Enter your school. (Abbreviation in CAPS; eg, SCME)" <<endl;
    cin >> school;
    
    /*At the end of data file, there is a new registration number stored for the next student to be registered. Here we are extracting that number and assigning to the student*/
    
    //open file that contains sophomore data
    ifstream file("sophomores.csv");
    
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
    }
    
    //store this new profile to csv file
    storeProfile();
    cout << "Your registration is " << registrationNo << " <-- Write this down for future login." << endl;
}

//Log a Registered Member in
void Sophomore::login(){
    string regNo;
    cout << "Enter your registration number: " <<endl;
    cin >> regNo;
    
    int flag = 0;
    string temp;
    ifstream file("sophomores.csv");
    
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
            cout << "No Sophomore registered under entered number" << endl;
        }
        else{
            registrationNo = stoi(regNo);
            getline(file,firstName,',');
            getline(file,lastName,',');
            getline(file,school,',');
            
        }
    }
    
    file.close();
}

void Sophomore::showProfile(){
    cout << "-------------------" <<endl;
    cout << "Registration #: " << registrationNo << endl << "Name: " << firstName << " " << lastName  << endl << "School: " << school << endl;
    cout << "-------------------" <<endl;
}

//store Sophomore data to file
void Sophomore::storeProfile(){
    ofstream file("sophomores.csv", ios::app);
    
    //store all new data
    file << "," <<  firstName << "," << lastName << "," << school;
    
    //move to next line and set the next registration number
    file << "," << "\n" << registrationNo + 1;
}

//Get sopho by Inputting their Regn#
Sophomore* Sophomore::getProfileByRgn(string Regn){
    Sophomore* s = new Sophomore;
    
    int flag = 0;
    string temp;
    ifstream file("sophomores.csv");
    
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
            cout << "No Sophomore registered under entered number" << endl;
        }
        else{
            s->registrationNo = stoi(Regn);
            getline(file,s->firstName,',');
            getline(file,s->lastName,',');
            getline(file,s->school,',');
            
        }
    }
    
    file.close();
    
    return s;
}

//invite all freshmen to an event who might be interested by looking at event type
void Sophomore::inviteToEvent(int Ek){
    Event* e1 = new Event;
    e1->loadEvent(to_string(Ek));
    
    fstream file("freshmen.csv",ios::in|ios::out);
    string holder;
    getline(file,holder);       //traverse through first line
    
    const char* ek = to_string(Ek).c_str();
    
    if(file.is_open()){
        while(file.good()){
            for(int i = 0;i < 4+e1->type; i++){  //reach column which tells current freshman's level of interest in event type
                getline(file,holder,',');
            }
            if(stoi(holder) >= 5){               //if the freshman is fairly interested in the type of event, invite them, else continue
                for(int i = 0; i < 10-e1->type; i++){
                    getline(file,holder,',');
                }
                
                file.seekg(-4,ios::cur);
                for(int i = 0; i < 3; i++){
                    file.put(ek[i]);
                }
                file.seekg(1,ios::cur);    //to skip the comma

                for(int i = 0; i < 2; i++){
                    string move = holder;
                    getline(file,holder,',');
                    file.seekg(-4,ios::cur);   //move p pointer 4 to next event key
                    const char* compare = move.c_str();
                    for(int i = 0; i < 3; i++){ //move ek's one place forward
                        file.put(compare[i]);
                    }
                    file.seekg(1,ios::cur);    //to skip the comma

                }
                
            }else{
                getline(file,holder);
                getline(file,holder,',');
                
                if(!getline(file,holder)){              //break loop if end is reached
                    break;
                }
                continue;
            }
            getline(file,holder);
            getline(file,holder,',');
            
            if(!getline(file,holder)){              //break loop if end is reached
                break;
            }
        }
        cout << "Invitations have been sent. " <<endl;
    }
    
    file.close();
    
    delete e1;
}

