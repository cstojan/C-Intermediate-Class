//*****************************************************************
// FILE:      Queue.h
// AUTHOR:    Cory Stojan
// LOGON ID:  Z1804761
// DUE DATE:  APRIL 10,2018
//
// PURPOSE:   Contains the headder for the Queue class.
//*****************************************************************

// include satements/ header guards
#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
#include <iostream>
#include <cstring>
#include <fstream>
#include <stdexcept>

using namespace std;

// Forward declaration of the Queue template class
template <class T>
class Queue;

// Forward declaration of the operator<< template function
template <class T>
std::ostream& operator<<(std::ostream&, const Queue<T>&);

// Queue Class Declaration
template <class T>
class Queue
{
	// Friends
	friend std::ostream& operator<< <>(std::ostream&, const Queue<T>&);  //not done
	
	//Private Data
	private:
	size_t stkCapacity;
	size_t stkSize;
	T* stkArray;
	int qfront;
	int qback;
	
	// Public Methods
	public:
	Queue();
	~Queue();
	Queue(const Queue& other);
	Queue<T>& operator=(const Queue&);
	
	void clear();
	size_t size() const;
	size_t capacity() const;
	bool empty() const;
	const T& front() const;
	const T& back() const;
	void push(const T&);
	void pop();
	void reserve(size_t);
};

/*
    Default Constructor - Sets data members to default values. Takes no arguments. Default Constructor for 
    the Queue class.
*/
template <class T>
Queue<T>::Queue()
{
	stkCapacity = 0;
	stkSize = 0;
	stkArray = nullptr;
	qfront = 0;
	qback = stkCapacity - 1;
}


/* 
    Destructor - Delets the dynamic memory for the queue array. Destructor for the Queue class. 
*/
template <class T>
Queue<T>::~Queue()
{
    // set values to default
	stkCapacity = 0;
	stkSize = 0;
    
    // delete the arry
	delete[] stkArray;
}

/*
    Copy Constructor - Creats a new object by copying an exisiting object.  Copy constructor for the Queue 
    Class
*/
template <class T>
Queue<T>::Queue(const Queue& other)
{
    // copy the size and capacity
	stkCapacity = other.stkCapacity;
	stkSize = other.stkSize;
	
    // check for empty capacity
	if (stkCapacity == 0)
	{
		stkArray = nullptr;
	}
    // if not empty, create new array with copied sized.
	else
	{
		stkArray = new int[stkCapacity];
	}
	
    // copy elements of the array.
	for (size_t i = 0; i < stkSize; i++)
	{
		stkArray[i] = other.stkArray[i];
	}
    
    // copy qfront and qback data memebers.
	qfront = other.qfront;
	qback = other.qback;
}

/*
   Copy operator (=)  - Copys an existing object into another exisiting object. Used in the Queue class.
*/
template <class T>
Queue<T>& Queue<T>::operator=(const Queue& other)
{
	// check to see if the two classes are the same
	if (this != &other)
	{
		// copy size and capacity
		stkCapacity = other.stkCapacity;
		stkSize = other.stkSize;
		
		// check capacity and create a new array
		if (stkCapacity > 0)
		{
			stkArray = new int[stkCapacity];
		}
        
        // else set the arrary to nullptr
		else
		{
			stkArray = nullptr;
		}
		
			// copy elements
			for (size_t i = 0; i < stkSize; ++i)
			{
				stkArray[i] = other.stkArray[i];
			}
            
            // copy qfornt and qback elements.
			qfront = other.qfront;
			qback = other.qback;
	}
	
	// return class
	return *this;
}


/*
    operator << - Friend of the Queue class. Cout's Two Queue objects.
*/
template <class T>
std::ostream& operator<<(std::ostream& lhs, const Queue<T>& rhs)
{
    // Local Varibles
	size_t current, i;

    // print array
	for (current = rhs.qfront, i = 0; i < rhs.stkSize; i++)
	{
		// Print queue element at subscript i
		lhs << rhs.stkArray[current] << ' ';

		// Increment i, wrapping around to front of queue array if necessary     
		current = (current + 1) % rhs.stkCapacity;
	}
    
	return lhs;
}

