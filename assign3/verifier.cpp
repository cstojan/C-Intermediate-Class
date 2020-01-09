//*****************************************************************
// FILE:      verifier.cpp
// AUTHOR:    Cory Stojan
// LOGON ID:  Z1804761
// DUE DATE:  27FEB18
//
// PURPOSE:   Contains the source code for the Verifier class.
//*****************************************************************

// include satements
#include "verifier.h"
#include <iostream>
#include <cstring>
#include <fstream>

// Global varaibles
#define MAXROWSIZE 9
#define MAXCOLSIZE 9

// functions/ meathods

// Constructor
Verifier::Verifier()
{

}

// readGrid takes a filename and opens the file and stores the numbers into an array. This function does not return anything.
void Verifier::readGrid(const char* filename)
{
	// create a stream
	ifstream myfile;

	// create a string for the filename and open the file
	char newFilenName[100] = " ";
	strcpy(newFilenName, filename);
	myfile.open(newFilenName, ios::in);
	if (!myfile)
	{
		myfile.close();
		cout << "failed to open file";
	}

	// store the values in the file to an array.
	for (int i = 0; i < MAXCOLSIZE; i ++)
	{
		for (int j = 0; j < MAXROWSIZE; j++)
		{
			myfile >> sudokuGrid[i][j];
		}
	}

	// close file
	myfile.close();
}
	
// printGrid prints the values stored in an array. printGrid takes no arguments and returns nothing.
void Verifier::printGrid()
{
	// display the numbers and the flashy outline
	for (int i = 0; i < MAXCOLSIZE; i ++)
	{
		cout << endl;
		if (i % 3 == 0)
		{
			cout << " - - - - - - - - - - - - -" << endl;
		}
		for (int j = 0; j < MAXROWSIZE; j++)
		{
			if (j % 3 == 0)
			{
				cout << " |";
			}
			cout << " " << sudokuGrid[i][j];
			if ( j == 8)
			{
				cout << " |";
			}	
		}
	}
	cout << "\n - - - - - - - - - - - - -" << endl;
}

// verifySolution takes no arguments, returns a booliean value. This method verifies a solution to a sudoku puzzle.
bool Verifier::verifySolution()
{
	// set array positon variables
	int i = 0;
	int j = 0;
	int ref;

	// GET RID OF SOME OF THESE
	bool colnumberArray[9] = {false, false, false, false, false, false, false, false, false};
	bool rownumberArray[9] = {false, false, false, false, false, false, false, false, false};
	bool gridnumberArray[9] = {false, false, false, false, false, false, false, false, false};

	// verify collumn
	for(j = 0; j < MAXROWSIZE; j++)
	{
		bool colnumberArray[9] = {false, false, false, false, false, false, false, false, false};
		for(i = 0; i < MAXCOLSIZE; i++)
		{
			ref = sudokuGrid[j][i];
			
			if (colnumberArray[ref - 1])
			{
				return false;
			}
			else
			{
				colnumberArray[ref - 1] = true;
			}
		}
	}

	// reset array positon variables
	i = 0;
	j = 0;

	// verify row
	for(j = 0; j < MAXROWSIZE; j++)
	{
		bool rownumberArray[9] = {false, false, false, false, false, false, false, false, false};
		for(i = 0; i < MAXCOLSIZE; i++)
		{
			ref = sudokuGrid[i][j];
			
			if (rownumberArray[ref - 1])
			{
				return false;
			}
			else
			{
				rownumberArray[ref - 1] = true;
			}
		}
	}

	// verify 3x3 grid
	// reset array positon variables
	i = 0;
	j = 0;
	int gridRow = 0;
	int gridCol = 0;

	// x grid section
	for (int gridX = 0; gridX < 3; gridX++)
	{
		gridRow = gridX * 3;

		// y grid section
		for (int gridY = 0; gridY < 3; gridY++)
		{
			bool colnumberArray[9] = {false, false, false, false, false, false, false, false, false};
			gridCol = gridY * 3;

			// rows included
			for(j = gridCol; j < gridCol + 3; j++)
			{
				// collumns included
				for(i = gridRow; i < gridRow + 3; i++)
				{
					ref = sudokuGrid[j][i];
					if (colnumberArray[ref - 1])
					{
						return false;
					}
					else
					{
						colnumberArray[ref - 1] = true;
					}
				}
			}
		}
	}

return true;
}

