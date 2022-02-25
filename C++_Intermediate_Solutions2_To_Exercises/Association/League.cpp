#include "League.h"

#include <iostream>
#include <sstream>

class Team;

void League::add(const Team& team)
{
	pTeams.push_back(&team);
}

void League::print() const
{
	for(const auto* pTeam : pTeams)
	{
		cout << pTeam->status();
	}
}


