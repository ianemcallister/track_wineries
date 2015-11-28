//
//  list.h
//  project1
//
//  Created by Ian McAllister on 6/28/15.
//  Copyright (c) 2015 com.IMEnt. All rights reserved.
//

#ifndef __project1__list__
#define __project1__list__

#include "winery.h"
#include <stdio.h>
#include <fstream>
#include <iostream>

const int MAX_COL_WIDTH = 101;


struct node
{
    winery item;
    node * nextByName;
    node * nextByRating;
};

class list
{
public:
    //constructors
    list();
    list(char fileName []);
    //destructors
    ~list();
    //accessors
    void displayByName() const;
    void displayByRating() const;
    void retrieve(const char key [], winery& aWinery) const;
    void writeOut(char fileName []);
    //mutators
    void insert(const winery& aWinery);
    void remove(const char key[]);
    
    //additional functions
    bool isLessThan(char string1[], char string2[]);
    
private:
    node * headByName;
    node * headByRating;
};


#endif /* defined(__project1__list__) */
