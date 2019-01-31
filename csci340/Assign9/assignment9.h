#ifndef ASSIGNMENT9_H
#define ASSIGNMENT9_H
#include <vector>
#include <list>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;


class graph {
    private:
        int size;			//Graph size
        vector< list<int> > adj_list;	//vector that holds the adjacent(neighboring) vertices in a list
        vector< char > labels;		//vector that holds Columns
        void depth_first( int ) const;	//
    public:
        graph( const char* filename );
        ~graph();
        int get_size() const;
        void traverse( ) const;
        void print ( ) const;
};

	bool *visited;
	string finish;
//Private Functions

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
Function: void graph::depth_first( int item ) const

Arguments: an integer pertaining to the vertice we are at

Purpose: we input the vertice, and then go through the graph
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
void graph::depth_first( int item ) const{

	visited[item] = true;

	cout << labels[item] << " ";


	list<int>::const_iterator it;

	for(it = adj_list[item].begin(); it != adj_list[item].end(); it++){
		int a = *it;
		if(!visited[a]){
			finish = finish + "(" + labels[item] + ", " + labels[a] + ") ";
			depth_first(a);
		}
	}
}


//Public Functions

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
Function: graph::graph( const char* fileName )

Arguments: a character pointer constant

Purpose: to input data from the input file.
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
graph::graph( const char* fileName ){

	ifstream inFile;

	inFile.open(fileName, ios::in);

	if (!inFile){
		cout << "Error: file did not open." << endl;
		exit(-1);
	}

	inFile >> size;					//First input is a number

	labels.resize(size);				//resize the vector to the graph's size

	for (int i = 0; i < size; i++)			//Second line is all of the Column labels
		inFile >> labels[i];			// so put them in the labels vector

	char temp;
	int integer;


	for (int r = 0; r < size; r++){
		inFile >> temp;

		list <int> atemplist;

		for (int c = 0; c < size; c++){
			inFile >> integer;
			if (integer == 1)
				atemplist.push_back(c);
		}
	adj_list.push_back(atemplist);
	}


	inFile.close();
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
Function: graph::~graph()

Arguments: none

Purpose: DESTROYER – we're just clearing the lists to make sure
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
graph::~graph(){
	adj_list.clear();			//They're lists. Clear them.
	labels.clear();
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
Function: int graph::get_size() const

Arguments: none

Purpose: return the size, which is private
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
int graph::get_size() const{
	return size;
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
Function: void graph::traverse() const

Arguments: none

Purpose: to traverse the graph via depth-first
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
void graph::traverse() const{

	cout << "----------- Traversal of Graph ------------" << endl;

	finish = "";
        visited = new bool[size];

        for (int i = 0; i < size; i++)
                visited[i] = false;		//Set everything as unvisited(false)

        for (int j = 0; j < size; j++)
                if(!visited[j])			//If we didn't visit it
                        depth_first(j);		// call depth-first

	cout << endl;
	cout << finish << endl;
        delete [] visited;
}


/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
Function: void graph::print () const

Arguments: none

Purpose: to print out the graph so that we see the connections
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
void graph::print () const{

	cout << "The number of vertices in the graph: " << size
		<< endl << endl;

	cout << "------ Graph ------" << endl;

	for (int i = 0; i < get_size(); i++){
		cout << labels[i] << ": ";		//Get the Alphabetical vertices
		list<int>::const_iterator it;		//It's a list, use an iterator
		for(it = adj_list[i].begin(); it != adj_list[i].end(); it++)
			cout << labels[*it] << ", ";	//We stored the vertices in the adj_list vector

		cout << endl;
	}

	cout << "\n";


}

#endif
