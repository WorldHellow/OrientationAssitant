//
//  Faculty.hpp
//  Orientation Assistant
//
//  Created by Talha Javed on 5/21/16.
//  Copyright © 2016 Talha Javed. All rights reserved.
//

#ifndef Faculty_hpp
#define Faculty_hpp

#include "Person.hpp"
#include "Event.hpp"

class Faculty:public Person{
private:
    string roomNumber;                  //data member for room numbers
    string courses[4];                 //Slot for courses they teach
public:
    //constructor
    Faculty();
    
    //get Name;
    virtual string getName();

    //Get Registration Number
    virtual int getRegNo();
    
    //Enter Course instructor's profile
    virtual void Register();
    
    //Log a registered faculty member in
    virtual void login();
    
    //Show their profile
    virtual void showProfile();
    
    //Store their profile in a .csv file
    virtual void storeProfile();
    
    //Get faculty member by Inputting their Regn#
    Faculty* getProfileByRgn(string Regn);
    
    //invite to an event
    virtual void inviteToEvent(int Ek);
};

#endif /* Faculty_hpp */
