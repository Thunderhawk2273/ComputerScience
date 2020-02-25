/* * * * * * * * * * * * * * * * * * * * * * * *
Programmer: WIlliam freriks

Purpose: To verify if the sudoku puzzle has a
		valid solution or not
* * * * * * * * * * * * * * * * * * * * * * * */

#ifndef VERIFIER_H
#define VERIFIER_H


#include <iostream>


class Verifier
{
public:
	Verifier();			// Default constructor

	void readGrid(const char*);	// read the file
	void printGrid();		// print the grid

	bool verifySolution();		// verify if it is solvable

	int checkRows();		// check the rows to see if they are correct
	int checkColm();		// check the columns to see if they are correct
	int checkBoxs();		// check the boxes to see if they are correct


private:

	int Array[9][9];		// the array that holds the sudoku puzzle

};


#endif
