/****************************************************
PROGRAMMER: WILLIAM FRERIKS

PURPOSE: To find all non-prime integers and destroy them

****************************************************/

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <set>
#include <algorithm>

using namespace std;

const int NO_ITEMS = 10;
const int ITEM_W = 5;

/****************************************************
Function:void sieve( set<int>& s, int n)

Arguments: an integer set, and an integer

Purpose: to search and destroy all non-prime numbers in a set
*****************************************************/
void sieve( set<int>& s, int n) {

}


/****************************************************
Function:void print_primes( const set<int>& s)

Arguments: a const integer set reference

Purpose: to print all of those prime numbers we just found
*****************************************************/
void print_primes( const set<int>& s) {

}





//MAIN FUNCTION
int main() {
    set<int> s;
    sieve(s, 1000);
    print_primes(s);
    return 0;
}
