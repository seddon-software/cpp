#ifndef TEAM_H
#define TEAM_H

#include <iostream>
#include <string>
#include <vector>

#include "League.h"
using namespace std;

class League;

class Team
{
public:
	Team(const string& name);
	friend void operator>>(Team& lhs, Team& rhs);
	string status() const;
	static void printTable();
private:
	static League league;
	string name;
	int won;
	int lost;
};

#endif
