//
//  Event.hpp
//  Orientation Assistant
//
//  Created by Talha Javed on 5/21/16.
//  Copyright © 2016 Talha Javed. All rights reserved.
//

#ifndef Event_hpp
#define Event_hpp

#include <iostream>
#include "Person.hpp"
using namespace std;

class Event{
private:
    int eventKey;
    string name;
    int type;                   //one of the 6 interests in interestsList
    string date;                //date on which event will take place
    string time;                //time at which event will take place
    string venue;               //school at which event will take place
    int creator;             //Registration no of person who sets up the event
public:
    //constructor
    Event();
    
    //Get Event key
    int getEventKey(){
        return eventKey;
    }
    
    //Register an Event
    void setEvent(Person* maker);
    
    //View Event Info
    void showEvent();
    
    //Store Event to file
    void storeEvent();
    
    //Load Event info from event key
    void loadEvent(string Ek);
    
    friend class Sophomore;
    friend class Faculty;
};

#endif /* Event_hpp */
