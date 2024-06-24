/*
 Define and implement a Ladder class that represents a squash league in which
 teams play each other. Create a Team class to hold each team's results
 (number of games won, drawn and lost). The Ladder class will hold a list of
 all the teams.
Create a test harness that defines the results of several games and prints
out the current standings of the table.

 */
#include "Team.h"

#include <iostream>
#include <sstream>

League Team::league;


void operator>>(Team& lhs, Team& rhs)
{
	lhs.won++;
	rhs.lost++;
}

Team::Team(const string& name): name(name), won(0), lost(0)
{
	league.add(*this);
}

string Team::status() const
{
	stringstream ss;
	ss << name << ": won=" << won << " lost=" << lost << endl;
	return ss.str();
}

void Team::printTable()
{
	league.print();
}

