/*********************************************************************
   PROGRAM:    Assignment 3

   FUNCTION:   This program tests the functionality of the Verifier
               class.
*********************************************************************/

#include <iostream>
#include <string>
#include "verifier.h"

using std::cout;
using std::endl;
using std::string;
using std::to_string;

#define NUM_FILES 5

int main()
   {
   Verifier v;
   string fileName;

   cout << "Sudoku Verifier\n";

//	int i = 0;
   for (int i = 1; i <= NUM_FILES; i++)
      {
	cout << endl;

      // Construct file pathname
	fileName = "solution" + to_string(i) + ".txt";

      // Read the solution file as input
	v.readGrid(fileName.c_str());

      // Print the Sudoku grid
	v.printGrid();

      // Verify whether or not the solution is correct
	if (v.verifySolution() == true)
	cout << endl << fileName << endl << "\nThis is a valid Sudoku solution\n";
	else
	cout << endl << fileName << endl << "\nThis is not a valid Sudoku solution\n";
     }

   return 0;
   }
