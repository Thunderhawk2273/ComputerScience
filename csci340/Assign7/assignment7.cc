/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
Program: Assignment 7

Programmer: William Freriks

Due Date: 11/06/15

Reason: Heaps

* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;


void build_heap ( vector < int >& , int, bool (*compar)(int, int) );
void heapify( vector < int >& , int, int, bool (*compar)(int, int) );

bool less_than ( int, int );
bool greater_than ( int, int );

void heap_sort ( vector < int >& , int, bool (*compar)(int, int) );
int extract_heap ( vector < int >& , int& , bool (*compar)(int, int) );
void print_vector ( vector < int >& , int, int);



int main(int argc, char** argv) {
    // ------- creating input vector --------------
    vector<int> v;
    v.push_back(-1000000);    // first element is fake
    int heap_size = 24;
    for (int i=1; i<=heap_size; i++)
        v.push_back( i );
    random_shuffle( v.begin()+1, v.begin()+heap_size+1 );
    cout << "\nCurrent input numbers: " << endl;
    print_vector( v, 1, heap_size );

    // ------- testing min heap ------------------
    cout << "\nBuilding a min heap..." << endl;
    build_heap(v, heap_size, less_than);
    cout << "Min heap: " << endl;
    print_vector( v, 1, heap_size );
    heap_sort( v, heap_size, less_than);
    cout << "Heap sort result (in ascending order): " << endl;
    print_vector( v, 1, heap_size );

    // ------- testing max heap ------------------
    cout << "\nBuilding a max heap..." << endl;
    build_heap(v, heap_size, greater_than);
    cout << "Max heap: " << endl;
    print_vector( v, 1, heap_size );
    heap_sort( v, heap_size, greater_than);
    cout << "Heap sort result (in descending order): " << endl;
    print_vector( v, 1, heap_size );

    return 0;
}



// Functions



/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
Function: void build_heap ( vector < int >& v, int heap_size, bool (*compar)(int, int) )

Arguments: vector reference, integer, and function pointer

Purpose: to build the heap
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
void build_heap ( vector < int >& v, int heap_size, bool (*compar)(int, int) ){
	for(int i = heap_size/2; i >= 1; i--)
		heapify(v, heap_size, i, compar);
}



/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
Function: void heapify( vector < int >& v, int heap_size, int r, bool (*compar)(int, int) )

Arguments: a vector reference, integer for the heap size, int r, and function pointer

Purpose: to get shit done.
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
void heapify( vector < int >& v, int heap_size, int r, bool (*compar)(int, int) ){
	int L = (2*r);
	int R = (2*r)+1;

	int largest;

	if (L <= heap_size && compar(v[L], v[r]))
		largest = L;
	else
		largest = r;

	if (R <= heap_size && compar(v[R], v[largest]))
		largest = R;

	if (largest != r){
		int temp = v[r];
		v[r] = v[largest];
		v[largest] = temp;

		heapify(v, heap_size, largest, compar);
	}
}



/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
Function: bool less_than ( int e1, int e2 )

Arguments: two integers

Purpose: Is e1 less than e2?
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
bool less_than ( int e1, int e2 ){
	return (e1 < e2);
}
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
Function: bool greater_than ( int e1, int e2 )

Arguments: two integers

Purpose: Is e1 greater than e2?
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
bool greater_than ( int e1, int e2 ){
	return (e1 > e2);
}



/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
Function: void heap_sort ( vector < int >& v, int heap_size, bool (*compar)(int, int) )

Arguments: vector reference, integer, function pointer

Purpose: to sort that sh!t. Srsly, it's a mess.
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
void heap_sort ( vector < int >& v, int heap_size, bool (*compar)(int, int) ){

	for (int i = heap_size; i >= 2; i--)
		v[i] = extract_heap(v, heap_size, compar);

	reverse(v.begin()+1, v.end());
}



/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
Function: int extract_heap ( vector < int >& v, int& heap_size, bool (*compar)(int, int) )

Arguments: vector reference, integer reference, function pointer

Purpose: Cause we must extract the heap from the enemy's clutches
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
int extract_heap ( vector < int >& v, int& heap_size, bool (*compar)(int, int) ){

	int temp = v[1];

	v[1] = v[heap_size];

	heap_size--;

	heapify(v, heap_size, 1, compar);

	return temp;
}




/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
Function: void print_vector ( vector < int >& v, int pos, int size )

Arguments: vector reference, integer for position, and an integer for heap size

Purpose: to print our victory over the mounds of slain enemy
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
void print_vector ( vector < int >& v, int pos, int size ){

	int count = 0;

	for(int i = pos; i <= size; i++){
		cout << setw(4) << v[i];
		count++;

		if (count%10 == 0)
			cout << endl;
	}
	cout << endl;
}
