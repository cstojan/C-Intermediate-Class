//*****************************************************************
// FILE:      VectorN.cpp
// AUTHOR:    Cory Stojan
// LOGON ID:  Z1804761
// DUE DATE:  27MAR18
//
// PURPOSE:   Contains the source code for the VectorN class.
//*****************************************************************

// Include Satements/Headders
#include "VectorN.h"
#include <iostream>
#include <cstring>
#include <fstream>

VectorN::VectorN() // default constructor
/*
The default constructor for the VectorN class takes no arguments and should initialize a 
new VectorN object to an empty vector array with a capacity of 0.
*/
{
	// default values for the VectorN data members
	capacity = 0;
	arrayVector = nullptr;
}

VectorN::VectorN(const double values[], size_t n) // alternate constructor
/*
This constructor for the VectorN class should initialize a new VectorN object to the values stored in the array values.
*/
{
	// stores n value in data member capacity
	capacity = n;
	// error checks
	if (capacity < 1)
	{
		arrayVector = nullptr;
	}

	// creats and inserts data into the VectorN class array
	else
	{
		arrayVector = new double[capacity];

		for (size_t i = 0; i < capacity; i++)
			{
				arrayVector[i] = values[i];
			}
	}
}

VectorN::VectorN(const VectorN& other) // copy constructor
/*
This "copy constructor" for the VectorN class should initialize a new VectorN object to the 
	same capacity and array contents as the existing VectorN object other.
*/
{
	// copy's capacty
	capacity = other.capacity;
	// error checking
	if (capacity == 0)
	{
		arrayVector = nullptr;
	}

	// copys elements of each VectorN class
	else
	{
		arrayVector = new double[capacity];
		
		for (size_t i = 0; i < capacity; i++)
		{
			arrayVector[i] = other.arrayVector[i];
		}
	}	
}

VectorN::~VectorN() // deconstructor
/*
The destructor for the VectorN class can simply call the clear() method described below.
*/
{
	// clears data members
	clear();
}

VectorN& VectorN::operator=(const VectorN& other) // assignment operator
/*
This overloaded copy assignment operator should assign one VectorN object (the object other) to another 
(the object that called the method, which is pointed to by this).
*/
{
	// Step 1 (check for identies)
 	if (this != &other)
 	{
		 // Step 2 (delete the VectorN array)
 		delete[] arrayVector;

 		// Step 3 (copy capacity)
 		capacity = other.capacity;

 		// Step 4 (create new array with capacity size) (also checks to see if capacity is 0)
 		if (capacity > 0)
		 arrayVector = new double[capacity];
 		else
		 arrayVector = nullptr;

		 // Step 5 (copys elements)
 		for (size_t i = 0; i < capacity; ++i)
 		arrayVector[i] = other.arrayVector[i];
 	}

 	// Step 6 (returns class)
 	return *this;
 }

void VectorN::clear() // clear method
/*
This method should properly set the instance back to a vector of zero elements. Delete the vector array, 
set the vector array pointer to nullptr, and set the vector capacity to 0.
*/
{
	// sets every data member to the default value.
	capacity = 0;
	arrayVector = nullptr;
	delete[] arrayVector;
}

size_t VectorN::size() const // size method
/*
Returns the size of the vector.
*/
{
	return capacity;
}

VectorN VectorN::operator+(const VectorN& rhs) const // additon operator
/*
The addition operator should be overloaded to take two VectorNs and return a VectorN.
	If the two operands are of different capacities, then only the first n components of each vector should be used in the 
	product where n is the capacity of the smaller of the two vectors. For example, (1, 2, 3) + (4, 5) should have a result of (5, 7).
*/
{
	VectorN newVectorN = *this;

		// finds smallest capacity and uses that size to comput the addition of the two arrays in each VectorN
		if (newVectorN.capacity > rhs.capacity)
		{
			// uses rhs capacity
			newVectorN.capacity = rhs.capacity;
			for (size_t i = 0; i < rhs.capacity; i++)
			{
				newVectorN.arrayVector[i] += rhs.arrayVector[i];
			}
		}
		// finds smallest capacity and uses that size to comput the addition of the two arrays in each VectorN
		else
		{
			// uses lhs capacity
			for (size_t i = 0; i < newVectorN.capacity; i++)
			{
				newVectorN.arrayVector[i] += rhs.arrayVector[i];
			}
		}

	return newVectorN;
}