/*
    Clear - Used in the Queue Class. Takes no arguments and returns nothing. Clears the array and sets data members to default values.
*/
template <class T>
void Queue<T>::clear()
{
	stkCapacity = 0;
	stkSize = 0;
	stkArray = nullptr;
	qfront = 0;
	qback = 0;
}
	
/*
    Size - Used in the Queue Class. Takes not arguments and returns the stkSize data member.
*/
 template <class T>
size_t Queue<T>::size() const
{
	return stkSize;
}

/*
    Capacity - Used in the Queue class. Takes no arguments and returns the stkCapacity data member.
*/
 template <class T>
size_t Queue<T>::capacity() const
{
	return stkCapacity;
}

/*
    Empty - Used in the Queue class. Takes no arguments. Returns a boolian true value if the stkSize is 0.
    Otherwise it returns a false value.
 */
 template <class T>
bool Queue<T>::empty() const
{
	if (stkSize == 0)
	{
		return true;
	}
	
	return false;
}

/*
    front - Used in the Queue class. Takes no arguments. Returns a constant refrence to the qfront elemet of
    the array in the Queue class.
*/
template <class T>
const T& Queue<T>::front() const
{
    // check for empty. Throw a underflow error if empty.
	if (empty())
	{
		throw underflow_error("front()");
	}

	return stkArray[qfront];
}

/*
    back - Used in the Queue class. Takes no arguments. Returns a constant refrence to the qback elemtn of
    the array in the Queue class.
*/    
template <class T>
const T& Queue<T>::back() const
{
    // check for empty. Throw a underflow error if empty.
	if (empty())
	{
		throw underflow_error("back()");
	}
	
	return stkArray[qback];
}

/* 
    push  - Used in the Queue class. Takes a refrence to a constant item specified in the template. Inserts
    the argument into the array. Wrapps the array elements as needed. Also calls Reserve as needed 
    to increase capacity.
*/
template <class T>
void Queue<T>::push(const T& val)
{
    // check stkCapacity to see if more capcity is needed.
	if (stkSize == stkCapacity)
	{
		if (stkCapacity == 0)
		{
			reserve(1);
		}
		else
		{
			reserve(stkCapacity * 2);
		}
	}
    
    // sets qback. wrapps if needed
	qback = (qback + 1) % stkCapacity;	
    // inserts values
	stkArray[qback] = val;
    // increases stkSize.
	++stkSize;
}

/*
    pop - Used in the Queue class.Takes no arguments and returns nothing. checks if the Queue is empty.
    throws an error if it is.
    Increments the qfront subscript and wrapps around if needed. decrements qsize by 1.
 */
    template <class T>
void Queue<T>::pop()
{
    // checks if the Queue is empty. Throws and error if it is.
	if(empty())
	{
		throw underflow_error("pop()");
	}
    
    // sets the qfront value. wraps if necessary
	qfront = (qfront + 1) % stkCapacity;
    // decreases stkSize.
	--stkSize;
}

/* 
    reserve - Allocates space for a new capacity. Returns nothing. Used in the Queue class.
*/
template <class T>
void Queue<T>::reserve(size_t n)
{
	// checks to see if new capacity is the same as current capacity.
	if (n < stkSize || n == stkCapacity)
	{
		return;
	}
   
   // allocates memory for the array
	T* tempArray = new T[n];
    
    // copies the elements wrapps if necessary.
	int current = qfront;
	for (size_t i = 0; i < stkSize; ++i)
	{
		tempArray[i] = stkArray[current];
		current = (current + 1) % stkCapacity;
	}
    
    // sets values to accomidate new size.
   stkCapacity = n;
   qfront = 0;
   qback = stkSize - 1;
   delete[] stkArray;
   stkArray = tempArray;
}

#endif /*QUEUE_N*/
