//*****************************************************************
// FILE:      verifier.h
// AUTHOR:    Cory Stojan
// LOGON ID:  Z1804761
// DUE DATE:  27FEB18
//
// PURPOSE:   Contains the hedder file for the Verifier class.
//*****************************************************************

// Header files ( including headder guards)
#ifndef VERIFIER_H
#define VERIFIER_H

using namespace std;

class Verifier
{
	private:

	int sudokuGrid[9][9];

	public:
	Verifier();  // default constructor
	void readGrid(const char* );
	void printGrid();
	bool verifySolution();

};

// Headder guard
#endif /*VERIFIER_H*/
