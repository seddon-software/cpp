#include <iostream>
#include "Team.h"

int main()
{
	Team spurs("Spurs");
	Team rangers("Rangers");
	Team rockets("Rockets");
	Team stingray("Stingray");
	spurs >> rangers;
	rockets >> spurs;
	rockets >> stingray;
	stingray >> spurs;
	Team::printTable();
}

