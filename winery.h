//
//  winery.h
//  project1
//
//  Created by Ian McAllister on 6/28/15.
//  Copyright (c) 2015 com.IMEnt. All rights reserved.
//

#ifndef __project1__winery__
#define __project1__winery__

#include <stdio.h>
#include <iomanip>

const int DEFAULT_YEAR = 1900;

using namespace std;

class winery
{
public:
    //constructors
    winery();
    winery(const char * name, const char * location);
    winery(const winery& aWinery);    //copy consturctor, make current objet a copy of "venue"
    
    //destructors
    ~winery();
    
    //accessors
    void getName(char * name) const;
    void getLocation(char * location) const;
    int getYear();
    int getAcres();
    float getRating();
    
    //mutators
    void setName(const char * name);
    void setLocation(const char * location);
    void setYear(const int year);
    void setAcres(const int acres);
    void setRating(const float rating);
    
    //operator overloading
    friend ostream& operator<< (ostream& out, const winery& aWinery);
    const winery& operator=(const winery& aWinery); //overloard assignment opperator
    
private:
    char * name;
    char * location;
    int year;
    int acres;
    float rating;
};

bool operator< (const winery& d1, const winery& d2);    //overload < on data objects
bool operator== (const winery& d1, const winery& d2);   //overload == on data objects
bool operator!= (const winery& d1, const winery& d2);   //overload == on data objects

#endif /* defined(__project1__winery__) */