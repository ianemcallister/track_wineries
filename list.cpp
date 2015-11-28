//
//  list.cpp
//  project1
//
//  Created by Ian McAllister on 6/28/15.
//  Copyright (c) 2015 com.IMEnt. All rights reserved.
//

#include "list.h"

using namespace std;

//constructors
list::list() :headByName(NULL), headByRating(NULL)
{
}

list::list(char fileName []) :headByName(NULL), headByRating(NULL)
{
    //declare and initialize local variables
    ifstream inFile;
    winery aWinery;
    char tempName[MAX_COL_WIDTH] = { '\0' };
    char tempLocation[MAX_COL_WIDTH] = { '\0' };
    int tempYear = 0;
    int tempAcres = 0;
    float tempRating = 0.0;
    
    //open file
    inFile.open(fileName);
    if(!inFile)
    {
        inFile.clear();
        cout << endl << "Failed to open " << fileName << " for input!" << endl << endl;
        exit(1);
    }
    
    //load file data into member variables, name first
    inFile.get(tempName, MAX_COL_WIDTH, ';');
    
    //loop through file until all data is read
    while (!inFile.eof())
    {
        //clear buffer
        inFile.ignore(10, ';');
        //then location
        inFile.get(tempLocation, MAX_COL_WIDTH, ';');
        //clear buffer
        inFile.ignore(10, ';');
        //then year
        inFile>>tempYear;
        //clear buffer
        inFile.ignore(10, ';');
        //then acres
        inFile>>tempAcres;
        //clear buffer
        inFile.ignore(10, ';');
        //then rating
        inFile>>tempRating;
        //clear buffer
        inFile.ignore(10, '\n');
        
        //load all temp values in to place holder object
        aWinery.setName(tempName);
        aWinery.setLocation(tempLocation);
        aWinery.setYear(tempYear);
        aWinery.setAcres(tempAcres);
        aWinery.setRating(tempRating);
        
        //add task to list
        insert(aWinery);
        
        //start next record
        inFile.get(tempName, MAX_COL_WIDTH, ';');
    } //out of loop
    
    //close the resource file
    inFile.close();

    
}

//destructors
list::~list()
{
    node *curr = headByName;
    
    if (headByName)
    {
        while (curr)
        {
            curr = curr->nextByName;
            delete headByName;
            headByName = curr;
        }
        
    }
    
}

//accessors
void list::displayByName() const
{
    //declare and initialize local variables
    node *curr = headByName;
    char name[100] = {'\0'};
    int counter = 1;
    
    //set up formating
    cout << left;
    
    //if atleast one record exists print through them
    if(headByName)
    {
        
        for(; curr; curr=curr->nextByName)
        {
            
            //get the current name
            curr->item.getName(name);
            
            //count the wineries being displayed
            cout << counter << ". ";
            
            //print current winery name
            cout << name << endl;
            
            //incriment counter
            counter++;
        } // out of for loop
        
    }
    
    else
    
    {
        
        cout << "No Wineries Found";
    
    }
    
    cout << endl;
}

void list::displayByRating() const
{
    //declare and initialize local variables
    node *curr = headByRating;
    char name[101] = {'\0'};
    float rating = 0.0;
    int counter = 1;
    
    //set up formating
    cout << left << setprecision(2) << fixed;
    
    //if atleast one record exists print through them
    if(headByRating)
    {
        
        for(; curr; curr=curr->nextByRating)
        {
            
            //get the current name & rating
            curr->item.getName(name);
            rating = curr->item.getRating();
            
            //count the wineries being displayed
            cout << counter << ". ";
            
            //print current winery name
            cout << setw(30) << name << "(" << rating << ")" << endl;
            
            //incriment counter
            counter++;
        } // out of for loop
        
    }
    
    else
        
    {
        
        cout << "No Wineries Found";
        
    }
    
    cout << endl;
}

void list::retrieve(const char key [], winery& aWinery) const
{
    //declare and initialize local variables
    node *curr;
    winery tempWinery;
    //add name to temp variable
    tempWinery.setName(key);
    
    //if at least one winery name exists
    if(headByName)
    {
        //incriment through each node, looking for a matching winery name
        for(curr = headByName; curr; curr = curr->nextByName)
        {
            //check for a match
            if(curr->item == tempWinery)
            {
                //if a match is found, deep copy the information from the model to aWinery for pass back
                aWinery = curr->item;

            }
            
        }
        
    }
    
}

