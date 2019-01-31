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

// METHOD DEFINITONS FOR THE STACK CLASS

/****************************************************************

   FUNCTION: ostream& operator<<(ostream& leftOp, const Stack<T>& rightOp

   ARGUMENTS: 2 - out stream on the left, a stack object on the right

   RETURNS: the stack

   PURPOSE: to read the stack

****************************************************************/
template <class T>
ostream& operator<<(ostream& leftOp, const Stack<T>& rightOp){

	Node<T>* ptr;

	for (ptr = rightOp.stkTop; ptr != NULL; ptr = ptr->next)
		leftOp << ptr->data << ' ';
//	Going through the array and printing it
	return leftOp;
}



/****************************************************************

   CONSTRUCTOR:Stack<T>::Stack()

   ARGUMENTS:  none

   RETURNS:    nonthing

   PURPOSE:    default constructor

****************************************************************/
template <class T>
Stack<T>::Stack(){

	stkTop = NULL;
	stkSize = 0;
}


/****************************************************************

   FUNCTION:int Stack<T>::size() const

   ARGUMENTS: none

   RETURNS: int of the stack size

   PURPOSE: to return the stack size; makes getting it much easier

****************************************************************/
template <class T>
int Stack<T>::size() const{
	return this->stkSize;
}



/****************************************************************

   FUNCTION:bool Stack<T>::empty() const

   ARGUMENTS: none

   RETURNS: 1 if true; 0 if false; a bool bro

   PURPOSE: to see if the stack is empty

****************************************************************/
template <class T>
bool Stack<T>::empty() const{
        if(size()==0)
                return 1;
        else
                return 0;
}



/****************************************************************

   FUNCTION:void Stack<T>::push(int item)

   ARGUMENTS:1 - an int

   RETURNS: nonthing

   PURPOSE: to add a node

****************************************************************/
template<class T>
void Stack<T>::push(int item){

	Node<T>* newNode = new Node<T>(item, stkTop);
	stkTop = newNode;
	stkSize++;
}                                 //put something into queue



/****************************************************************

   FUNCTION: Stack<T>::Stack(const Stack<T>& stackToCopy)

   ARGUMENTS: a stack object to read

   RETURNS: nothing

   PURPOSE: copy constructor

****************************************************************/
template <class T>
Stack<T>::Stack(const Stack<T>& stackToCopy){

   stkTop = NULL;
   copyList(stackToCopy);
   stkSize = stackToCopy.stkSize;
}	// Copy Constructor




/****************************************************************

   FUNCTION:void Stack<T>::copyList(const Stack<T>& stkToCopy)

   ARGUMENTS: 1 - a readable stack object

   RETURNS: nothing

   PURPOSE: to copy a stack

****************************************************************/
template <class T>
void Stack<T>::copyList(const Stack<T>& stkToCopy){

   Node<T>* ptr, * newNode, * last = NULL;
   for (ptr = stkToCopy.stkTop; ptr != NULL; ptr = ptr->next)
      {
      newNode = new Node<T>(ptr->data);
      if (last == NULL)
         stkTop = newNode;
      else
         last->next = newNode;

      last = newNode;
      }
}



/****************************************************************

   FUNCTION:void Stack<T>::clear()

   ARGUMENTS: none

   RETURNS: none

   PURPOSE: to "clear" a stack of its data

****************************************************************/
template <class T>
void Stack<T>::clear(){

	if (stkSize != 0)
		pop();

	stkTop = NULL;
        stkSize = 0;

}                                   // set the object to "0"



/****************************************************************

   FUNCTION: void Stack<T>::pop()

   ARGUMENTS: none

   RETURNS: none

   PURPOSE: to take the stkTop data off

****************************************************************/
template <class T>
void Stack<T>::pop(){


// Remove first node in list
	Node<T>* delNode = stkTop;
	stkTop = stkTop->next;

// If queue is now empty, make sure both pointers are NULL
	delete delNode;
	stkSize--;
}             //pop the slot where qFront is


/****************************************************************

   FUNCTION: Stack<T>& Stack<T>::operator=(const Stack<T>& rightOp)

   ARGUMENTS:a const stack reference

   RETURNS: a copied stack obj

   PURPOSE: to copy one constructor to another

****************************************************************/
template <class T>
Stack<T>& Stack<T>::operator=(const Stack<T>& rightOp)		//Assignment Operator
{
   if (this != &rightOp)
      {
	      clear();
	      copyList(rightOp);
	      stkSize = rightOp.stkSize;
      }

   return *this;
}




/****************************************************************

   FUNCTION: T Stack<T>::top() const

   ARGUMENTS: none

   RETURNS: the data found at the top of the stack

   PURPOSE: to return the data found at the top of the stack

****************************************************************/
template <class T>
T Stack<T>::top() const{      //show the slot where front is

	return stkTop->data;
}



/****************************************************************

   FUNCTION: Stack<T>::~Stack()

   ARGUMENTS: none

   RETURNS: none

   PURPOSE: Destructor

****************************************************************/
template <class T>
Stack<T>::~Stack(){	// Destructor

clear();
}

#endif
