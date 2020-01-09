//*****************************************************************
// FILE:      Book.h
// AUTHOR:    Cory Stojan
// LOGON ID:  Z1804761
// DUE DATE:  13FEB18
//
// PURPOSE:   Contains the hedder file for the Book class.
//*****************************************************************

// Header files ( including headder guards)
#ifndef BOOK_H
#define BOOK_H

using namespace std;

// Book class. Holds information about a book. (ISBN, Title, Price, # of books in stock)
class Book
{
	private:

	char ISBN[11];
	char Title[41];
	double Price;
	int Stock;

	public:
	Book(); // default constructor
	Book(char*, char*, double, int); // alternet constructor
	char* getISBN();
	char* getTitle();
	double getPrice();
	int getQuantity();
	void setPrice(double);
	void setQuantity(int);
	int fulfillOrder(int);
	void print();
};

// Headder guard
#endif /*BOOK_H*/
