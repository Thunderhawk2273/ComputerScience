//*****************************************************************
// FILE:      Player.h
// AUTHOR:    William Freriks
// LOGON ID:  Z1698749
// DUE DATE:  2/12/15
//
// PURPOSE:   Contains the declaration for the Player class.
//*****************************************************************

#ifndef PLAYER_H
#define PLAYER_H

class Player
{
public:
    Player();						//Default
    Player(int , char [], char [], int , int );		//Actual Player

    int getNumber();					//Get the stats
    int getHits();
    int getAtBats();

    char* getName();
    char* getPosition();

    double battingAverage();				//calculate the batting avg

    void setHits(int);					//Setting stats
    void setAtBats(int);
    void print();					//Printing the player

private:						//Data values
    int player_number;
    char playerName[26];
    char playerPosition[3];
    int NumOfHits;
    int numTimesAtBat;
};

#endif
