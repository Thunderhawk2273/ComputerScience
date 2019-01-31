
//*****************************************************************
// FILE:      Queue.cpp
// AUTHOR:    William Freriks
// LOGON ID:  Z1698749
// DUE DATE:  3/20/15
//
// PURPOSE:   Contains the declarations for the Queue class
//*****************************************************************
#include <iostream>
#include <iomanip>
#include <fstream>

#include "Queue.h"

using namespace std;


/****************************************************************

   CONSTRUCTOR: Queue()

   ARGUMENTS:  none

   RETURNS:    notheing

   PURPOSE:    Default constructor

****************************************************************/
Queue::Queue(){

	qCapacity = 1;

	qArray = new int[qCapacity];

	qSize = 0;

	qFront = 0;

	qRear = -1;
}



/****************************************************************

   FUNCTION:   unsigned int Queue::size() const

   ARGUMENTS:  none

   RETURNS:    returns the size of the queue

   PURPOSE:    to get the size of the queue

****************************************************************/
unsigned int Queue::size() const{

	return this->qSize;
}



/****************************************************************

   FUNCTION:   unsigned int Queue::capacity() const

   ARGUMENTS:  none

   RETURNS:    returns the size of the queue

   PURPOSE:    to get the capacity

****************************************************************/
unsigned int Queue::capacity() const{

	return this->qCapacity;
}



/****************************************************************

   FUNCTION:   bool Queue::empty() const

   ARGUMENTS:  none

   RETURNS:    1 if true, 0  if false

   PURPOSE:    to see if the array is empty or not

****************************************************************/
bool Queue::empty() const{

	if(size()==0)
		return 1;
	else
		return 0;
}



/****************************************************************

   FUNCTION:   ostream & operator<< (ostream&, const queue&)

   ARGUMENTS:  output on the left; object ont he right

   RETURNS:    output

   PURPOSE:    to print the dynamic array to standard output

****************************************************************/

ostream & operator<< (ostream& output, const Queue& obj){

int current, i;

for (current = obj.qFront, i = 0; i < (int) obj.qSize; ++i)
   {
   // Print queue element at subscript i
   output << obj.qArray[current] << " ";

   // Increment i, wrapping around to front of queue array if necessary
   current = (current + 1) % obj.qCapacity;
   }
return output;
}



/****************************************************************

   FUNCTION:   void Queue::push(int)

   ARGUMENTS:  1 int; what is going to be put into the array

   RETURNS:    nothing

   PURPOSE:    to put something into the rear of the array

****************************************************************/
void Queue::push(int item){

	if (qSize == qCapacity)
		reserve(qCapacity * 2);				//adding more memory if full


	qRear = (qRear + 1) % qCapacity;			//wrapping around

	qArray[qRear] = item;					//adding the new item

	qSize++;						//increasing the size
}




/****************************************************************

   FUNCTION:   void Queue::reserve(unsigned)

   ARGUMENTS:  unsigned int, the new capacity for the array

   RETURNS:    nothing

   PURPOSE:    to increase the size of the array

****************************************************************/
void Queue::reserve(unsigned newCap){
	int* copyArray = new int[newCap];			//new memory

	int current = qFront;					//temporary int for qFront

	for (unsigned i = 0; i < qSize; i++){			//put array into a new one
		copyArray[i] = qArray[current];
		current = (current + 1) % qCapacity;
	}

	qCapacity = newCap;					//copy capacity

	delete[] qArray;					//delete old memory

	qArray = copyArray;

	qFront = 0;						//set qFront to beginning of array

	qRear = qSize - 1;					//set qRear to the end of the data
}



/****************************************************************

   FUNCTION:   void Queue::pop() throw (underflow_error)

   ARGUMENTS:  none (error in case array is empty)

   RETURNS:    nothing

   PURPOSE:    to take something out of the front of the array

****************************************************************/
void Queue::pop() throw (underflow_error){

	if (empty() == 1)
                throw underflow_error("queue underflow on pop()");


	qFront = (qFront + 1) % qCapacity;

	qSize--;
}



/****************************************************************

   FUNCTION:   Queue& Queue::operator=(const Queue&)

   ARGUMENTS:  a const Queue reference

   RETURNS:    a pointer to the left object

   PURPOSE:    to make the left object the same as the right

****************************************************************/
Queue& Queue::operator=(const Queue& obi){
//1 Check for self-assignment
	//If self-assignment true, jump to step 5
if (this == &obi)
	return *this;


//2 Free up memory for left Object
delete[] qArray;

//3 Get new memory for the left Object

//4 Copy all the data from right to left


	this->qCapacity = obi.qCapacity;			//copy capacity
	this->qSize = obi.qSize;				//copy size
	this->qArray = new int[qCapacity];			//create new memory

	for (unsigned i=0; i<qCapacity; i++)
		this->qArray[i] = obi.qArray[i];		//copy array

	this->qFront = obi.qFront;				//copy front
	this->qRear = obi.qRear;				// and back

//5 Return *this

return *this;
}



/****************************************************************

   FUNCTION:   int Queue::front() const throw (underflow_error)

   ARGUMENTS:  none

   RETURNS:    the integer in the front's slot

   PURPOSE:    to return the integer in the front's slot

****************************************************************/
int Queue::front() const throw (underflow_error){

        if (empty() == 1)					//if it's empty
		throw underflow_error("queue underflow on front()");	//print error

	return this->qArray[qFront];
}



/****************************************************************

   FUNCTION:   int Queue::back() const throw(underflow_error)

   ARGUMENTS:  none

   RETURNS:    the integer in the back's slot spot

   PURPOSE:    returns the integer in the rear's slot spot

****************************************************************/
int Queue::back() const throw (underflow_error){

	if (empty() == 1)
		throw underflow_error("queue underflow on back()");

	return this->qArray[qRear];
}



/****************************************************************

   FUNCTION:   void Queue::clear()

   ARGUMENTS:  none

   RETURNS:    nothing

   PURPOSE:    to set the memory as though it were a new array

****************************************************************/
void Queue::clear(){

	qSize = 0;
	qFront = 0;
	qRear = -1;
}



/****************************************************************

   FUNCTION:   Queue::~Queue()

   ARGUMENTS:  none

   RETURNS:    nothing

   PURPOSE:    Destructor

****************************************************************/
Queue::~Queue(){

	delete[] qArray;
}



/****************************************************************

   FUNCTION:   Queue::Queue(const Queue&)

   ARGUMENTS:  a const object reference

   RETURNS:    nothing

   PURPOSE:    Copy Constructor - similar to assignment operator

****************************************************************/
Queue::Queue(const Queue& obi){

	qCapacity = obi.qCapacity;

	qSize = obi.qSize;

	qArray = new int[qCapacity];

	for( unsigned i = 0; i < qCapacity; i++)
		qArray[i] = obi.qArray[i];


	qFront = obi.qFront;

	qRear = obi.qRear;

}



