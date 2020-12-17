#include "functor.h"

class job : public functor
{
public:
	void operator() ()
	{
		wcout << "Job A" << endl;
	}
private:
};

class jobB : public functor
{
public:
	void operator() ()
	{
		wcout << "Job B" << endl;
	}
};

class jobC : public functor
{
public:
	void operator() ()
	{
		wcout << "Job C" << endl;
	}
};

class jobD : public functor
{
public:
	void operator() ()
	{
		wcout << "Job D" << endl;
	}
};


