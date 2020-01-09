//*****************************************************************
// FILE:      BookStore.h
// AUTHOR:    Cory Stojan
// LOGON ID:  Z1804761
// DUE DATE:  13FEB18
// 
// PURPOSE:   Contains the headder file for the Bookstore class.
//*****************************************************************

// Headder Files (include headder guards)
#ifndef BOOKSTORE_H
#define BOOKSTORE_H
#include <string>
#include "Book.h"
#include "BookStore.h"

using namespace std;

#define MAX_ARRAY_SIZE 31 // <-- constant intiger for the array size (BookArray) (very useful for corrections)

// Bookstore class. Stores an array of Books. (simulates a bookstore)
class Bookstore {
	private:
		Book BookArray[MAX_ARRAY_SIZE];
		int numOfBooks;

	public:
		Bookstore(); // default constructor
		Bookstore(const string&); // alternet constructor
		void print();
		void sortByISBN();
		int searchForISBN(char*);
		void processOrders(const string&);
		void insertion_sort(int, int);
		
};

// headder guard
#endif /*BOOKSTORE_H*/
