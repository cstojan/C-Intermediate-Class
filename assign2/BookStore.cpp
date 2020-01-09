//*****************************************************************
// FILE:      BookStore.h
// AUTHOR:    Cory Stojan
// LOGON ID:  Z1804761
// DUE DATE:  13FEB18
//
// PURPOSE:   Contains the Source Code for the BookStore class.
//*****************************************************************

// Headder Files
#include "Book.h"
#include "BookStore.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <iomanip>
#include <ios>

using namespace std;

// Default Constructor for the Bookstore class
Bookstore::Bookstore()
{
	numOfBooks = 0;
	for (int i = 0; i < MAX_ARRAY_SIZE; i++)
	{
		BookArray[i] = Book();
	}
}

// Alternet Constructor for the Bookstore class (uses a filename as a constructor)
Bookstore::Bookstore(const string& fileName )
{
	//Declare an input file stream variable
	ifstream inFile;

	// opens a file in binary mode
	inFile.open(fileName.c_str(), ios::in | ios::binary);

	// checks to see if it opens correctly
	if (!inFile)
	{
		inFile.close();
		perror("File Failed To Open");
	}
	
	// Read the database file into your BookStore object
	inFile.read((char*) this, sizeof(Bookstore));

	// Close File
	inFile.close();

	// Calls the sortByISBN to sort the books in the array by ISBN
	sortByISBN();
}

// Print method that prints the Books in the Bookstore class. It takes no arguments and returns nothing.
void Bookstore::print()
{
	cout << "\nBook Invintory Listing:" << endl;
	cout << endl << left << setw(15) <<  "ISBN " << left << setw(46) << "Title " << setiosflags( ios:: fixed )
		 << setprecision(2) << setw(11) << "Price " <<  setw(6) << "Qty.\n" << endl;

	// create a array (used for comparision)
	char isbn[2] = "";

	// prints the information about a book (checks to see if the array has a valid book or a default book)
	for (int i = 0; i < MAX_ARRAY_SIZE; i++)
	{
		int compare;
		compare = strcmp(isbn, BookArray[i].getISBN());

		// prints array elements that are vaild books. (doesnt display books that have an empty string)
		if(compare == 0)
		{

		}
		else
		{
			BookArray[i].print();
		}
	}
}

// sortByISBN method sorts an array by the ISBN. It takes no arguents and returns nothing.
void Bookstore::sortByISBN()
{
	// variables
	int i, j;
	Book bucket;

	// compares the arrays and sorts the array (using the insertion sort algorithm).
	for (i = 1; i < numOfBooks; i++)
	{
		bucket = BookArray[i];

		for (j = i; (j > 0) && (strcmp(BookArray[j-1].getISBN(), bucket.getISBN()) > 0); j--)
			BookArray[j] = BookArray[j-1];

		BookArray[j] = bucket;
    }
}

/* searchForISBN method uses an ISBN array and searches for it in the BookArray array. It returns in index to where the ISBN is in the arrray.
   If it doesnt find one. it returns -1 which is an indicator for it not being found. */
int Bookstore::searchForISBN(char* search)
{
	// variables
	int low = 0;
	int high = numOfBooks - 1;
	int mid;
	int position;
	int comparison;
	position = -1; // Default return Value

	// finds the middle of the array
	mid = (low + high) / 2;

	// compares the middle array ISBN to see if it is the same isbn or if it is a higher/ lower number.
    comparison = strcmp(search, BookArray[mid].getISBN());

	// ISBN is the same
	if (comparison == 0)
	{
		position = mid;
		return position;
	}

	// ISBN is a lower number than the middle ISBN
    else if (comparison < 0)
    {
        for (int i = 0; i < mid; i ++)
        {
       		if (strcmp(BookArray[i].getISBN(), search) == 0)
        	{
        		position = i;
        		return position;
			}
		}
	}

	// ISBN is a higher number than the middle ISBN
	else
    {
    	for (int i = mid + 1; i < numOfBooks; i ++)
        {
       		if (strcmp(BookArray[i].getISBN(), search) == 0)
        	{
        		position = i;
        		return position;
			}
		}
	}

	return position;
}

// processOrder method takes a filename as an argument. It reads the file and processes the file. It returns nothing.
void Bookstore::processOrders(const string& fileName)
{
	// declare a stream
	fstream inFile;

	// variables
	char orderNumber[7];
	char isbn[11];
	int orderQuantity = 0;
	int numShipped;
	double total = 0.00;

	// displays a title
	cout << "\nOrder Listing:\n" << endl;

	//Open inFile using the file name passed in as a parameter
	inFile.open(fileName.c_str(), ios::in);

	// check for successful open
	if (!inFile)
	{
		inFile.close();
		perror("File Failed To Open");
	}
	
	// read orderNumber from inFile
    inFile >> orderNumber;

	// reads and stores order values
	while (inFile.eof() == false)
	{

		// read isbn from inFile
		inFile >> isbn;

    	// read orderQuantity from inFile
    	inFile >> orderQuantity;

		// calls for the searchForISBN method to find a ISBN in the Bookstore
    	int index = searchForISBN(isbn);

		// if not found
    	if (index == -1)
        {
        	// print an error message for this order
        	cout << "Order: #" << orderNumber << " Error: ISBN: " << isbn << " Does Not Exist" << endl;
		}

		// if found
    	else
        	{
        		// proces order
        		numShipped = BookArray[index].fulfillOrder(orderQuantity);
        		total = (BookArray[index].getPrice()) * numShipped;

        		// print the results for this order
        		cout << "Order: #" << orderNumber <<" ISBN: " << isbn << "  Shipped: " << right << numShipped << " of " << left << orderQuantity << "  Total: $" << total << endl;
        	}

    	//Read next orderNumber from inFile
		inFile >> orderNumber;
    	}

   //Close input file
   inFile.close();
}
