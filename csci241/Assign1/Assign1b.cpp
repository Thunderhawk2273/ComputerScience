/**********************************************************************
 CSCI 241         Program 1     Fall 2014

 Programmer: William Freriks

 Section: 01

 Date Due: 2/1/2015

 Purpose: This program calculates and displays the user's numerology.
 **********************************************************************/



#include <iostream>
#include <iomanip>
#include <cstring>
#include <cctype>


using namespace std;

void gettingTheWorkDone(char array[81]);                                // Main function
void table(int);                                                // Results function
void recalculate(int);                                          // Recalculate the sum

char name[81];
char ch;

int main()
{
    cout << "Welcome to the Spirituality Table."
         << endl << endl;

    do
    {
        cout << endl << "What is your name? ";
        cin.getline(name, 80);                                     // input the name

        gettingTheWorkDone(name);                                // The main funct

        cout << endl << endl
             << "Would you like to input another name? Y to continue, "
             << "or another character to discontinue. ";

        cin >> ch;
	cin.ignore();

    }
   while (ch == 'y' || ch == 'Y');

        return 0;
}

// FUNCTIONS

/***************************************************************
 Function:  void gettingTheWorkDone(string namechange)

 Use: Gets all of the number calculations done

 Arguments: 1 string: the person's name

 Returns: none
 ***************************************************************/
void gettingTheWorkDone(char  namechange[81])
{
    int i, sum;
    char namearray[81];

    i = 0;
    sum = 0;

	strcpy(namearray, namechange);

    for (i = 0; i <= 80; i++)                   // getting the numbers for the cha$
                                                // adding them up
    {
        if (namearray[i] =='\0')
            break;
                                                // also taking away dashs and spac$
        else if (namearray[i] == '-')
            sum = sum + (tolower(namearray[i]) - '-');

        else if (namearray[i] == ' ')
            sum = sum + (tolower(namearray[i]) - ' ');

        else
            sum = sum + (tolower(namearray[i]) - 'a'+1);
    }

    cout << sum << endl << endl;

    table(sum);                                 // checking the table for results

    }


/***************************************************************
 Function:  void table(int inputsum)

 Use: Holds the table of spirituality

 Arguments: 1 int: the sum

 Returns: none
 ***************************************************************/
void table(int inputsum)
 {                                               // I used if-else statements to  c$
    if (inputsum == 0)                          // of the options provided
    {
        cout << "That name has the spirituality traits: "
        << "emptyiness, nothingness, blank.";
    }

    else if (inputsum == 1)
    {
        cout << "That name has the spirituality traits: "
        << "independence, loneliness, creativity, originality, dominance, leadership,"
	<< " impatience.";
    }

    else if (inputsum == 2)
    {
        cout << "That name has the spirituality traits: "
        << "quiet, passive, diplomatic, co-operation, comforting, soothing, intuitive,"
	<< " compromising, patient.";
    }
      else if (inputsum == 3)
    {
        cout << "That name has the spirituality traits: "
        << "charming, outgoing, self expressive, extroverted, abundance, active,"
	<< " energetic, proud.";
    }

    else if (inputsum == 4)
    {
        cout << "That name has the spirituality traits: "
        << "harmony, truth, justice, order discipline, practicality.";
    }

    else if (inputsum == 5)
    {
        cout << "That name has the spirituality traits: "
        << "new directions, excitement, change, adventure.";
    }

     else if (inputsum == 6)
    {
        cout << "That name has the spirituality traits: "
        << "love, harmony, perfection, marriage, tolerance, public service.";
    }

    else if (inputsum == 7)
    {
        cout << "That name has the spirituality traits: "
        << "spirituality, completeness, isolation, introspection.";
    }

    else if (inputsum == 8)
    {
        cout << "That name has the spirituality traits: "
        << "organization, business, commerce, new beginnings.";
    }

    else if (inputsum == 9)
    {
        cout << "That name has the spirituality traits: "
        << "romantic, rebellious, determined, passionate, compassionate.";
    }

    else if (inputsum == 11)
    {
        cout << "That name has the spirituality traits: "
        << "idealism, visionary, inspirational";
    }

    else if (inputsum == 12)
    {
        cout << "That name has the spirituality traits: "
        << "perfectionist, discriminating";
    }

    else if (inputsum == 22)
    {
        cout << "That name has the spirituality traits: "
        << "builder, leader, humanitarian, practical, honest";
    }

     else
        recalculate(inputsum);                                          // If the $
}                                                                       // it gets$

/***************************************************************
 Function:  void recalculate(int moarInputSum)

 Use: Not as fancy as putting the numbers into a string and
        reading/adding them up, this gets the job done

 Arguments: 1 int; the sum

 Returns: none: put into a loop with table
 ***************************************************************/
void recalculate(int moarInputSum)
{
    int j, k, m, newSum;

    m = moarInputSum / 100;                             // Targets the Third digit$

    k = (moarInputSum / 10) % 10;                       // Targets the Second digi$

    j = moarInputSum % 10;                              // Targets the First digit$


    newSum = m + k + j;                                 // The New sum added toget$

    table(newSum);                                      // The New sum gets checke$
                                                        // creates a loop with tab$
}

