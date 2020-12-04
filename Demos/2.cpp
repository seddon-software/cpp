#include <iostream>
#include <vector>
#include <tuple>
#include <utility>
#include <sstream>
#include <memory>
#include <stdexcept>

using namespace std;
typedef pair<string,string> tuple2;
typedef tuple<string,string,string,string,string> tuple5;


class bad_swap : public exception
{
public:
	bad_swap(const string& player) : player(player) {}
	virtual const char* what() const noexcept
	{
		return (player + string(" is not in the team")).c_str();
	}
private:
	string player;
};

template <typename T>
class Groupings
{
public:
	virtual string info() = 0;
	virtual ~Groupings() {}
	Groupings(T list):list(list) {}
	T getList() { return list; }
	void setList(T list) { this->list = list; }
private:
	T list;
};

class Swap
{
public:
	virtual void swapPlayers(const string&, const string&) = 0;
	virtual ~Swap() {}
};

class Singles : public Groupings<string>
{
public:
	Singles(const string& p) : Groupings<string>(p) {}
	virtual string info()
	{
		return getList();
	}
};

class Doubles : public Groupings<tuple2>, public Swap
{
public:
	Doubles(const string& first, const string& second) : Groupings<tuple2>(make_pair(first, second)) {}
	string info()
	{
		tuple2 list = getList();
		return list.first + ", " + list.second;
	}
	virtual void swapPlayers(const string& current, const string& replacement)
	{
		tuple2 list = getList();
		tuple2 newList = list;
		if(list.first == current)
		{
			newList.first = replacement;
		}
		else if(list.second == current)
		{
			newList.second = replacement;
		}
		else
		{
			throw bad_swap(current);
		}
		setList(newList);
	}
};

class FiveASideTeam : public Groupings<tuple5>, public Swap
{
public:
	FiveASideTeam(const string& p1, const string& p2, const string& p3, const string& p4, const string& p5):
		Groupings<tuple5>(make_tuple(p1, p2, p3, p4, p5)) {}
	string info()
	{
		stringstream s;
		string player[5];
		tie(player[0], player[1], player[2], player[3], player[4]) = getList();
		for(int i = 0; i < 5; i++)
		{
			s << player[i] << ";";
		}
		return s.str();
	}
	virtual void swapPlayers(const string& current, const string& replacement)
	{
		tuple5 list = getList();
		tuple5 newList = list;
		string player[5];
		tie(player[0], player[1], player[2], player[3], player[4]) = getList();

		for(int i = 0; i < 5; i++)
		{
			if(player[i] == current)
			{
				player[i] = replacement;
			}
		}
		newList = make_tuple(player[0], player[1], player[2], player[3], player[4]);
		if(newList == list)
		{
			throw bad_swap(current);
		}
		setList(newList);
	}
};

int main()
{
	Singles tom("Tom Sheridan");
	Doubles philAndGeorge("Phil Tandy", "George Ball");
	FiveASideTeam galaxy("Jim", "Susan", "Peter", "Luke", "Zoe");
	cout << tom.info() << endl;
	cout << philAndGeorge.info() << endl;
	cout << galaxy.info() << endl;
	philAndGeorge.swapPlayers("George Ball", "Peter Smith");
	cout << philAndGeorge.info() << endl;
	philAndGeorge.swapPlayers("Phil Tandy", "Jim Cutchon");
	cout << philAndGeorge.info() << endl;
	galaxy.swapPlayers("Peter", "Ian");
	cout << galaxy.info() << endl;
	try
	{
		galaxy.swapPlayers("Peter", "Terry");
		cout << galaxy.info() << endl;
	}
	catch(const bad_swap& e)
	{
		cout << e.what() << endl;
	}

	try
	{
		philAndGeorge.swapPlayers("Phil Tandy", "John Smeek");
		cout << philAndGeorge.info() << endl;
	}
	catch(const bad_swap& e)
	{
		cout << e.what() << endl;
	}
}
