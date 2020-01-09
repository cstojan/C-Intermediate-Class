/*
    Programmer: Cory Stojan
    Class/Section: CSCI 241 Section 1
    Due Date: 26 April 2018
    Purpose: Contains the template code for a sorting algorithem
*/

// Headder Guard
#ifndef SORTS_H
#define SORTS_H

// Include strings
#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string.h>

// Using Statements
using std::cout; 
using std::endl;
using std::fixed; 
using std::left; 
using std::setw; 
using std::cerr;
using std::ostream; 
using std::ifstream;
using std::vector;
//****************************************************

/*
Function: buildList()
Arguments: A reference to a vectr of T data type called set
	   A pointer to a constant char called fileName
Purpose: Creates a vector with the passed file name (fileName)
Returns: Nothing
*/
template <class T>
void buildList(vector<T>& set, const char* fileName) 
{
	//variable to hold items from file
    T item;
	ifstream inFile;

	inFile.open(fileName);
	if(inFile.fail()) 
    {
        //print error if it cant open
		cerr << "ERROR: Could not open file!" << endl;
		exit(-1);
	}

    //if vector(set) isn't empty, clear it out. (error checks)
	if(!set.empty()) 
		set.clear();

    //reads the first item from the file and stores in in item
	inFile >> item; 
    
    //continue until end of file and store items in vector(set)
	while(!inFile.eof()) 
    { 
		set.push_back(item);
		inFile >> item;
	}
    
    //close file
    inFile.close();
}

/*
Function: printList()
Arguments: A integer called itemWidth to determine width a item should occupy
	   A integer called numPerLine to determine how many items will be printed per line
	   A reference to a constant vector of T data type called set
Purpose: Prints out the vector in a formatted way
Returns: Nothing
*/
template <class T>
void printList(const vector<T> & set, int itemWidth, int numPerLine) 
{
	for(unsigned i = 0; i < set.size(); i++) 
    {
        //if numPerLine is reached, a new line is started
		if( i % numPerLine == 0 && i != 0) 
			cout << endl;
            
        // display itemWidth
		cout << fixed << left << setw(itemWidth) << set.at(i) << " ";
	}
}

/*
Function: lessThan()
Arguments: A constant reference to a T data type called item1
	   A constant reference to a T data type called item2
Purpose: Checks if item1 is less than item2
Returns: True if item1 is less than item2 or false if it's not
*/
template <class T>
bool lessThan(const T& item1, const T& item2) 
{
    // check if item1 is less than item 2 if so return true else return false.
	if(item1 < item2)
		return true;
	else
		return false;
}

/*
Function: greaterThan()
Arguments: A constant reference to a T data type called item1
	   A constant reference to a T data type called item2
Purpose: Checks if item1 is greater than item2
Returns: True if item1 is greater than item2 or false if it's not
*/
template <class T>
bool greaterThan(const T& item1, const T& item2) 
{
    // check if item1 is greater than item 2 if so return true else return false.
	if (item1 > item2)
		return true;
	else
		return false;
}

#endif
