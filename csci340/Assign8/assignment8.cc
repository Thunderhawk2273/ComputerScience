/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
Program: Assignment 8

Programmer: William Freriks

Due Date: 11/13/15

Reason: Hashing

* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>

#include "assignment8.h"

using namespace std;



/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
Function: Entry* get_entry (const string& line)

Arguments: a constant string reference

Purpose: to substring the bloody input and return it
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
Entry* get_entry (const string& line){

	Entry* e2 = new Entry();

	e2->key = line.substr(2,3);
	e2->description = line.substr(6);

	return e2;
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
Function: string get_key(const string& line)

Arguments: a constant string reference

Purpose: to substring the key
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
string get_key(const string& line){
	return line.substr(2,3);
}


// key is in form of letter-letter-digit
// compute sum <-- ascii(pos1)+ascii(pos2)+ascii(pos3)
// compute sum%htable_size
// int HT::hashing(const string& key) {
//   return ((int)key[0] + (int)key[1] + (int)key[2])%table_size;
//}

int main(int argc, char** argv ) {
    if ( argc < 2 ) {
        cerr << "argument: file-name\n";
        return 1;
    }

    HT ht(11);
    ifstream infile(argv[1], ios::in);
    string line;
    infile >> line;
    while ( !infile.eof() ) {
        if ( line[0] == 'A' ) {
            Entry* e = get_entry( line );
            ht.insert( *e );
            delete e;
        }
        else {
            string key = get_key(line);
            if ( line[0] == 'D' ) {
                cout << "Removing " << key << "...\n";
                bool removed = ht.remove( key );
                if ( removed )
                    cout << key << " is removed successfully...\n\n";
                else
                    cout << key << " does not exist, no key is removed...\n\n";
            }
            else if ( line[0] == 'S' ) {
                int found = ht.search( key );
                if ( found < 0 )
                    cout << key << " does not exit in the hash table ..." << endl << endl;
                else
                   cout << key << " is found at table position " << found << endl << endl;
            }
            else if ( line[0] == 'P' ) {
                cout << "\nDisplaying the table: " << endl;
                ht.print();
            }
            else
                cerr << "wrong input: " << line << endl;
        }
        infile >> line;

    }

    infile.close();
    return 0;
}
