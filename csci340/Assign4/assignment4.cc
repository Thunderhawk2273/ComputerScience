/****************************************************
PROGRAMMER: William Freriks

DUE DATE: October 1, 2015

PROGRAM: Assignment 4

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

	int counter = 0, Occurances = 0;

	map<string, int>::const_iterator it;
	it = chart.begin();
							//need an iterator to get through the map
	while(it != chart.end()){
		cout << setw(ITEM_W) << left
			<< it->first << " = "
			<< setw(5) << it->second;
							//print in neat oraganized lines
		Occurances += it->second;		//how many lines have we gone through?

		counter++;
		it++;
							//make a new line when we hit 3 columns
		if(counter%NO_ITEMS == 0)
			cout << endl;
	}
								//stats
	cout << endl << "Occurances: " << Occurances << endl
		<< "Map Size: " << chart.size() << endl;
}


/***************************************************
Function: void lowerCase( char& character )

Arguments: A character reference

Purpose: to lowercase any char within the for_each() function
***************************************************/

void lowerCase( char& character ) {
	character = tolower(character);
}


/***************************************************
Function: void clean_entry( const string&, string& )

Arguments: a constant string ref, and a string ref

Purpose: is to read input and substring the words
***************************************************/
void clean_entry( const string& read, string& clean) {
							//use 2 pointers
	unsigned int home, range;
							//look for the first letter or number
	for(home = 0; home < read.length(); home++){
		if(isalnum(read[home]))
			break;
	}
							//look for the "last" letter or number
	for(range = home; range < read.length(); range++){
		if(!isalnum(read[range]))
			break;
	}
							//substring it out
	clean = read.substr(home, (range-home));	//put it into string& clean

	for_each(clean.begin(), clean.end(), lowerCase);//lowercase everything
}


/***************************************************
Function: void get_words( map<string, int>&, ifstream& )

Arguments: a map<sting,int> reference, and an infile-stream reference

Purpose: input the lines of "words"
***************************************************/
void get_words( map<string, int>& words, ifstream& inFile) {

	string preClean, postClean;
							//need to put input into something
	while(inFile >> preClean){			//while reading something in

		clean_entry(preClean, postClean);
							//if  postClean is bigger than 0
		if(postClean.length() != 0)		//put it into map words
			words[postClean]++;
	}
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
