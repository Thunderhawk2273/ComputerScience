#include <iostream>
#include <iomanip>
#include "Player.h"
#include "Team.h"

using std::cout;
using std::endl;
using std::fixed;
using std::setprecision;

int main()
   {
	Team team("playerdata");

        team.print();

        team.updateStats("gamestats.txt");

        team.print();

	return 0;
   }
