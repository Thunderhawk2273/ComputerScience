#ifndef QUICKSORT_H
#define	QUICKSORT_H

/* * * * * * * * * * * * * * * * * * * * * * * * * *
Program: quicksort.h

Programmer: William Freriks

Purpose: Class definitions for the source.cpp file
		in Application 8
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
#include <algorithm>

using namespace std;


template <class T> void quickSort(vector<T>& , bool (*compare)(const T&, const T&));
template <class T> void quickSort(vector<T>& , int, int, bool (*compare)(const T&, const T&));
template <class T> int partition(vector<T>& , int, int, bool (*compare)(const T&, const T&));


/****************************************************************

   FUNCTION:	void quickSort(vector<T>& set, bool (*compare)(const T&, const T&))

   ARGUMENTS:	a vector reference, and a boolean pointer to the GreaterThan or LessThan

   RETURNS:	nothing

   PURPOSE:	to call the quicksort

****************************************************************/
template <class T> void quickSort(vector<T>& set, bool (*compare)(const T&, const T&))
{
	quickSort(set, 0, set.size()-1, compare);
}


/****************************************************************

   FUNCTION:	void quickSort(vector<T>& set, int start, int end, bool (*compare)(const T&, const T&))

   ARGUMENTS:	a vector reference, int for the start of the information, int for the end of the information,
			and a boolean pointer to the GreaterThan or LessThan

   RETURNS:	nothing

   PURPOSE:	to create a partion and sort the information

****************************************************************/
template <class T> void quickSort(vector<T>& set, int start, int end, bool (*compare)(const T&, const T&))
{

int pivotPoint;
	if (start < end)
	{
		pivotPoint = partition(set, start, end, compare);     // Get the pivot point
		quickSort(set, start, pivotPoint - 1, compare);       // Sort first sublist
		quickSort(set, pivotPoint + 1, end, compare);         // Sort second sublist
	}
}


/****************************************************************

   FUNCTION:	int partition(vector<T>& set, int start, int end, bool (*compare)(const T&, const T&))

   ARGUMENTS:	a vector reference, int for the start of the information, an int for the end of the information,
			and a boolean pointer for the GreatherThan or LessThan

   RETURNS:	an integer, also known as the pivot point

   PURPOSE:	to find and return the pivot point

****************************************************************/
template <class T> int partition(vector<T>& set, int start, int end, bool (*compare)(const T&, const T&))
{
   int pivotIndex, mid;
   T pivotValue;

   mid = (start + end) / 2;
//   Swap elements start and mid of the vector
	swap(set[start], set[mid]);

   pivotIndex = start;
   pivotValue = set[start];

   for (int scan = start + 1; scan <= end; scan++)
      {
      if (compare(set[scan], pivotValue))
         {
         pivotIndex++;

//	Swap elements pivotIndex and scan of the vector
         swap(set[pivotIndex], set[scan]);
	}
      }

//   Swap elements start and pivotIndex of the vector
	swap(set[start], set[pivotIndex]);

   return pivotIndex;
}
#endif
