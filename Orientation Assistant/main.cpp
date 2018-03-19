//
//  main.cpp
//  Orientation Assistant
//
//  Created by Talha Javed on 5/9/16.
//  Copyright © 2016 Talha Javed. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string.h>
#include "Freshman.hpp"
#include "Sophomore.hpp"
#include "Faculty.hpp"
#include "Event.hpp"
#include "Info.hpp"
using namespace std;

void start();
void mainMenu();
void fr(Person* a);
void so(Person* a);
void fa(Person* a);


int main(){
    Event e;
    Info i;
    Freshman* f;
    int ek;
    
    bool loop = true;
    
    int type;                   //type of person
    
    start();
    cin >> type;
    
    Person* p;
    
    while(loop){
        loop = false;
        switch(type){
            case 1:
                p = new Freshman;
                break;
            case 2:
                p = new Sophomore;
                break;
            case 3:
                p = new Faculty;
                break;
            case 4:
                return 0;
                break;
            default:
                cout << "Invalid Entry. Enter again: " << endl;
                cin >> type;
                loop = true;
        }
    }
    loop = true;            //reset boolean switch
    
    
    int mode;
    

    mainMenu();
    cin >> mode;
    
    while(loop){
        loop = false;
        switch(mode){
            case 1:
                p->login();
                break;
            case 2:
                p->Register();
                break;
            case 3:
                return 0;
                break;
            default:
                cout << "Invalid Entry. Enter again: " << endl;
                cin >> type;
                loop = true;
        }
    }
    loop = true;            //reset boolean switch
    
    if(type == 1){          //if user is a freshman, we need to create a freshman pointer to access functions exclusive to freshman class
        f = f->getProfileByRgn(to_string(p->getRegNo()));
    }

    
    switch(type){
        case 1:
            fr(p);
            cin >> mode;
            while(loop){
                loop = true;
                switch(mode){
                    case 1:
                        f->viewMatches();
                        fr(p);
                        break;
                    case 2:
                        f->sendMeetupInvite();
                        fr(p);
                        break;
                    case 3:
                        f->viewMeetupInvites();
                        fr(p);
                        break;
                    case 4:
                        f->viewEventInvites();
                        fr(p);
                        break;
                    case 5:
                        i.tellLocation();
                        fr(p);
                        break;
                    case 6:
                        i.printFacts();
                        fr(p);
                        break;
                    case 9:
                        p->showProfile();
                        fr(p);
                        break;
                    case 0:
                        return 0;
                        break;
                    default:
                        cout << "Invalid Entry. Enter again: " << endl;
                        cin >> type;
                        loop = true;
                }
                cin>>mode;
            }
            break;
            
        case 2:
            so(p);
            cin >> mode;
            while(loop){
                loop = true;
                switch(mode){
                    case 1:
                        e.setEvent(p);
                        so(p);
                        break;
                    case 2:
                        cout << "Enter event key for automated invite sending" <<endl;
                        cin >> ek;
                        p->inviteToEvent(ek);
                        so(p);
                        break;
                    case 9:
                        p->showProfile();
                        so(p);
                        break;
                    case 0:
                        return 0;
                        break;
                    default:
                        cout << "Invalid Entry. Enter again: " << endl;
                        cin >> type;
                        loop = true;
                }
                cin>>mode;
            }
            break;
            
        case 3:
            fa(p);
            cin>>mode;
            while(loop){
                loop = true;
                switch(mode){
                    case 1:
                        e.setEvent(p);
                        fa(p);
                        break;
                    case 2:
                        cout << "Enter event key for automated invite sending" <<endl;
                        cin >> ek;
                        p->inviteToEvent(ek);
                        fa(p);
                        break;
                    case 9:
                        p->showProfile();
                        fa(p);
                        break;
                    case 0:
                        return 0;
                        break;
                    default:
                        cout << "Invalid Entry. Enter again: " << endl;
                        cin >> type;
                        loop = true;
                }
                cin>>mode;
            }
            break;
            
    }
    
    
    return 0;
}

