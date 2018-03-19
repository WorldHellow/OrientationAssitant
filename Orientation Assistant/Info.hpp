//
//  Info.hpp
//  Orientation Assistant
//
//  Created by Talha Javed on 5/22/16.
//  Copyright © 2016 Talha Javed. All rights reserved.
//

#ifndef Info_hpp
#define Info_hpp

#include <iostream>
#include<string>
#include<stdlib.h>
#include<time.h>

class Info
{
private:
    char *FunFacts[6];
    char *Cafes[4];
    char *Schools[10];
    char *Hostels[8];
    char *Gates[3];
    std::string NUSTLake;
    char *Grounds[2];
    
public:
    //constructor
    Info();
    
    //print random fact function
    void printFacts();
    
    //Tells user which buildings are near his location
    void tellLocation();
    
    //returns an integer value if the user enters a name of place
    int locationHandler();
};

#endif /* Info_hpp */
