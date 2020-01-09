/*
    Programmer: Cory Stojan
    Class/Section: CSCI 241 Section 1
    Due Date: 26 April 2018
    Purpose: Contains the template class and code for the mergesort algorthem
*/

// Headder Guard
#ifndef MERGESORT_H
#define MERGESORT_H

// Include Statements
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
// (ORDER OF FUNCTIONS DO MATTER) <--- LAME

/*
Function: swap() (avoids repeating code)
Arguments: A reference to a T data type vector called temp
	   A reference to a T data type vector called set
	   A reference to a integer called varOne
	   A refernece to a integer called varTwo
Use: Takes the element of the vector(set) at location varOne and sets it to vector(temp) at location varTwo
     Adds one to both of the integer varibles to move to next subscript
Returns: Nothing
*/
template <class T>
void swap(vector<T>& temp, vector<T>& set, int& varOne, int& varTwo) 
{
	temp[varTwo] = set[varOne];
	varOne++;
	varTwo++;
}

/*
Function: merge()
Arguments: A reference to a T data type vector called set
	   A integer called low
	   A integer called mid
           A integer called high
	   A predicate function called compare
Use: Merges the two sorted subvectors
Returns: Nothing
*/
template <class T>
void merge(vector<T>& set, int low, int mid, int high, bool (*compare)(const T&, const T&)) 
{
   // Create temporary vector to hold merged subvectors
   vector<T> temp(high - low + 1);

   int i = low;      // Subscript for start of left sorted subvector
   int j = mid+1;    // Subscript for start of right sorted subvector
   int k = 0;        // Subscript for start of merged vector

   // While not at the end of either subvector
   while (i <= mid && j <= high) 
   {
      if (compare(set[j], set[i]))
      //calls swap() to swap the elements
	  swap(temp, set, j, k); 
      else
	  swap(temp, set, i, k);
   }

   // Copy over any remaining elements of left subvector
   while (i <= mid)
	swap(temp, set, i, k);

   // Copy over any remaining elements of right subvector
   while (j <= high)
	swap(temp, set, j, k);

   // Copy merged elements back into original vector
   for (i = 0, j = low; j <= high; i++, j++)
      set[j] = temp[i];
}

/*
Function: mergeSort()
Arguments: A reference to a T data type vector called set
	   A predicate function called compare
	   A integer called low
	   A intger called high
Use: Divides a vector into two subvectors, sorts them, and then merges the two sorted subvectors.
Returns: Nothing
*/
template <class T>
void mergeSort(vector<T>& set, int low, int high, bool (*compare)(const T&, const T&)) 
{
   int mid;

   if (low < high) 
   {
      mid = (low + high) / 2;

      mergeSort(set, low, mid, compare); //sorts the vector
      mergeSort(set, mid+1, high, compare); //sorts the vector

      merge(set, low, mid, high, compare); //merges the to vectors
   }
}

/*
Function: mergeSort()
Arguments: A reference to a T data type vector called set, 
        A predicate function called compare
Use: Calls the recursive merge sort function
Returns: Nothing
*/
template <class T>
void mergeSort(vector<T>& set, bool (*compare)(const T&, const T&)) 
{
    //passes the vector(set), subscript of fist vector element(o), subscript of last vector element(n-1), and the camparison function
	mergeSort(set, 0, set.size()-1, compare);
}

#endif
