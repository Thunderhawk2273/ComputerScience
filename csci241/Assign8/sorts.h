#ifndef SORTS_H
#define	SORTS_H

/* * * * * * * * * * * * * * * * * * * * * * * * * *
Program: sorts.h

Programmer: William Freriks

Purpose: Class definitions for the source.cpp file
		in Assignment 8
* * * * * * * * * * * * * * * * * * * * * * * * * */

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <fstream>
#include <unistd.h>
#include <stdlib.h>
#include <cstdlib>
#include <list>

using namespace std;



template <class T> void buildList(vector<T>& , const char*);
template <class T> void printList(const vector<T>&, int, int);
template <class T> bool lessThan(const T& , const T&);
template <class T> bool greaterThan(const T& , const T&);


/****************************************************************

   FUNCTION:	void buildList(vector<T>& set, const char* fileName)

   ARGUMENTS:	a vector reference, and a character pointer to a filename

   RETURNS:	nothing

   PURPOSE:	to read the information from a file and put it into a
			vector object

****************************************************************/
template <class T>
void buildList(vector<T>& set, const char* fileName)
{
	T item;
	ifstream inFile;

	inFile.open(fileName);
	if (!inFile)
	{
		cout << "Unable to open input file " << fileName << endl;
		exit(1);
	}

	inFile >> item;

	while (!inFile.eof())
	{
		set.push_back(item);
		inFile >> item;
	}

	inFile.close();
}



/****************************************************************

   FUNCTION:    void printList(const vector<T>& set, int itemWidth, int numPerLine)

   ARGUMENTS:   A const vector reference, an int for the width of the coloums,
			and the number of items per line

   RETURNS:     nothing

   PURPOSE:     to print the information in a coloumn formation

****************************************************************/
template <class T>
void printList(const vector<T>& set, int itemWidth, int numPerLine)
{
	int i = 0;
	while (i < (int)set.size())
	{
		cout << setw(itemWidth) << set[i] << ' ';
		i++;

		if (i % numPerLine == 0)
			cout << endl;
	}

	if (i % numPerLine != 0)
	cout << endl;
}



/****************************************************************

   FUNCTION:    bool lessThan(const T& item1, const T& item2)

   ARGUMENTS:   two const T items - to be readable

   RETURNS:     true or false

   PURPOSE:     to see which of the items is smaller

****************************************************************/
template <class T>
bool lessThan(const T& item1, const T& item2)
{
	return (item1 < item2);
}


/****************************************************************

   FUNCTION:    bool greaterThan(const T& item1, const T& item2)

   ARGUMENTS:   two const T items - to be readable

   RETURNS:     true or false

   PURPOSE:     to see which of the items is bigger

****************************************************************/
template <class T>
bool greaterThan(const T& item1, const T& item2)
{
	return (item1 > item2);
}

#endif
