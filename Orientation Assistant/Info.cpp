//
//  Info.cpp
//  Orientation Assistant
//
//  Created by Talha Javed on 5/22/16.
//  Copyright © 2016 Talha Javed. All rights reserved.
//

#include "Info.hpp"
using namespace std;

Info::Info()
{
    
    //char to poiter is storing the values in a form of a string
    //values of char to pointer is stored in the pointer to array data member
    
    char *f1 = "There's a cafe near CIPS too!!!!"; FunFacts[0] = f1;
    char *f2 = "SEECS and NBS schools recieves special attention."; FunFacts[1] = f2;
    char *f3 = "Most of the time you'll think that the NUST's shuttle service is only for girls."; FunFacts[2] = f3;
    char *f4 = "NUST has the best sunset view in Islamabad."; FunFacts[3] = f4;
    char *f5 = "During course enrollment hours, you'll question the credibility of the letter T in NUST"; FunFacts[4] = f5;
    char *f6 = "NUST gives the most number of unplanned holidays"; FunFacts[5] = f6;
    
    
    
    //Cafes
    char *C1 = "Concordia 1"; Cafes[0] = C1;
    char *C2 = "Concordia 2"; Cafes[1] = C2;
    char *C3 = "Concordia 3"; Cafes[2] = C3;
    char *SmE = "SMME Cafe"; Cafes[3] = SmE;
    
    //Schools
    
    char *S1 = "School of Electrical Engineering and Computer Science"; Schools[0] = S1;
    char *S2 = "Nust Institute of Civil Engineering"; Schools[1] = S2;
    char *S3 = "Atta-Ur-Rehman School of Applied Biosciences"; Schools[2] = S3;
    char *S4 = "Nust Buisness School"; Schools[3] = S4;
    char *S5 = "School of Chemical and Enviormental Engineering"; Schools[4] = S5;
    char *S6 = "School of Social Sciences and Humanities"; Schools[5] = S6;
    char *S7 = "School of Art, Design and Architecture"; Schools[6] = S7;
    char *S8 = "School of Mechenical and Manufacturing Engineering"; Schools[7] = S8;
    char *S9 = "School of Natural Sciences"; Schools[8] = S9;
    char *S10 = "NUST Institute of Peace and Conflict Studies"; Schools[9] = S10;
    
    //Hostels
    char *H1 = "Rumi Hostel"; Hostels[0] = H1;
    char *H2 = "Ghazali Hostel"; Hostels[1] = H2;
    char *H3 = "Razi Hostel"; Hostels[2] = H3;
    char *H4 = "Attar Hostel"; Hostels[3] = H4;
    char *H5 = "Fatima Hostel"; Hostels[4] = H5;
    char *H6 = "Zainab Hostel"; Hostels[5] = H6;
    char *H7 = "Ayesha Hostel"; Hostels[6] = H7;
    char *H8 = "Iqra Appartments"; Hostels[7] = H8;
    
    //Gates
    char *G1 = "Gate 1"; Gates[0] = G1;
    char *G2 = "Gate 2"; Gates[1] = G2;
    char *G3 = "Gate 3"; Gates[2] = G3;
    
    //Grounds
    char *g1 = "HBL Ground"; Grounds[0] = g1;
    char *g2 = "NBS Ground"; Grounds[1] = g2;
    
    //NUST Lake
    NUSTLake = "NUST Lake";
}

void Info::printFacts()
{
    srand(time(NULL));
    
    int i = rand() % 6;
    cout << FunFacts[i] << endl;
    
}

int Info::locationHandler()
{
    string place;
    cout << "Where are you right now?" << endl;
    cin >> place;
    
    if (place == "ASAB" || place == "SEECS" || place == "NICE" || place == "Concordia 2" || place == "Rumi Hostels" || place == "Ghazali Hostel" || place == "Attar Hostel"||place == "Razi Hostel" || place == "Gate 1" || place == "Gate 3"  )
    {
        return 1;
    }
    
    else if (place == "NBS" || place == "S3H" ||place == "SADA" || place == "IESE" || place == "SCEE" || place == "Iqra Appartments"|| place == "Ayesha Hostel"||place == "Zainab Hostel" || place == "Fatima Hostel" ||place == "Concordia 1" || place == "Gate 10" )
    {
        return 2;
    }
    
    else if (place == "SMME" || place == "SNS")
    {
        return 3;
    }
    
    else if (place == "CIPS" || place == "NIPCONS")
    {
        return 4;
    }
    
    else
    {
        return 0;
    }
}

void Info::tellLocation()
{
    int answer = locationHandler();
    if (answer == 1)
    {
        cout << "Locations near you are:" << endl;
        cout << "\t" << Cafes[0] << endl;
        for (int a = 0; a < 3; a++)
        {
            cout << "\t" << Schools[a] << endl;
        }
        for (int a = 0; a < 4; a++)
        {
            cout << "\t" << Hostels[a]<<endl;
        }
        
        cout <<"\t"<< NUSTLake << endl;
    }
    
    if (answer == 2)
    {
        cout << "Locations near you are:" << endl;
        cout << "\t" << Cafes[1] << endl;
        for (int a = 3; a < 7; a++)
        {
            cout << "\t" << Schools[a]<<endl;
        }
        
        for (int a = 4; a < 8; a++)
        {
            cout << "\t" << Hostels[a]<<endl;
        }
    }
    
    if (answer == 3)
    {
        cout << "Locations near you are:" << endl;
        cout << "\t" << "SMME and SNS's cafe" << endl;
        for (int a = 8; a < 10; a++)
        {
            cout << "\t" << Schools[a]<<endl;
        }
    }
    
    if (answer == 4)
    {
        cout << "Locations near you are:" << endl;
        cout << "\t" << "NUST HQ Building" << endl;
        cout << "\t" << Schools[3] << "\t" << Schools[4] << "\t" << Schools[10] << endl;
        cout << "\t" << Cafes[2]<<endl;
    }
    
}