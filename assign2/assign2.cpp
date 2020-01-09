/*********************************************************************
   PROGRAM:    CSCI 241 Assignment 2
   PROGRAMMER: Cory Stojan
   LOGON ID:   z1804761
   DUE DATE:   13FEB18
 
   FUNCTION:   This Program uses two custom header files and two source files to simulate a Bookstore.
   			   The program displays the contents of a bookstore, then it processes an order, then it
   			   displays the contents of the bookstore after it had processed the order.
*********************************************************************/

// Headder files
#include <iostream>
#include "Book.h"
#include "BookStore.h"

using namespace std;

// Main Program.
int main()
{
	Bookstore Bookstore1("bookdata"); 		// <-- creates a object
	Bookstore1.print(); 					// <-- prints data about the object
	Bookstore1.processOrders("orders.txt"); // <-- process an order
	Bookstore1.print(); 					// <-- prints object data after an order has been processed
	
	return 0;
}





