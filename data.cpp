//
//  data.cpp
//  project1
//
//  Created by Ian McAllister on 6/28/15.
//  Copyright (c) 2015 com.IMEnt. All rights reserved.
//

#include "data.h"
#include <iomanip>
#include <string.h> //TAKE THIS OUT LATER!!!!!!!!!!!
#include <fstream> //TAKE THIS OUT LATER!!!!!!!!!!!

//constructors
data::data() :name(NULL), location(NULL), yearProductionStarted(DEFAULT_YEAR), vineyardAcreage(0), successRating(0.0)
{
}

data::data(const char * name, const char * location) :name(NULL), location(NULL), yearProductionStarted(DEFAULT_YEAR), vineyardAcreage(0), successRating(0.0)
{
    setName(name);
    setLocation(location);
}

data::data(const data& winery) :name(NULL), location(NULL), yearProductionStarted(DEFAULT_YEAR), vineyardAcreage(0), successRating(0.0)
{
    setName(winery.name);
    setLocation(winery.location);
    setProductionStart(winery.yearProductionStarted);
    setAcreage(winery.vineyardAcreage);
    setSuccessRate(winery.successRating);
}

//destructors
data::~data()
{
    if(name)
        delete [] name;
    if(location)
        delete [] location;
}

//accessors
void data::getName(char * name) const
{
    strcpy(name, this -> name);
}

void data::getLocation(char * location) const
{
    strcpy(location, this -> location);
}

int data::getProductionStart()
{
    return yearProductionStarted;
}

int data::getAcreage()
{
    return vineyardAcreage;
}

float data::getSuccessRate()
{
    return successRating;
}

//mutators
void data::setName(const char * name)
{
    //release the existing memory if there is any
    if(this -> name)
        delete [] this -> name;
    
    //set new name
    this -> name = new char[strlen(name)+1];
    strcpy(this -> name, name);
}

void data::setLocation(const char * location)
{
    //release the existing memory if there is any
    if(this -> location)
        delete [] this -> location;
    
    //set new location
    this -> location = new char[strlen(location)+1];
    strcpy(this -> location, location);
}

void data::setProductionStart(const int yearProductionStarted)
{
    this -> yearProductionStarted = yearProductionStarted;
}

void data::setAcreage(const int vineyardAcreage)
{
    this -> vineyardAcreage = vineyardAcreage;
}

void data::setSuccessRate(const float successRating)
{
    this -> successRating = successRating;
}

//operator overloading
bool operator< (const data& d1, const data& d2)
{
    char name1[100];
    char name2[100];
    
    d1.getName(name1);
    d2.getName(name2);
    
    if(strcmp(name1, name2) < 0)
        return true;
    else
        return false;
}

bool operator== (const data& d1, const data& d2)
{
    char name1[100];
    char name2[100];
    
    d1.getName(name1);
    d2.getName(name2);
    
    if(strcmp(name1, name2) == 0)
        return true;
    else
        return false;
}

const data& data::operator=(const data& winery)
{
    //if it is a self copy don't do anything
    if(this == &winery)
        return *this;
    //make current object *this a copy of the passed in winery
    else
    {
        setName(winery.name);
        setLocation(winery.location);
        setProductionStart(winery.yearProductionStarted);
        setAcreage(winery.vineyardAcreage);
        setSuccessRate(winery.successRating);
        return *this;
    }
}

ostream& operator<< (ostream& out, const data& winery)
{
    out << setw(20) << winery.name << setw(20) << winery.location << setw(5) << winery.successRating;
    return out;
}