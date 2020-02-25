#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <stdexcept>

using namespace std;

template <class T>
struct Node
{
	T data;
	Node<T>* next;

	Node(const T& = T(), Node<T>* next = NULL);
};

// METHOD DEFINITIONS FOR THE NODE CLASS

/****************************************************************
   FUNCTION: template <class T>
		Node<T>::Node(const T& newData, Node<T>* newNext)
   ARGUMENTS:2 - a data reader and a pointer to a new node
   RETURNS: nothing
   PURPOSE: creates another node
****************************************************************/

template <class T>
Node<T>::Node(const T& newData, Node<T>* newNext)
{
	data = newData;
	next = newNext;
}
// Forward declaration of the Stack template class
template <class T>
class Stack;

// Forward declaration of the operator<< template function
template <class T>
ostream& operator<<(ostream&, const Stack<T>&);

template <class T>
class Stack
{
   // friend declaration for the template function - note the
   // special syntax

	Node<T>* stkTop;
	int stkSize;

public:
	friend ostream& operator<< <>(ostream&, const Stack<T>&);


	Stack();			// Default constructor

	int size() const;               //show the size
	bool empty() const;             // is it empty or not?

	void push(int);                 //put something into queue

	Stack(const Stack<T>& );	// Copy Constructor
	void copyList(const Stack<T>&);

	void clear();                   // set the object to "0"

	void pop();			//pop the slot where qFront is

	Stack<T>& operator=(const Stack<T>&);		//Assignment Operator

	T top() const;     		//show the slot where front is

	~Stack();			// Destructor
};

#endif
