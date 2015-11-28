//
//  winery.cpp
//  project1
//
//  Created by Ian McAllister on 6/28/15.
//  Copyright (c) 2015 com.IMEnt. All rights reserved.
//

#include "winery.h"
#include <iomanip>
#include <string.h> //TAKE THIS OUT LATER!!!!!!!!!!!
#include <fstream> //TAKE THIS OUT LATER!!!!!!!!!!!

//constructors
winery::winery() :name(NULL), location(NULL), year(DEFAULT_YEAR), acres(0), rating(0.0)
{
}

winery::winery(const char * name, const char * location) :name(NULL), location(NULL), year(DEFAULT_YEAR), acres(0), rating(0.0)
{
    setName(name);
    setLocation(location);
}

winery::winery(const winery& aWinery) :name(NULL), location(NULL), year(DEFAULT_YEAR), acres(0), rating(0.0)
{
    setName(aWinery.name);
    setLocation(aWinery.location);
    setYear(aWinery.year);
    setAcres(aWinery.acres);
    setRating(aWinery.rating);
}

//destructors
winery::~winery()
{
    if(name) {
        delete [] name;
        name = NULL;
    }
    if(location) {
        delete [] location;
        location = NULL;
    }
    
}

//accessors
void winery::getName(char * name) const
{
    strcpy(name, this -> name);
}

void winery::getLocation(char * location) const
{
    strcpy(location, this -> location);
}

int winery::getYear()
{
    return year;
}

int winery::getAcres()
{
    return acres;
}

float winery::getRating()
{
    return rating;
}

//mutators
void winery::setName(const char * name)
{
    //release the existing memory if there is any
    if(this -> name)
        delete [] this -> name;
    
    //set new name
    this -> name = new char[strlen(name)+1];
    strcpy(this -> name, name);
}

void winery::setLocation(const char * location)
{
    //release the existing memory if there is any
    if(this -> location)
        delete [] this -> location;
    
    //set new location
    this -> location = new char[strlen(location)+1];
    strcpy(this -> location, location);
}

void winery::setYear(const int year)
{
    this -> year = year;
}

void winery::setAcres(const int acres)
{
    this -> acres = acres;
}

void winery::setRating(const float rating)
{
    this -> rating = rating;
}

//operator overloading
bool operator< (const winery& d1, const winery& d2)
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

bool operator== (const winery& d1, const winery& d2)
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

bool operator!= (const winery& d1, const winery& d2)
{
    char name1[100];
    char name2[100];
    
    d1.getName(name1);
    d2.getName(name2);
    
    if(strcmp(name1, name2) != 0)
        return true;
    else
        return false;
}

const winery& winery::operator=(const winery& aWinery)
{
    //if it is a self copy don't do anything
    if(this == &aWinery)
        return *this;
    //make current object *this a copy of the passed in winery
    else
    {
        setName(aWinery.name);
        setLocation(aWinery.location);
        setYear(aWinery.year);
        setAcres(aWinery.acres);
        setRating(aWinery.rating);
        return *this;
    }
}

ostream& operator<< (ostream& out, const winery& aWinery)
{
    out << aWinery.name << ";" << aWinery.location << ";" << aWinery.year << ";" << aWinery.acres;
    out << ";" << aWinery.rating << endl;
    return out;
}