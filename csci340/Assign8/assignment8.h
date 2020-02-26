#ifndef ASSIGNMENT8_H
#define ASSIGNMENT8_H
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

struct Entry {
    string key;
    string description;

    Entry() { key = "---"; }
};

class HT {
    private:
        vector<Entry>* hTable;
        int table_size;				//table size of the table
        int item_count;				//how many items are in the table
        int hashing(const string&);
    public:
        HT(int);				//Constructor
        ~HT();					//Destructor
        bool insert(const Entry&);		//Insert
        int search(const string&);		//Search
        bool remove(const string&);		//Remove
        void print();				//Print
};


#endif
