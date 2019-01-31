//*****************************************************************
// FILE:      Player.cpp
// AUTHOR:    William Freriks
// LOGON ID:  Z1698749
// DUE DATE:  2/12/15
//
// PURPOSE:   Contains the declaration for the Player class.
//*****************************************************************

#include<iostream>
#include<iomanip>
#include<cstring>
#include<stdio.h>
#include "Player.h"

using std::cout;		//All of the std that the program is using
using std::cin;
using std::setprecision;
using std::setw;
using std::fixed;
using std::left;
using std::right;
using std::endl;

//*****************************************************
//Constructor: Player()
//
//Input:nothing
//
//Purpose:default player; set everything to null
//*****************************************************
Player::Player()
{
    //Number
    player_number = 0;
    //Name
    strcpy(playerName,"");
    //Position
    strcpy(playerPosition,"");
    //Hits
    NumOfHits = 0;
    //At Bats
    numTimesAtBat = 0;
}

//*****************************************************
//Constructor: Player (int, char*, char*, int, int)
//
//Input: 3 int, 2 char*
//
//Purpose: to create a player object
//*****************************************************
Player::Player(int newNum, char newName[], char newPost[], int newNumOfHits, int newNumAtBats)
{
    //Number
    player_number = newNum;
    //Name
    strcpy(playerName,newName);
    //Position							These are actual players
    strcpy(playerPosition,newPost);
    //Hits								- set them up witht heir stats
    NumOfHits = newNumOfHits;
    //At Bats
    numTimesAtBat = newNumAtBats;

}

//*****************************************************
//Function:void setHits(int)
//
//Input:int
//
//Purpose: To make sure the number of hits is no lower
//		than 0
//*****************************************************
void Player::setHits(int inputHit)
{
    	if (inputHit >= 0)
		NumOfHits = inputHit;

	else
		NumOfHits = 0;
}

//*****************************************************
//Function: void setAtBats(int)
//
//Input:int
//
//Purpose: To make sure the number of hits is no lower
//		than 0
//*****************************************************
void Player::setAtBats(int inputAtBats)
{
	if (inputAtBats >= 0)
		numTimesAtBat = inputAtBats;

	else
		numTimesAtBat = 0;
}

//*****************************************************
//Function: double battingAverage()
//
//Input:none
//
//Purpose: To calculate the batting average between
//		the player's hits and at bats
//*****************************************************
double Player::battingAverage()
{
    float i, j, atBats;

    i = getAtBats();

    if (i == 0)						// if player != gone to bat
    {							// they do not recieve an avg
        atBats = -1;
    }

    else
    {
        j = getHits();

        atBats = j / i;
    }

    return atBats;
}

//*****************************************************
//Function: void print()
//
//Input: nothing
//
//Purpose: To print out the player's stats
//*****************************************************
void Player::print()
{
	cout << left << setw(4) << getNumber()		// printing stats
    		<< left << setw(27) << getName()
    		<< left << setw(5) << getPosition()
    	 	<< right << setw(3) << getHits()
    	 	<< right << setw(5) << getAtBats();

if (battingAverage() < 0)				// if invalid avg, put a '-'
	cout << right << setw(7) << "-";
else
    	cout << right << setw(7) << fixed << setprecision(3) << battingAverage();
}

//*****************************************************
//Function: int getNumber()
//
//Input: nothing
//
//Purpose: to get the player's number
//*****************************************************
int Player::getNumber()
{
    return player_number;
}

//*****************************************************
//Function: char* getName()
//
//Input:nothing
//
//Purpose:to get the player's name via object address
//*****************************************************
char* Player::getName()
{
    return playerName;
}

//*****************************************************
//Function: char* getPosition()
//
//Input: nothing
//
//Purpose: to get the player's position via address
//*****************************************************
char* Player::getPosition()
{
    return playerPosition;
}

//*****************************************************
//Function: int getHits()
//
//Input:nothing
//
//Purpose: to get the nuymber of player's hits
//*****************************************************
int Player::getHits()
{
    return NumOfHits;
}

//*****************************************************
//Function: int getAtBats()
//
//Input:nothing
//
//Purpose: to get the number of times the player has
//		gone up to bat
//*****************************************************
int Player::getAtBats()
{
    return numTimesAtBat;
}


