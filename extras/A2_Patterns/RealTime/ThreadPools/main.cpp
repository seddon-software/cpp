#include <iostream>
#include <string>
#include "executor.h"
using namespace std;



class jobA : public functor
{
public:
	void operator() ()
	{
		cout << "Job A" << endl;
	}
};

class jobB : public functor
{
public:
	void operator() ()
	{
		cout << "Job B" << endl;
	}
};

class jobC : public functor
{
public:
	void operator() ()
	{
		cout << "Job C" << endl;
	}
};

class jobD : public functor
{
public:
	void operator() ()
	{
		cout << "Job D" << endl;
	}
};


int main()
{
	executor e;
	for(int i = 0; i < 25; i++)
	{
		jobA a;
		jobB b;
		jobC c;
		jobD d;
		e.submitJob(a);
		e.submitJob(b);
		e.submitJob(c);
		e.submitJob(d);
	}
	e.start();
	MessageBox(0, "End main?", "Main", MB_OK);
}
