//
//  Person.hpp
//  Orientation Assistant
//
//  Created by Talha Javed on 5/20/16.
//  Copyright © 2016 Talha Javed. All rights reserved.
//

#ifndef Person_hpp
#define Person_hpp

#include <iostream>
#include <string>
using namespace std;

class Person{
protected:
    string firstName;
    string lastName;
    string school;
    int registrationNo;
public:
    //constructor
    Person();
    
    //get Name;
    virtual string getName() = 0;
    
    //get registration number
    virtual int getRegNo() = 0;
    
    //register
    virtual void Register() = 0;
    
    //login
    virtual void login() = 0;
    
    //Show Profile
    virtual void showProfile() = 0;
    
    //Store Profile
    virtual void storeProfile() = 0;
    
    //Invite to Event
    virtual void inviteToEvent(int Ek) = 0;
};

#endif /* Person_hpp */
