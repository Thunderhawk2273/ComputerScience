/****************************************************
PROGRAMMER: WILLIAM FRERIKS

DUE DATE: FRIDAY, SEPTEMBER 18, 2015

PROGRAM: 2

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

	set<int>::iterator it;
	set<int>::iterator del_it;


	for( int i = 2; i <= n; i++)			//fill up the set with n integers
		s.insert(i);


	for( it = s.begin(); it!=s.end(); ++it ){
		del_it = it;
							//Going throught the set and deleting
		for( del_it++; del_it!=s.end(); ++del_it ){	// integers
			if(*del_it % *it == 0)
			s.erase(del_it);
		}
	}

}


/****************************************************
Function:void print_primes( const set<int>& s)

Arguments: a const integer set reference

Purpose: to print all of those prime numbers we just found
*****************************************************/
void print_primes( const set<int>& s) {

	set<int>::iterator it;

	int count = 0;

	cout << endl;				//formating

	for(it=s.begin(); it!=s.end(); ++it ){
		cout << setw(ITEM_W) << *it;
		count++;
						//using an iterator to go through the set
		if (count == NO_ITEMS){		// and to print the prime numbers
			cout << endl;
			count = 0;
		}
	}
	cout << endl << endl;			//formating
}







//MAIN FUNCTION
int main() {
    set<int> s;
    sieve(s, 1000);
    print_primes(s);
    return 0;
}
