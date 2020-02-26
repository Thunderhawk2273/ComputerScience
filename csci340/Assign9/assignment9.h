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

#endif
