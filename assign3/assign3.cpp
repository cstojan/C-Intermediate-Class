/*********************************************************************
   PROGRAM:    CSCI 241 Assignment 3
   PROGRAMMER: your name
   LOGON ID:   your z-ID
   DUE DATE:   27FEB18

   FUNCTION:   This program tests the functionality of the Verifier
               class.
*********************************************************************/  

#include <iostream>
#include <string>
#include "verifier.h"

using std::cout;
using std::endl;
using std::string;

#define NUM_FILES 7

int main()
{
	// Declare
   Verifier grid;
   string fileName;
   
   cout << "\nSudoku Verifier\n";
   
   for (int i = 1; i <= NUM_FILES; i++)
	{     
		cout << endl;

		// Construct file pathname
		fileName = string("/home/turing/t90kjm1/CS241/Data/Spring2018/Assign3/solution")
		+ (char)('0' + i) + ".txt";

		// Read the solution file as input
		grid.readGrid(fileName.c_str());

		// Print the Sudoku grid
		grid.printGrid();

		// Verify whether or not the solution is correct
		if (grid.verifySolution())
			cout << "\nThis is a valid Sudoku solution\n";
		else
			cout << "\nThis is not a valid Sudoku solution\n";
	}

   return 0;
}
