//
//  Freshman.hpp
//  Orientation Assistant
//
//  Created by Talha Javed on 5/20/16.
//  Copyright © 2016 Talha Javed. All rights reserved.
//

#ifndef Freshman_hpp
#define Freshman_hpp

#include <iostream>
#include "Student.hpp"

class Freshman: public Student{
private:
    int interestKeys[6];
    int meetupInvites[3];                //holds registration numbers of inviters
    int eventInvites[3];                 //holds eventKeys of events you've been invited to
    
public:
    std::string interestsList[6] = { "Sports", "Books", "Visual Arts", "Music", "Science", "Food" };
    
    //constructor
    Freshman();
    
    //get Name;
    virtual string getName();
    
    //Get Registration Number
    virtual int getRegNo();
    
    //Register a new freshman
    virtual void Register();
    
    //Log a registered freshman in
    virtual void login();
    
    //Print Freshman Data
    virtual void showProfile();
    
    //Store Freshman Data to file
    virtual void storeProfile();
    
    //Get freshman by Inputting their Regn#
    Freshman* getProfileByRgn(string Regn);
    
    //View Matches
    void viewMatches();
    
    //Send a Meetup Invite
    void sendMeetupInvite();
    
    //View my Meetup Invites
    void viewMeetupInvites();
    
    //Find Events
    void findEvents();
    
    //View my Event Invites
    void viewEventInvites();
    
    virtual void inviteToEvent(int Ek);
};


#endif /* Freshman_hpp */