VectorN VectorN::operator-(const VectorN& rhs) const // subtraction operator
/*
The binary subtraction operator should also be overloaded to take two VectorNs and return a VectorN. 
The result is the component-wise difference of the operands. For example (1, 2, 3) - (4, 6, 8) should have a 
result of (-3, -4, -5). As with addition, the result should have the capacity of the smaller operand.
*/
{
	// stores the lhs VectorN for use later in method.
	VectorN newVectorN = *this;

		// finds which capacity is larger and uses smaller value to compute the subtraction of the two VectorN arrays
		if (newVectorN.capacity > rhs.capacity)
		{
			// uses the rhs capacity
			newVectorN.capacity = rhs.capacity;
			for (size_t i = 0; i < rhs.capacity; i++)
			{
				newVectorN.arrayVector[i] -= rhs.arrayVector[i];
			}
		}
		// finds which capacity is larger and uses smaller value to compute the subtraction of the two VectorN arrays
		else
		{
			// uses lhs capacity
			for (size_t i = 0; i < newVectorN.capacity; i++)
			{
				newVectorN.arrayVector[i] -= rhs.arrayVector[i];
			}
		}
	// returns result
	return newVectorN;
}

double VectorN::operator*(const VectorN& rhs) const // multiplication operator (1 of 3)
/*
The first form, called the scalar product takes two VectorNs and produces a single double value. The scalar product is computed 
	by multiplying the corresponding components of the two vectors and adding the results. For example the scalar product of (1, 2, 3) and 
	(4, 5, 6) is (1 · 4) + (2 · 5) + (3 · 6) which equals 4 + 10 + 18 which gives a final result of 32.

If the two operands are of different capacities, then only the first n components of each vector should be used in the product 
	where n is the capacity of the smaller of the two vectors.
*/
{
	// stores the first vector for use late
	VectorN newVectorN = *this;
	int result;
	size_t newCapacity;

	// computes values in the variables array if the rhs VectorN has a larger capacity.
	if (newVectorN.capacity > rhs.capacity)
	{
		newCapacity = rhs.capacity;
		for (size_t i = 0; i < newCapacity; i++)
		{
			newVectorN.arrayVector[i] *= rhs.arrayVector[i];
		}
	}

	// computes values in the variables array if the rhs VectorN has a larger capacity.
	else
	{
		newCapacity = newVectorN.capacity;
		for (size_t i = 0; i < newCapacity; i++)
		{
			newVectorN.arrayVector[i] *= rhs.arrayVector[i];
		}
	}

	// add all variables array values
	for (size_t i = 0; i < newCapacity; i++)
	{
		result += newVectorN[i];
	}

	return result;
}

VectorN VectorN::operator*(float rhs) const // multiplication operator (2 of 3) (VectorN, Constant)
/*
The overloaded multiplication operators allow multiplication of a VectorN with a double constant. 
	For example, multiplying the vector (1, 2, 3) by 3 results in the vector (3, 6, 9). Two overloaded operators are 
	needed here, one to handle multiplication of the vector by the constant in that order, the other to handle multiplication 
	of the constant by the vector in that order. The results should be the same in both cases.
*/
{
	// stores the first vector for use late
	VectorN newVectorN = *this;

	// computes values in the variables array
	for (size_t i = 0; i < newVectorN.capacity; i++)
	{
		newVectorN.arrayVector[i] *= rhs;
	}

	return newVectorN;
}

