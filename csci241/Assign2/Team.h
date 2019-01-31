//*****************************************************************
// FILE:      Team.h
// AUTHOR:    William Freriks
// LOGON ID:  Z1698749
// DUE DATE:  2/12/15
//
// PURPOSE:   Contains the declaration for the Team class.
//*****************************************************************

#ifndef TEAM_H
#define TEAM_H

class Team
{
public:
	Team();					// Default Team
	Team(const char*);			// a "real" team with a file

	int searchForName(const char*);		//find a specific player

	void sortByName();			//sort the names
	void updateStats(const char*);		//update the Player's stats
	void print();				// print the team

private:					//Data members
	Player playerObjects[40];		//how many objects there are
	int numPlayers;				//how many players there are

};

#endif

