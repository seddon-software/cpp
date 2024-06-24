#ifndef LEAGUE_H
#define LEAGUE_H

#include <iostream>
#include <string>
#include <vector>

#include "Team.h"
using namespace std;

class Team;

class League
{
public:
	League() {}
	void add(const Team& team);
	void print() const;
private:
	vector<const Team*> pTeams;
};

#endif
