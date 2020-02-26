/****************************************************
PROGRAMMER: WILLIAM FRERIKS

PURPOSE: TO CREATE TWO INTEGER VECTORS AND COMPARE THEM

****************************************************/


#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

const int TOBE_SEARCHED = 5000;
const int HIGH = 10000;
const int LOW = 1;



/****************************************************

Function: void genRndNums( vector<int>& v, int vec_size, int seed )

Arguements: a vector reference, an integer to the vectors' size,
                and an integer for a seed value.

Purpose: to generate random numbers and push them into
                the vector.

****************************************************/
void genRndNums( vector<int>& v, int vec_size, int seed ) {

}


/****************************************************

Function: bool linearSearch( const vector<int>& v, int x)

Arguements: a vector reference, and an integer to look for

Purpose: to find an integer via linear search

****************************************************/
bool linearSearch( const vector<int>& v, int x) {

}


/****************************************************

Function: bool binarySearch( const vector<int>& v, int x)

Arguements: a vector const reference, and an integer

Purpose: to search vectors and find matcing integers

****************************************************/
bool binarySearch( const vector<int>& v, int x) {
}


/****************************************************

Function: int search( const vector<int>& container, const vector<int>& searchNums,
            bool (*p)( const vector<int>&, int) )

Arguements: a vector constant reference(1), a vector const reference(2),
		a boolean pointer (basically a function call to binarySearch or linearSearch)

Purpose: to search two vectors, and find matching integers

****************************************************/
int search( const vector<int>& container, const vector<int>& searchNums,
            bool (*p)( const vector<int>&, int) ) {

}


/****************************************************

Function: void sortVec (vector<int& v)

Arguements: a vector reference

Purpose: to sort a vector

****************************************************/
void sortVec (vector<int>& v) {
}


/****************************************************

Function: void printStat (int totalSucCnt, int vec_size)

Arguements: an integer for the number of successful comparisons,
		and an integer for the size of a vector.

Purpose: to cout the percent of successful comparisons
****************************************************/
void printStat (int totalSucCnt, int vec_size) {
}





//MAIN FUNCTION

int main() {
    vector<int> container, tobeSearched;
    genRndNums(container, 10000, 9);
    genRndNums(tobeSearched, TOBE_SEARCHED, 3);

    cout << "\nConducting linear search ..." << endl;
    int linear_search_count = search( container, tobeSearched, linearSearch );
    printStat ( linear_search_count, TOBE_SEARCHED );

    cout << "\nConducting binary search on unsorted container ..." << endl;
    int binary_search_count = search( container, tobeSearched, binarySearch );
    printStat ( binary_search_count, TOBE_SEARCHED );

    sortVec( container );

    cout << "\nConducting binary search on sorted container ..." << endl;
    binary_search_count = search( container, tobeSearched, binarySearch );
    printStat ( binary_search_count, TOBE_SEARCHED );

    return 0;
}