VectorN operator*(const float lhs, const VectorN& rhs) // multiplication operator (3 of 3) friend (constant, VectorN)
/*
The other two overloaded multiplication operators allow multiplication of a VectorN with a double constant. 
	For example, multiplying the vector (1, 2, 3) by 3 results in the vector (3, 6, 9). Two overloaded operators are 
	needed here, one to handle multiplication of the vector by the constant in that order, the other to handle multiplication 
	of the constant by the vector in that order. The results should be the same in both cases.
*/
{
	// stores the first vector for use late
	VectorN newVectorN = rhs;

	// computes values in the variables array
	for (size_t i = 0; i < rhs.capacity; i++)
	{
		newVectorN.arrayVector[i] *= lhs;
	}

	return newVectorN;
}

ostream& operator << (ostream& lhs, const VectorN& rhs) // outpout operator 
// The output operator should be overloaded so that a VectorN can be sent to the standard output. An empty vector (capacity 0) should be printed as ().
{
	// checks to seee if capacity is 0
	if (rhs.capacity == 0)
	{
		lhs << "()" << endl;
	}

	else
	{
		// format and prints each element of the VectorN array
		lhs << "(";
		for (size_t i = 0; i < rhs.capacity; i++)
		{
			lhs << rhs.arrayVector[i];
			if (i == rhs.capacity - 1)
			{
				lhs << ")";
			}
			else
			{
				lhs << ", ";
			}
		}
	}

   return lhs;     
}

double VectorN::operator[](int index) const // <--- subscript operator (1 of 2) getting a value (reading)
/*
The subscript operator should be overloaded to provide accessor methods for the class. The provided subscript indicates 
	which value should be accessed from the dynamically-allocated array. For speed, no error checking needs to be done.
*/
{
	return arrayVector[index];
}

double & VectorN::operator[](int index) // <--- subscript operator (2 of 2) setting a value (writing)
/*
The subscript operator should be overloaded to provide accessor methods for the class. The provided subscript indicates 
	which value should be accessed from the dynamically-allocated array. For speed, no error checking needs to be done.
*/
{
	return arrayVector[index];
}

double VectorN::at(int sub) const // subscript operator variant (1 of 2)
/*
This method is a variant of the read form of operator[] that provides some error checking.
*/
{
	// error checking (through out of range)
	if (sub < 0 || sub >= (int)capacity)
	{
		throw out_of_range("subscript out of range");
	}
	
	// finds and returns the index variable
	else
	{
		return arrayVector[sub];
	}
}

double& VectorN::at(int sub) // subscript operator variant (2 of 2)
/*
This method is a variant of the write form of operator[] that provides some error checking.
*/
{
	// error checking (through out of range)
	if ((sub < 0) | (sub >= (int)capacity))
	{
		throw out_of_range("subscript out of range");
	}

	// finds and returns the index variable
	else
	{
		return arrayVector[sub];
	}

}

bool VectorN::operator ==(const VectorN& rhs) const // equality operator 
/*
The equality operator should be overloaded to compare two VectorNs. The two vectors are considered equal 
	only if they are componentwise equal. For example, (1, 2, 3) is equal to (1, 2, 3), but not to (4, 3, 2). 
		All components must be equal. If the operands have different capacities, then the vectors are automatically 
			not equal, regardless of the component values.
*/
{
	// stores the first vector for use late
	VectorN newVectorN = *this;

	// compares each value. if they are not equal, returns false.
	if ((newVectorN.capacity > rhs.capacity) | (rhs.capacity > newVectorN.capacity))
	{
		return false;
	}
	// compares each value in the array in both VectorN classes. Checks for a false value.
	for (size_t i = 0; i < rhs.capacity; i++)
	{
		if (newVectorN.arrayVector[i] != rhs.arrayVector[i])
			{
				return false;
			}
	}

	// If everything is equal, returns true value.
	return true;
}
