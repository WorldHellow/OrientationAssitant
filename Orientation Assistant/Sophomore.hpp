//
//  Sophomore.hpp
//  Orientation Assistant
//
//  Created by Talha Javed on 5/20/16.
//  Copyright © 2016 Talha Javed. All rights reserved.
//

#ifndef Sophomore_hpp
#define Sophomore_hpp

#include <iostream>
#include "Event.hpp"
#include "Student.hpp"

class Sophomore: public Student{
private:
public:
    //constructor
    Sophomore();
    
    //get Name;
    virtual string getName();

    //Get Registration Number
    virtual int getRegNo();
    
    //register
    virtual void Register();
    
    //Log a registered sophomore in
    virtual void login();
    
    //show profile
    virtual void showProfile();
    
    //store profile
    virtual void storeProfile();
    
    //Get sopho by Inputting their Regn#
    Sophomore* getProfileByRgn(string Regn);
    
    //invite to an Event
    virtual void inviteToEvent(int Ek);
};

#endif /* Sophomore_hpp */
