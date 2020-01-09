/*
    Programmer: Cory Stojan
    Class/Section: CSCI 241 Section 1
    Due Date: 26 April 2018
    Purpose: Contains the template code for the quicksort algorthem
*/

//Headder Guard
#ifndef QUICKSORT_H
#define QUICKSORT_H

//Include Statements
#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string.h>

// Using Statemnts
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
Function: swapElements() (avoids repeating code)
Arguments: A reference to a T data type called firtElement
           A reference to a T data type called secondElement
Use: Used to swap elements within the vector
Returns: Nothing
*/
template <class T>
void swapElements(T& firstElement, T& secondElement) 
{
	//Temp variable to hold firstElement
    T temp; 
	temp = firstElement;
	firstElement = secondElement;
	secondElement = temp;
}

/*
Function: partition()
Arguments: A reference to a vector(set) of T data type
           A integer called start
	   A intger called end
           A predicate function called compare
Use: Selects a pivot element and then partitions the vector around the pivot
Returns: A integer, pivotIndex
*/
template <class T>
int partition(vector<T>& set, int start, int end, bool (*compare)(const T&, const T&)) 
{
	//variables to hold the pivot index and the mid
    int pivotIndex = 0;
	int mid = 0;
	T pivotVal;

    //finds the mid point
	mid = (start + end) / 2; 

    //calls swapElements function to swap start and mid of the vector(set)
	swapElements(set[start], set[mid]); 

    //sets pivot index to start
	pivotIndex = start; 
    
    //sets pivotVal to the vector's start subscript
	pivotVal = set[start]; 

    //sorts
	for(int scan = start + 1; scan <= end; scan++) 
    { 
        if(compare(set[scan], pivotVal)) 
        {
			pivotIndex++;
			swapElements(set[pivotIndex],set[scan]);
		}
	}
    //swaps
	swapElements(set[start],set[pivotIndex]); 
	return pivotIndex;
}

/*
Function: quickSort()
Arguments: A reference to a vector of T data type called set
           A integer called start
	   A integer called end
	   A predicate function called compare
Use: Performs the recursive calls to implement the quick sort algorithm.
Returns: Nothing
*/
template <class T>
void quickSort(vector<T>& set, int start, int end, bool(*compare)(const T&, const T&)) 
{
	int pivotPoint = 0;

	if(start < end) 
    {
            // Get the pivot point
            pivotPoint = partition(set, start, end, compare);     
      		
            // Sort first sublist
            quickSort(set, start, pivotPoint - 1, compare);       
      		
            // Sort second sublist
            quickSort(set, pivotPoint + 1, end, compare);         
      }
}

/*
Function: quickSort()
Arguments: A reference to a T data type vector called set
           A predicate function, with two references to T data type variables
Use: Call the recursive quick sort function
Returns: Nothing
*/
template <class T>
void quickSort(vector<T>& set, bool(*compare)(const T&, const T&)) 
{
    //passes the vector(set), subscript of first element(0), subscript of last element(n-1), and the compasison function
	quickSort(set, 0, set.size() - 1, compare);
}




#endif
