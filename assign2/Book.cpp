//*****************************************************************
// FILE:      Book.cpp
// AUTHOR:    Cory Stojan
// LOGON ID:  Z1804761
// DUE DATE:  13FEB18
//
// PURPOSE:   Contains the Source Code for the Book Class.
//*****************************************************************

// Headder files
#include "Book.h"
#include <cstring>
#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

// Default Constructor for the Book class.
Book::Book()
{
	strcpy(ISBN, "");
	strcpy(Title, "");
	Price = 0.00;
	Stock = 0;
}

// Alternet Constructor for the Book class. Arguments include an ISBN, Title, Price of book, Quantity in stock.
Book::Book(char* newISBN, char* newTitle, double newPrice, int newQuantity) // constructor method 2
{
	strcpy(ISBN, newISBN);
	strcpy(Title, newTitle);
	setPrice(newPrice);
	setQuantity(newQuantity);
}

// getISBN method gets the ISBN number from the book class and returns the ISBN array. It takes no arugments.
char* Book::getISBN()
{

	return ISBN;
}

// getTitle method gets the title number from the book class and returns the title array. It takes no arugments.
char* Book::getTitle()
{

	return Title;
}

// getPrice method gets the price from the book class and returns the price value. It takes no arugments.
double Book::getPrice()
{

	return Price;
}

// getQuantity method get the Stock quantity from the Book class and returns the Stock value. It takes no arguments.
int Book::getQuantity()
{

	return Stock;
}

// setPrice method sets the price value of the Book class. It takes a double value and returns nothing.
void Book::setPrice(double price)
{
	// error checks to see if the argument is a negitive number.
	if (price >= 0)
	{
		Price = price;
	}
	else
	{
		Price = 0;
	}
}

// setQuantity method sets the quantity in the Book class. it takes an intiger (# of book requested) and returns nothing.
void Book::setQuantity(int quantity)
{
	// error checks to see if there is enough in stock.
	if (quantity >= 0)
	{
		Stock = quantity;
	}
	// if there is not enough, it sets the value to 0.
	else
	{
		Stock = 0;
	}
}

// fulfillOrder method process an order and returns the number of book shipped. It takes an intiger (# of book requested)
int Book::fulfillOrder(int orderQuantity)
{
	// variables
	int shipment, quantity;

	// default vale of shipment
	shipment = 0;
	
	// gets the amount of books in stock
	quantity = getQuantity();

	// error checks to see there is a valid order (no negitive amount of books requested)
	if (orderQuantity < 0)
	{
		cout << "Order Error" << endl;
	}
	// complets order if # of books are in stock
	else if (orderQuantity >= 0 && orderQuantity < Stock)
	{
		shipment = orderQuantity;
		quantity = quantity - orderQuantity;
		setQuantity(quantity);
	}
	// ships number of book is stock if more books are requested then stock size.
	else
	{
		shipment = quantity;
		setQuantity(0);
	}
	// returns the amount of book shipped
	return shipment;
}

// print method prints information about a book. (ISBN, Title, Price, # in stock)
void Book::print()

{
	cout << left << setw(14) << ISBN << " " << setw(44) << Title << "  $" << setw(5) << Price << " " << right << setw(6) << Stock << endl;
}

