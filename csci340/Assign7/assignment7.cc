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


