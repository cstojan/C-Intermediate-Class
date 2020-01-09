//*****************************************************************
// FILE:      VectorN.h
// AUTHOR:    Cory Stojan
// LOGON ID:  Z1804761
// DUE DATE:  08MAR18
//
// PURPOSE:   Contains the headder for the VectorN class.
//*****************************************************************

// include satements/ header guards
#ifndef VECTORN_H
#define VECTORN_H
#include <iostream>

using namespace std;

// VectorN Class
class VectorN
{
	// Friends
	friend VectorN operator*(const float, const VectorN&);
	friend ostream& operator<< (ostream&, const VectorN&);
	
	//Private Data
	private:
		
		double* arrayVector;
		size_t capacity;
	
	// Public Methods
	public:
	VectorN();
	VectorN(const double values[], size_t);
	VectorN(const VectorN&);
	~VectorN();
	VectorN& operator=(const VectorN&);
	void clear();
	size_t size() const;
	VectorN operator+(const VectorN&) const;
	VectorN operator-(const VectorN&) const;
	double operator*(const VectorN&) const;
	VectorN operator*(float) const;
	double & operator[](int);
	double   operator[](int) const;
	double at(int) const;
	double& at(int);
	bool operator ==(const VectorN&) const;
	
	

};

#endif /*VECTOR3_N*/