void list::writeOut(char fileName [])
{
    //declare and initialize local variables.
    node * curr;
    ofstream outData;
    
    //open resource file
    outData.open(fileName);
    
    //notify user if error opening file
    if (!outData)
    {
        cout << "cannot open file";
        exit(0);
    }
    
    //iterate through each node, printing out to the file
    for (curr = headByName; curr; curr = curr->nextByName)
        outData << curr->item;
    
    //close the resource file
    outData.close();
}

//mutators
void list::insert(const winery& aWinery)
{
    //declare and initialize local variables
    float tempRating1 = 0.0;
    float tempRating2 = 0.0;
    int tempAcres1 = 0;
    int tempAcres2 = 0;
    node *newNode, *curr, *prev;
    newNode = new node;
    curr = NULL;
    prev = NULL;
    
    //populate new node
    newNode->item = aWinery;
    newNode->nextByName = NULL;
    newNode->nextByRating = NULL;
    
    //update the Name ordered List
    if(!headByName)
    {
        //if this is the first node just direct the pointers
        headByName = newNode;
    }
    else
    {
        //if this is not the first node start at the beginning and run through the list
        curr = headByName;
        prev = NULL;
        
        //find the appropriate node
        while(curr && (curr->item < newNode->item))
        {
            prev = curr;
            curr = curr->nextByName;
            
        }
        
        //once the approprite node has been found update the pointers
        if(prev)
        {
            prev->nextByName = newNode;
            newNode->nextByName = curr;
        }
        else
        {
            headByName = newNode;
            newNode->nextByName = curr;
        }
        
    }

    //update the rating ordered List
    if(!headByRating)
    {
        //if this is the first node just direct the pointers
        headByRating = newNode;
    }
    
    else
    {
        //if this is not the first node start at the beginning and run through the list
        curr = headByRating;
        prev = NULL;
        
        //extract rating values
        tempRating1 = curr->item.getRating();
        tempRating2 = newNode->item.getRating();
        
        //find the appropriate node
        while(curr && (tempRating1 > tempRating2))
        {
            prev = curr;
            curr = curr->nextByRating;
            if(curr)
                tempRating1 = curr->item.getRating();
            
            //if the ratings are the same compare acres
            if(tempRating1 == tempRating2)
            {
                tempAcres1 = curr->item.getAcres();
                tempAcres2 = newNode->item.getAcres();
                
                while((tempAcres1 < tempAcres2) && (tempRating1 == tempRating2))
                {
                    prev = curr;
                    curr = curr->nextByRating;
                    if(curr)
                    {
                        tempAcres1 = curr->item.getRating();
                        tempRating1 = curr->item.getRating();
                    }
                    
                }
                
            }
            
        }
        
        //once the approprite node has been found update the pointers
        if(prev)
        {
            prev->nextByRating = newNode;
            newNode->nextByRating = curr;
        }
        else
        {
            headByRating = newNode;
            newNode->nextByRating = curr;
        }
        
    }

}

void list::remove(const char key[])
{
    //declare and initialize local variables
    node *currByName = NULL;
    node *prevByName = NULL;
    node *currByRating = NULL;
    node *prevByRating = NULL;
    bool found = false;
    winery tempWinery;
    //add name to temp variable
    tempWinery.setName(key);
    
    //if at least one winery name exists
    if(headByName)
    {
        //assign the currByName start
        currByName = headByName;
        
        //incriment through each node by name, looking for a matching winery name
        while(currByName && (currByName->item != tempWinery) && currByName->nextByName)
        {
            prevByName = currByName;
            currByName = currByName->nextByName;
        }
        
        //assign the currByRating start
        currByRating = headByRating;
        
        //incriment through each node by rating, looking for a matching winery name
        while(currByRating && (currByRating->item != tempWinery) && currByRating->nextByRating)
        {
            prevByRating = currByRating;
            currByRating = currByRating->nextByRating;

        }
        
        //if matches were found update the database
        if(currByName->item == tempWinery && currByRating->item == tempWinery)
        {
            found = true;
            
            //update the pointers to skip over the record to delete
            if(currByName != headByName)
                prevByName->nextByName = currByName->nextByName;
            else
                headByName = currByName->nextByName;
            
            if(currByRating != headByRating)
                prevByRating->nextByRating = currByRating->nextByRating;
            else
                headByRating = currByRating->nextByRating;
            
            //delete the desired node
            delete currByName;
            currByName = NULL;
            currByRating = NULL;
        }
        else
        {
            cout << "No record " << key << " found." << endl;
        }
        
        
    }
    else
    {
        //notify user of empty list
        cout << "There are no records to remove." << endl;
    }
    
}

bool list::isLessThan(char string1[], char string2[])
{
    if (strcmp(string1, string2) < 0)
        return true;
    else
        return false;
}