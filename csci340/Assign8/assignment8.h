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


// Functions
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
Function: int HT::hashing(const string& key)

Arguments: a constant string reference

Purpose: apparently to compute the key sum for the table
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
// key is in form of letter-letter-digit
// compute sum <-- ascii(pos1)+ascii(pos2)+ascii(pos3)
// compute sum%htable_size
int HT::hashing(const string& key){
   return ((int)key[0] + (int)key[1] + (int)key[2])%table_size;
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
Constructor: HT::HT(int size=11)

Arguments: integer

Purpose: to create a table for my table
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
HT::HT(int size){

	hTable = new vector<Entry>(size);

	table_size = size;

	item_count = 0;
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
Function: HT::~HT()

Arguments: none

Purpose: to erase crap from existance from my table
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
HT::~HT(){

	delete hTable;
}



/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
Function: bool HT::insert(const Entry& item)

Arguments: a constant entry reference

Purpose: to insert crap into my table
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
bool HT::insert(const Entry& item){

	if(item_count == table_size){						//if table is full
		return false;
	}

	int temp = search(item.key);
	if (temp != -1){						//if already in there
		return false;
	}

        for(int i = 0; i < table_size; i++){				//go throught the table
                if((*hTable) [i].key == "---" || (*hTable) [i].key == "+++"){ 	// if something is in there
				item_count++;					// 	add it
				(*hTable) [i] = item;
				return true;
		}
	}

	return false;
}



/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
Function: int HT::search(const std::string& itemkey)

Arguments: a const string reference

Purpose: to look for crap in my table
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
int HT::search(const std::string& itemkey){

        for(int i = 0; i < table_size; i++){
                if((*hTable) [i].key == "---")
			break;

		if((*hTable) [i].key == itemkey)
			return i;
        }

	return -1;
}



/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
Function: bool HT::remove(const std::string& item)

Arguments: string reference

Purpose: to remove crap from my table
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
bool HT::remove(const std::string& item){

	int temp = search(item);

	if(temp == -1){
		cout << "Item is not in the hash Table;";
		return false;
	}

	(*hTable) [temp].key="+++";

	item_count--;

	return true;
}



/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
Function: void HT::print()

Arguments: none

Purpose: to print my table
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
void HT::print(){

	cout << "------- Hash Table -------" << endl;

	for(int i = 0; i < table_size; i++){
		if((*hTable) [i].key != "---" && (*hTable) [i].key != "+++"){
			cout << i << "   " << setw(4) << (*hTable) [i].key
			<< "   " << (*hTable) [i].description << endl;
		}
	}
	cout << "--------------------------" << endl;
}

#endif