//start screen
void start(){
    cout << "=====================================================" << endl;
    cout << "||          WELCOME TO ORIENTATION ASSISTANT       ||" << endl;
    cout << "=====================================================" << endl;
    cout << "||         What would you like to enter as?        ||" << endl;
    cout << "||                                                 ||" << endl;
    cout << "||                (1) Freshman                     ||" << endl;
    cout << "||                (2) Sophomore                    ||" << endl;
    cout << "||                (3) Faculty                      ||" << endl;
    cout << "||                (4) Exit                         ||" << endl;
    cout << "||                                                 ||" << endl;
    cout << "=====================================================" << endl;
}

void mainMenu(){
    cout << "=====================================================" << endl;
    cout << "||               ORIENTATION ASSISTANT             ||" << endl;
    cout << "=====================================================" << endl;
    cout << "||                 Main Menu                       ||" << endl;
    cout << "||                                                 ||" << endl;
    cout << "||                (1) Login                        ||" << endl;
    cout << "||                (2) Register                     ||" << endl;
    cout << "||                (3) Exit                         ||" << endl;
    cout << "||                                                 ||" << endl;
    cout << "=====================================================" << endl;
}

void fr(Person* a){
    cout << "Logged in as:  " << a->getName() << endl;
    cout << "=====================================================" << endl;
    cout << "||               ORIENTATION ASSISTANT             ||" << endl;
    cout << "=====================================================" << endl;
    cout << "||                      Menu                       ||" << endl;
    cout << "||                                                 ||" << endl;
    cout << "||     (1) Find People with Matching Interests     ||" << endl;
    cout << "||      (2) Send a Meetup Invite to Someone        ||" << endl;
    cout << "||          (3) View my Meetup Invites             ||" << endl;
    cout << "||           (4) View my Event Invites             ||" << endl;
    cout << "||              (5) Places Near me                 ||" << endl;
    cout << "||         (6) Random fun fact about NUST          ||" << endl;
    cout << "||                                                 ||" << endl;
    cout << "||                                                 ||" << endl;
    cout << "||                (9) View Profile                 ||" << endl;
    cout << "||                   (0) Logout                    ||" << endl;
    cout << "||                                                 ||" << endl;
    cout << "=====================================================" << endl;
}

void so(Person* a){
    cout << "Logged in as:  " << a->getName() << endl;
    cout << "=====================================================" << endl;
    cout << "||               ORIENTATION ASSISTANT             ||" << endl;
    cout << "=====================================================" << endl;
    cout << "||                      Menu                       ||" << endl;
    cout << "||                                                 ||" << endl;
    cout << "||             (1) Set up an Event                 ||" << endl;
    cout << "||      (2) Invite Interested Freshmen to Event    ||" << endl;
    cout << "||                                                 ||" << endl;
    cout << "||               (9) View Profile                  ||" << endl;
    cout << "||                  (0) Logout                     ||" << endl;
    cout << "||                                                 ||" << endl;
    cout << "=====================================================" << endl;
}

void fa(Person* a){
    cout << "Logged in as:  " << a->getName() << endl;
    cout << "=====================================================" << endl;
    cout << "||               ORIENTATION ASSISTANT             ||" << endl;
    cout << "=====================================================" << endl;
    cout << "||                      Menu                       ||" << endl;
    cout << "||                                                 ||" << endl;
    cout << "||             (1) Set up an Event                 ||" << endl;
    cout << "||      (2) Invite Interested Freshmen to Event    ||" << endl;
    cout << "||                                                 ||" << endl;
    cout << "||                (9) View Profile                 ||" << endl;
    cout << "||                  (0) Logout                     ||" << endl;
    cout << "||                                                 ||" << endl;
    cout << "=====================================================" << endl;
}

