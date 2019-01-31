/****************************************************
PROGRAMMER: WILLIAM FRERIKS

DUE DATE: SUNDAY, SEPTEMBER 5, 2015

PROGRAM: ASSIGNMENT 1

PURPOSE: TO INPUT 100 INTEGERS IN A VECTOR, SORT THEM
		AND PRINT THEM IN ORDER
****************************************************/


#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

#define HIGH 10000
#define LOW 1
#define NO_ITEMS 12
#define ITEM_W 5


/****************************************************

Function: void genRndNums( vector<int>& v, int vec_size, int seed )

Arguements: a vector reference, an integer to the vectors' size,
		and an integer for a seed value.

Purpose: to generate random numbers and push them into
		the vector.

****************************************************/


void genRndNums( vector<int>& v, int vec_size, int seed ) {

	int number;

	srand(seed);

	for( int i = 0; i < vec_size; i++){
		number = rand() % (HIGH - LOW + 1) + LOW;
		v.push_back(number);				//generating random numbers
	}							//and pushing them into the vector
}


/****************************************************

Function: void printVec( const vector<int>& v, int vec_size )

Arguements: a vector constant reference, and an integer
		to the vectors' size

Purpose: to print out the vector in neat lines

****************************************************/

void printVec( const vector<int>& v, int vec_size ){

	int count = 0;						//seperate counter

	cout << endl;

	for(int i = 0; i < vec_size; i++){
		cout << setw(ITEM_W) << v[i];			//printing the vector
		count++;

		if(count == 12){				//printing every 12 lines
			cout << endl;
			count = 0;
		}
	}

	cout << endl << endl;					//formating
}


//MAIN FUNCTION

int main() {

    vector<int> v;
    genRndNums( v, 100, 9 );
    sort(v.begin(), v.end());
    printVec(v, 100);

    return 0;
}
