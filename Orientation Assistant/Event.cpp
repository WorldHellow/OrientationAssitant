//
//  Event.cpp
//  Orientation Assistant
//
//  Created by Talha Javed on 5/21/16.
//  Copyright © 2016 Talha Javed. All rights reserved.
//

#include "Event.hpp"
#include "Person.hpp"
#include <fstream>

//constructor
Event::Event(){
    
}

void Event::setEvent(Person* maker){
    cout << "Enter the name for your event: " <<endl;
    cin >> name;
    cout << "What kind of an event is this? Enter appropriate number. 1)Sports 2)Books 3)Visual Art 4)Music 5)Food 6)Science" <<endl;
    cin >> type;
    cout << "What date will the event take place? format: dd-mm-yyyy" <<endl;
    cin >> date;
    cout << "What time will the event take place? format: 24-hour xx:xx" <<endl;
    cin >> time;
    cout << "What school will the event take place in? (Abbreviation in CAPS; eg, SCME)" <<endl;
    cin >> venue;
    creator = maker->getRegNo();
    
    //open file that contains events data
    ifstream file("events.csv");
    
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
        getline(file,x);            //x stores the last line, which just holds a new event key
        eventKey = stoi(x);
        
        file.close();
        cout << "The event key for this event is: " << eventKey << " .Write this down for further access to this event" << endl;
    }
    
    storeEvent();
}

void Event::storeEvent(){
    ofstream file("events.csv", ios::app);
    
    //store all new data
    file << "," <<  name << "," << type << "," << date << "," << time << "," << venue << "," << creator;
    
    //move to next line and set the next event key
    file << "," << "\n" << eventKey + 1;
}

void Event::loadEvent(string Ek){
    ifstream file("events.csv");
    string holder;
    eventKey = stoi(Ek);
    
    if(file.is_open()){
        while(holder != Ek){                //loop until grabbed event key matches passed one
            getline(file,holder);           //grab next event key in file
            getline(file,holder,',');
        }
        
        //grab data
        getline(file, name, ',');
        getline(file, holder, ',');
        type = stoi(holder);
        getline(file, date, ',');
        getline(file, time, ',');
        getline(file, venue, ',');
        getline(file, holder, ',');
        creator = stoi(holder);
    }
}