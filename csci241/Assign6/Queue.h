#ifndef QUEUE_H
#define QUEUE_H

//*****************************************************************
// FILE:      Queue.h
// AUTHOR:    William Freriks
//
// PURPOSE:   Contains the declarations for the Queue class.
//*****************************************************************
#include <iostream>
#include <iomanip>
#include <fstream>
#include <stdexcept>

using namespace std;



class Queue
{
private:
    int * qArray;					// dynamic array
	unsigned qCapacity;				// array capacity
	unsigned qSize;					// the number of used slots
	int qFront;					// the front indicator
	int qRear;					// the rear indicator

public:
	Queue();					//Default constructor

	unsigned int size() const;			//show the size
	unsigned int capacity() const;			//show the capacity
	bool empty() const;				// is it empty or not?


    friend ostream &operator<< (ostream& , const Queue& );//output overload


	void push(int);					//put something into queue
	void reserve(unsigned);				//function for expanding queue capacity
	void pop() throw (underflow_error);		//pop the slot where qFront is
	void clear();					// set the object to "0"

	int front() const throw (underflow_error);	//show the slot where front is
	int back() const throw (underflow_error);	//show the slot where back is

	~Queue();					//Destructor

	Queue(const Queue&);				//COPY CONSTRUCTOR

	Queue& operator=(const Queue&);			//assignment operator overload

};


#endif


