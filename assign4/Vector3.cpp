//*****************************************************************
// FILE:      Vector.cpp
// AUTHOR:    Cory Stojan
// LOGON ID:  Z1804761
// DUE DATE:  08MAR18
//
// PURPOSE:   Contains the source code for the Vector3 class.
//*****************************************************************

// include satements
#include "Vector3.h"
#include <iostream>
#include <cstring>
#include <fstream>


// Constructor For the Vector Class
Vector3::Vector3(float intx, float inty, float intz)
{
	variables[0] = intx;
	variables[1] = inty;
	variables[2] = intz;
}

// << operator overloading. 
ostream& operator << (ostream& lhs, const Vector3& rhs)
// The stream insertion operator should be overloaded so that a Vector3 can be sent to the standard output.
// ex: (#,#,#)
{
   lhs << "(" << rhs.variables[0] << ", " << rhs.variables[1] << ", " << rhs.variables[2] << ")" << endl;

   return lhs;     
}

// + operator overloading
Vector3 Vector3::operator+(const Vector3& rhs) const
// The addition operator should be overloaded to take two Vector3s and return a Vector3. 
// The components of the result are computed by simply adding the components of the operands.
{
	// stores the first vector for use late
	Vector3 newVector3 = *this;

	// computes values in the variables array
	newVector3.variables[0] += rhs.variables[0];
	newVector3.variables[1] += rhs.variables[1];
	newVector3.variables[2] += rhs.variables[2];
	
	return newVector3;
}

// - operand overaloading
Vector3 Vector3::operator-(const Vector3& rhs) const
// The binary subtraction operator should also be overloaded to take two Vector3s and return a Vector3. 
// The result is the component-wise difference of the operands.
{
	// stores the first vector for use late
	Vector3 newVector3 = *this;

	// computes values in the variables array
	newVector3.variables[0] -= rhs.variables[0];
	newVector3.variables[1] -= rhs.variables[1];
	newVector3.variables[2] -= rhs.variables[2];
	
	return newVector3;
}

// * operand overloading (1 of 3)
float Vector3::operator*(const Vector3& rhs) const
// This method takes to Vector3 objects and multiplies the values stored insid by its coorospoing Vecotr3 value. then it adds all the values together.
// This method returns a float value.
{
	// stores the first vector for use late
	Vector3 newVector3 = *this;

	// computes values in the variables array
	newVector3.variables[0] *= rhs.variables[0];
	newVector3.variables[1] *= rhs.variables[1];
	newVector3.variables[2] *= rhs.variables[2];
	// add all 3 variables array values
	float result = newVector3.variables[0] + newVector3.variables[1] + newVector3.variables[2];
	
	return result;
}

// * operand overloading (2 of 3)
Vector3 Vector3::operator*(float rhs) const
// This method takes a Vecotr3 object and a float. Each value of the Vector3 object is multiplied by the float value.
// This method returns a Vecotr3 object.
{
	// stores the first vector for use late
	Vector3 newVector3 = *this;

	// computes values in the variables array
	newVector3.variables[0] *= rhs;
	newVector3.variables[1] *= rhs;
	newVector3.variables[2] *= rhs;
	
	return newVector3;
}

// * operand overloading (3 of 3)
Vector3 operator*(const float lhs, const Vector3& rhs)
// This function is a friend of the Vector3 class. It takes a float and a Vecotr3 object. The values inside the Vector3 object are multiplied by the float value.
// This function returns a Vector3 object.
{
	// stores the first vector for use late
	Vector3 newVector3 = rhs;

	// computes values in the variables array
	newVector3.variables[0] *= lhs;
	newVector3.variables[1] *= lhs;
	newVector3.variables[2] *= lhs;
	
	return newVector3;
}

// [] overloading (1 of 2)
float Vector3::operator[](int index) const // For reading
// The indexing operator should be overloaded to provide accessor methods for the class. 
// Subscript 0 should provide access to the x component value of the vector; subscript 1 to the y component and subscript 2 to the z component.
// This method returns a float value (the value inside the refrenced variable.
{
	// finds and returns the index variable
	return variables[index];
	
}

// [] overloading (2 of 2)
float & Vector3::operator[](int index)       // For writing
// The indexing operator should be overloaded to provide accessor methods for the class. 
// Subscript 0 should provide access to the x component value of the vector; subscript 1 to the y component and subscript 2 to the z component.
// This method returns a float value (the value inside the refrenced variable.
{
	// finds and returns the index variable
	return variables[index];
	
}


bool Vector3::operator ==(const Vector3& rhs) const
// The equality operator should be overloaded to compare two Vector3s. 
// The two vectors are considered equal only if they are componentwise equal.
// returns a bool value.
{
	// stores the first vector for use late
	Vector3 newVector3 = *this;
	
	// compares each value. if they are not equal, returns false.
	if (newVector3.variables[0] != rhs.variables[0])
	{
		return false;
	}
	if (newVector3.variables[1] != rhs.variables[1])
	{
		return false;
	}
	if (newVector3.variables[2] != rhs.variables[2])
	{
		return false;
	}
	
	return true;
}

