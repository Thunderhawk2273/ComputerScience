//*****************************************************************
// FILE:      Team.cpp
// AUTHOR:    William Freriks
// LOGON ID:  Z1698749
// DUE DATE:  2/12/15
//
// PURPOSE:   Contains the functions for the Team class.
//*****************************************************************

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <cstdlib>

#include "Player.h"
#include "Team.h"

using std::cout;
using std::endl;
using std::ifstream;
using std::setw;
using std::left;
using std::right;
using std::string;
using std::ios;


//*****************************************************
//Constructor: Team()
//
//Input:nothing
//*****************************************************

Team::Team()
{
	numPlayers = 0;						//Default team, no players required
}


//*****************************************************
//Constructor: Player(const char*)
//
//Input:a file's name
//
//Purpose:To open, read, and close the file
//		- also to initially sort the players
//			with sortByName();
//*****************************************************

Team::Team(const char* fileName)
{
								// Declare an input file stream variable
        ifstream inFile;

								// Open the file stream for binary input
        inFile.open( fileName, ios::binary);
	if(!inFile)
	{
		cout << "Error: file did not open." << endl;
		exit(-1);
	}

								// Read // Read the database file into your Team object
        inFile.read((char*) this, sizeof(Team));

								// Close the file
	inFile.close();
								// Sort the Players
	sortByName();
}

//*****************************************************
//Function: void sortByName()
//
//Input:nothing
//
//Purpose: To sort the players out by their last name
//*****************************************************

void Team::sortByName()
{
	int i, j;
	Player PlayerO;

	for (i = 1; i < numPlayers; i++)			//For however many players there are
	{
		PlayerO = playerObjects[i];
								//String compare the names

		for (j = i; (j > 0) && (strcmp(playerObjects[j-1].getName(), PlayerO.getName()) > 0); j--)
		{
			playerObjects[j] = playerObjects[j-1];
		}
								// Placing the names in the proper place

	playerObjects[j] = PlayerO;
	}
}

//*****************************************************
//Function: int searchForName(const char*)
//
//Input:a pointer to the player
//
//Purpose:To search for a specific player
//*****************************************************

int Team::searchForName(const char* playerName)
{
	int low;
	int high;
	int mid;

	low = 0;
	high = numPlayers - 1;
					// assigning values
	while (low <= high)
	{
	mid = (low + high) / 2;
									//String comparing names to find the person

	if (strcmp(playerName,playerObjects[mid].getName()) == 0)
	return mid;							//Returning mid, or the player's name when we find it

	else if (strcmp(playerName, playerObjects[mid].getName()) < 0)
		high = mid - 1;						//Otherwise, keep looking
	else
		low = mid + 1;
	}
	return -1;
}


//*****************************************************
//Function: void updateStats(const char*)
//
//Input:a pointer to a file
//
//Purpose: to print and update the player's game stats
//*****************************************************

void Team::updateStats(const char *fileName)
{
	int pn, hits, bats;
	string line, first, last, full;

	ifstream inFile(fileName); 	// Open inputFileName passed as a parameter
	if (inFile.is_open())		// Check for successful open
	{
		inFile >> line;				//Date

		cout << "BOX SCORE FOR " << line
			<< endl << endl;		// Game Report Heading


		cout << left  << setw(27) << "NAME"	// print players stat categories
			<< right << setw(3)  << "H"
			<< right << setw(5)  << "AB"
			<< endl << endl;

		while(!inFile.eof())			// While it's not the end of the file
		{
			inFile >> first;		// Reading the first name because that is first
			inFile >> last;			// reading last name - 2nd
			inFile >> hits;			// reading hits - 3rd
			inFile >> bats;			// reading up to bat - 4th


			full = last + ", " + first;				// combining the last and first name to the sample output

										// Now we have to look for them
			pn = searchForName(full.c_str());

			if ( pn == -1)						// if it does not work
				cout << full << " does not exist "<< endl;

			else							// else: print the stats
			{
				cout << left << setw(27) << full
				<< right << setw(3) << hits
				<< right << setw(5) << bats
				<< endl;

				playerObjects[pn].setHits(playerObjects[pn].getHits() + hits);		//now add the stats to the
				playerObjects[pn].setAtBats(playerObjects[pn].getAtBats() + bats);	// Player's stats

			}
		}
	}
	else
	{
	cout << "Update file: Unopened";	// if the file did not open, print error
	exit(-1);				// and exit the program
	}

	cout << endl << endl;			//formating
}



//*****************************************************
//Function: void print()
//
//Input:nothing
//
//Purpose: To print the roster
//*****************************************************

void Team::print()
{
	int i;

	cout << "CHICAGO WHITE SOX ROSTER" << endl << endl;	//print the team name

	cout << left << setw(4) << "NO"				// print the stats categories
                << left << setw(27) << "NAME"
                << left << setw(5) << "POS"
                << right << setw(3) << "H"
                << right << setw(5) << "AB"
                << right << setw(7) << "AVG"
                << endl;


	for (i = 0; i < numPlayers; i++)			// print the players
	{
	playerObjects[i].print();
	cout << endl;
	}

	cout << endl << endl;
}


