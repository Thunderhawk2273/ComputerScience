/* * * * * * * * * * * * * * * * * * * * * * * *
Program: Assignment 7

Programmer: WIlliam freriks

Due: 2/26/2015

Purpose: To verify if the sudoku puzzle has a
		valid solution or not
* * * * * * * * * * * * * * * * * * * * * * * */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <cstdlib>

#include "verifier.h"		//Must include header file

using std::cout;		//Must state what commands I am using
using std::endl;
using std::ifstream;
using std::setw;
using std::left;
using std::right;
using std::string;
using std::ios;

#define COL 9			// Column #
#define ROW 9			// Row #



/*****************************************************
Constructor: Verifier()

Input: nothing

Purpose:To set the sudoku Array to 0
*****************************************************/
Verifier::Verifier()
{
	for (int i=0; i<ROW; i++)
		 for(int y=0; y<COL; y++)
			Array[i][y] = 0;		// setting the array to 0's
}

/*****************************************************
Function: readGrid(const char*)

Input: a character constant that points to a file

Purpose:To open, read, and close the file
*****************************************************/
void Verifier::readGrid(const char* fileName)
{
        ifstream inFile;					//Create an inFile

        inFile.open( fileName, ios::in);			//open the input file
        if(!inFile)						// error message
        {
                cout << "Error: file did not open." << endl;
                exit(-1);					//exit the program
        }

	for (int x=0; x<ROW; x++)				//for every row
		for(int y=0; y<COL; y++)			// and every column
			inFile >> Array[x][y];			// input the sudoku array

        inFile.close();						// close the file
}


/*****************************************************
Constructor: printGrid()

Input:nothing

Purpose: to print the sudoku puzzle in a fancy way
*****************************************************/
void Verifier::printGrid()
{
/*        int x, y;						//original print code

        for(x = 0; x < ROW; x++){
                for(y = 0; y < COL; y++)
                        cout << setw(2) << Array[x][y];

        cout << endl;
        }*/

	int i, y, j, k;						// New Fancy Print code

	cout << endl;
        for( i = 0; i < 3; i++){
		cout << " –––––––––––––––––––––––––" << endl;	// – The top of the puzzle –
								// It is the same code as
                for( y = 0; y < 3; y++){			// the checkBoxs, but tailored
			cout << " |";				// to print the sudoku puzzle
								// in a fancy way

                        for( j = (3*y); j < ((3*y) + 3); j++){
                                for(k = (3*i); k < ((3*i) + 3); k++){
					cout << right << setw(2) << Array[j][k];
                	        }
			cout << " |";				// The box "placers"
			}

		cout << endl;

                }
        }
        cout << " –––––––––––––––––––––––––" << endl;		// The bottom of the puzzle

}


/*****************************************************
Function: bool verifySolution()

Input:n othing

Purpose:To create a counter to see if the sudoku
		puzzle will work
*****************************************************/
bool Verifier::verifySolution()
{
	int a, b, c, total;


	a = checkRows();					// Row checker

	b = checkColm();					// Column checker

	c = checkBoxs();					// Box checker

	total = a + b + c;					// All three return an integer, which
								// is added to the total value
	if (total == 27)					// If these == 27
		return true;					// the puzzle has a solution
	else
		return false;					// otherwise, it does not

}

/*****************************************************
Function: int checkRows()

Input:nothing

Purpose: To check to see if the rows are correct
*****************************************************/
int Verifier::checkRows()
{
        int i, y;						// rows, columns
        int asum, msum, tallyr;					// addition, multiplication

        tallyr = 0;						// tally counter


        for(i=0; i<ROW; i++){					// Row #

                asum =0;					// resetting the addition to 0
                msum=1;						// resetting the multiplication to 0

                for(y = 0; y < COL; y++){			// Column 1-9
                        asum = asum + Array[i][y];		// add numbers together
                        msum = msum * Array[i][y];		// multiply # together
                }

        	if (asum == 45 && msum == 362880)	// If the row adds/multiplies correctly
                	tallyr += 1;			// add a tally to the counter

        	if(asum!=45 || msum!=362880)		// If not
                	tallyr -= 1;			// minus a tally
        }

        return tallyr;					// return the tally
}


/*****************************************************
Function: int checkColm()

Input:nothing

Purpose:To check to see if the columns are correct
*****************************************************/
int Verifier::checkColm()
{
	int i, y;
	int asum, msum, tallyc;
								// same as the row checker
	tallyc = 0;


        for(i=0; i<COL; i++){					// the columns

                asum =0;
                msum=1;

                for(y = 0; y < ROW; y++){			// the rows
                        asum = asum + Array[y][i];		// adding the numbers
                        msum = msum * Array[y][i];		// multiplying them
                }



        if (asum == 45 && msum == 362880)			// if it checks out
                tallyc += 1;					// add 1 to the counter

         if(asum!=45 || msum!=362880)				// if it doesn't
                tallyc -= 1;					// subtract 1 from the counter
        }

	return tallyc;						// return the counter
}

/*****************************************************
Function: int checkBoxs()

Input: nothing

Purpose: To check to see if the boxes are correct
*****************************************************/
int Verifier::checkBoxs()
{
	int i, y, j, k;					// multiple rows and columns
	int asum, msum, tallyb;				// addition, multiplication, counter

	i = y = j = k = 0;				// initialize almost everything to 0
	tallyb = 0;

			// Basically, we are splitting the boxes into three rows and columns
	for( i = 0; i < 3; i++)
	{
                for( y = 0; y < 3; y++)
                {

	                asum =0;		//reset the addition and multiplication
	                msum=1;			// to zero and 1 respectively

		        for( j = (3*y); j < ((3*y) + 3); j++){		//move to another line

	        	        for(k = (3*y); k < ((3*y) + 3); k++){	//read through one line
	        	                asum = asum + Array[j][k];	// add #'s up
	       		                msum = msum * Array[j][k];	// multiply #'s up
	        	        }
		        }


			 if (asum == 45  && msum == 362880)		// if they check out
		                tallyb += 1;				// add 1 to the counter

		         if(asum!=45 || msum!=362880)			// if they don't
		                tallyb -= 1;				// - 1 from the counter



		}
	}

	return tallyb;					// return the counter
}
