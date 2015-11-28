//
//  data.h
//  project1
//
//  Created by Ian McAllister on 6/28/15.
//  Copyright (c) 2015 com.IMEnt. All rights reserved.
//

#ifndef __project1__data__
#define __project1__data__

#include <stdio.h>
#include <iomanip>

const int DEFAULT_YEAR = 1900;

using namespace std;

class data
{
public:
    //constructors
    data();
    data(const char * name, const char * location);
    data(const data& winery);    //copy consturctor, make current objet a copy of "venue"
    
    //destructors
    ~data();
    
    //accessors
    void getName(char * name) const;
    void getLocation(char * location) const;
    int getProductionStart();
    int getAcreage();
    float getSuccessRate();
    
    //mutators
    void setName(const char * name);
    void setLocation(const char * location);
    void setProductionStart(const int yearProductionStarted);
    void setAcreage(const int vineyardAcreage);
    void setSuccessRate(const float successRating);
    
    //operator overloading
    friend ostream& operator<< (ostream& out, const data& winery);
    const data& operator=(const data& winery); //overloard assignment opperator
    
private:
    char * name;
    char * location;
    int yearProductionStarted;
    int vineyardAcreage;
    float successRating;
};

bool operator< (const data& d1, const data& d2);    //overload < on data objects
bool operator== (const data& d1, const data& d2);   //overload == on data objects

#endif /* defined(__project1__data__) */