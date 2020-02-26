/****************************************************
PROGRAMMER: William Freriks

PURPOSE: "to count the [frequencies] of clean words."

****************************************************/

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cstdlib>
#include <algorithm>
#include <cctype>
#include <map>

using namespace std;

const int NO_ITEMS = 3;
const int ITEM_W = 16;


/***************************************************
Function: void print_words( const map<string, int>& )

Arguments: a map<string,int> reference constant

Purpose: to print words in columns
***************************************************/
void print_words( const map<string, int>& chart) {

}


/***************************************************
Function: void lowerCase( char& character )

Arguments: A character reference

Purpose: to lowercase any char within the for_each() function
***************************************************/

void lowerCase( char& character ) {
}


/***************************************************
Function: void clean_entry( const string&, string& )

Arguments: a constant string ref, and a string ref

Purpose: is to read input and substring the words
***************************************************/
void clean_entry( const string& read, string& clean) {
}


/***************************************************
Function: void get_words( map<string, int>&, ifstream& )

Arguments: a map<sting,int> reference, and an infile-stream reference

Purpose: input the lines of "words"
***************************************************/
void get_words( map<string, int>& words, ifstream& inFile) {
}




//MAIN FUNCTION

int main(int argc, char** argv) {
    if ( argc < 2 ) {
        cerr << "command line argument: input-file-name" << endl;
        return 1;
    }

    ifstream infile(argv[1], ios::in);

    map<string, int> m;

    get_words( m, infile );

    infile.close();

    print_words( m );

    return 0;
}
