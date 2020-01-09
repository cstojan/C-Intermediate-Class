/*********************************************************************
   PROGRAM:    CSCI 241 Assignment 7
   PROGRAMMER: Cory Stojan
   LOGON ID:   z1804761
   DUE DATE:   19 April 18

   FUNCTION:   This File Contains the sourse code for assignment 7.
*********************************************************************/  

// include satements/ header guards
#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
#include <stdexcept>
#include <stdlib.h>
#include <iomanip>

using std::cout;
using std::endl;
using std::ostream;
using std::underflow_error;

// Node Structure
template<class T>
struct Node
{
    
    //Data Members
           //item to be inserted into the queue
    T item;
    
        //point to the next node in the linked list
 	Node<T>* ptr;

    //Methods
        // Constructor takes one argument of the template parameter type (const data). the constructor should copy the
        //     argument into the queue node and set the nod's pointer to nullptr
	Node(const T& newVal) 
    {
        ptr = nullptr;
        item = newVal;
    }
    
};


// Forward declaration of the Queue template class
template <class T>
class Queue;

// Forward declaration of the operator<< template function
template <class T>
std::ostream& operator<<(std::ostream&, const Queue<T>&);

// Queue Class
template <class T>
class Queue
{
    private:
    //Data members
    Node<T>* qFront; // pointer to the front node
    Node<T>* qBack;  // pointer to the back node
    size_t queueSize; // number of elements in the array
    
    public:
    //Methods
        //constructor
    Queue();
        // destructor
    ~Queue();
        // copy constructor
    Queue(const Queue&);
        // operator =
    Queue<T>& operator=(const Queue&);
        // clear
    void clear();
        // size
    size_t size() const;
        // empty
    bool empty() const;
        // front
    const T& front() const;
        // back
    const T& back() const;
        // push
    void push(const T&);
        // pop
    void pop();
    
    //Friends
        // operator<<
   friend std::ostream& operator<< <>(std::ostream&, const Queue<T>&);
};

/*
Function/Method Name: Queue()
Arguments: None
Return: N/A
Basic Function: Basic Constructor. Sets data pointers to nullptr and sets queueSize to zero.
*/
template <class T>
Queue<T>::Queue()
{
    // set data member to default values
    qFront = nullptr;
    qBack = nullptr;
    queueSize = 0;
}


/*
Function/Method Name: ~Queue()
Arguments: None
Return: N/A
Basic Function: Queue destructor. This function calls the clear() method.
*/
template <class T>
Queue<T>::~Queue()
{
    // call the clear method.
    clear();
}


/*
Function/Method Name: copy constructor
Arguments: 
Return 
Basic Function: Creates a new object that is an exact copy of an existing object
*/
template <class T>
Queue<T>::Queue(const Queue& other)
{
    //sets data member to default values
	qFront = nullptr;
    qBack = nullptr; 
	queueSize = 0;

    //creates a new Node called ptr, used to point to the next node in Queue
	Node<T>* ptr; 
    
    //calls push to insert the iteam into the new queue
	for (ptr = other.qFront; ptr != nullptr; ptr = ptr->ptr)
		push(ptr->item);
}

/*
Function/Method Name: operator=
Arguments: 
Return 
Basic Function: The copy assignment operator copys one object into another existing object.
*/
template <class T>
Queue<T>& Queue<T>::operator=(const Queue& other)
{
    // if not equal,
	if (this != &other) 
    { 
        // will call clear.
		clear();     
        
        // Then create a new Node pointer
		Node<T>* ptr; 
        
        // Procedes to copy the elements from the passed in Queue, into the new one
		for (ptr = other.qFront; ptr != nullptr; ptr = ptr->ptr) 
			push(ptr->item);
	}
    
    // else, if they are equal, return it
	return *this; 
}

/*
Function/Method Name: operator<<
Arguments
Return 
Basic Function: This function is a friend of the Queue class
*/
template <class T>
std::ostream& operator<<(std::ostream& lhs, const Queue<T>& rhs)
{
    // creates a new Node called current
 	Node<T>* current;

    // output string
	for (current = rhs.qFront; current != nullptr; current = current->ptr) 
    {
		lhs << current->item << "  ";
	}

return lhs;
}


/*
Function/Method Name: Clear
Arguments: None
Return: None
Basic Function: Sets qBack to the empty state.
*/
template <class T>
void Queue<T>::clear()
{
    // use pop() to clear the object.
	while(queueSize != 0)
        pop();
}


/*
Function/Method Name: size()
Arguments: None
Return: (size_t) The current size of the queue.
Basic Function
*/
template <class T>
size_t Queue<T>::size() const
{
    return queueSize; // SMILE :) 
}


/*
Function/Method Name: empty()
Arguments: None
Return: (bool) True/False if queue is empty.
Basic Function: Returns True if there is no data stored in the queue, otherwise it returns false;
*/
template <class T>
bool Queue<T>::empty() const
{
    // check to see if the queue is empty
	if (queueSize == 0)
	{
		return true;
	}
	
    // if not. return false
	return false;
}


/*
Function/Method Name: front()
Arguments: None
Return: Refrence to a constant item of the template paramater type.
Basic Function: if empty. throw underflow error, otherwise returns data stored in the front node of the queue.
*/
template <class T>
const T& Queue<T>::front() const
{
    // check for empty. Throw a underflow error if empty.
	if (empty())
	{
		throw underflow_error("Queue underflow on front()");
	}

    // return qFront
	return qFront->item; 
}


/*
Function/Method Name: back()
Arguments: None
Return: Refrence to a constant item of the template parameter type.
Basic Function: if empty, throw underflow error. Otherwise returns data stored in the back node of the queue.
*/
template <class T>
const T& Queue<T>::back() const
{
    // check for empty. Throw a underflow error if empty.
	if (empty())
	{
		throw underflow_error("Queue underflow on back()");
	}
	
    // return qBack
	return qBack->item; 
}


/*
Function/Method Name: push()
Arguments: Refrence to a constant item of the template class.
Return: None
Basic Function: Inserts an item into the back of the queue and increments the queue size.
*/
template <class T>
void Queue<T>::push(const T& val)
{
    // creates a new Node and passes in the item to that Node
	Node<T>* newNode = new Node<T>(val); 
    
    // if empty, the front of the queue will be set to that Node
	if(empty()) 
		qFront = newNode;
    // else, queue is not empty, back queue will be set to that Node
	else
		qBack->ptr = newNode; 
        
    // takes qBack and sets it to the newNode
	qBack = newNode; 
    
    // adds one to queue size
	queueSize++; 
}


/*
Function/Method Name: pop()
Arguments: None
Return: None
Basic Function: Checks to see if queue is empty. If not, remove the item at the front of the queue and decrement the queue size.
*/
template <class T>
void Queue<T>::pop()
{
    // if empty, throw exception
	if(empty()) 
		throw underflow_error("queue underflow on pop()\n");

    // allocates memory for a new Node, that will be used to delete the desired node
	Node<T>* deleteNode = qFront;
    
    // sets the front equal to one element in front of qFront
	qFront = qFront->ptr; 

    // if front is null, sets back to nullptr
	if(qFront == nullptr) 
		qBack = nullptr;
    
    // deletes the desired node
	delete deleteNode; 
    
    // subtracts from the queue size after deletion
	queueSize--; 
}




#endif /*QUEUE_N*/