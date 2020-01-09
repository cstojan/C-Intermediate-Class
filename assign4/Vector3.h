//*****************************************************************
// FILE:      Vector.h
// AUTHOR:    Cory Stojan
// LOGON ID:  Z1804761
// DUE DATE:  08MAR18
//
// PURPOSE:   Contains the headder for the Vector3 class.
//*****************************************************************

// include satements/ header guards
#ifndef VECTOR3_H
#define VECTOR3_H
#include <iostream>

using namespace std;

// Vector3 Class
class Vector3
{
	// Friends
	friend ostream & operator << (ostream& lhs, const Vector3& rhs);
	friend Vector3 operator*(const float, const Vector3&);
	
	//Private Data
	private:
	float variables[3]; // pos 0 = x;  pos 1 = y;  pos 2 = z;
	
	// Public Methods
	public:
	Vector3(float = 0.0, float = 0.0, float = 0.0);
	Vector3 operator+(const Vector3& Vector3) const;
	Vector3 operator-(const Vector3& Vector3) const;
	float operator*(const Vector3& Vector3) const;
	Vector3 operator*(float) const;
	float operator[](int index) const; 
	float & operator[](int index);       
	bool operator==(const Vector3&) const;	

};

#endif /*VECTOR3_H*/
