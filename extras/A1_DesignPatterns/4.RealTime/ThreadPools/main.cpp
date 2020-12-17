#include <iostream>
#include <string>
#include "executor.h"
using namespace std;



struct job1 : public functor
{
	void operator() () { Sleep(100); cout << "1"; }
};

struct job2 : public functor
{
	void operator() () { Sleep(200); cout << "2"; }
};

struct job3 : public functor
{
	void operator() () { Sleep(300); cout << "3"; }
};

struct job4 : public functor
{
	void operator() () { Sleep(400); cout << "4"; }
};

struct job5 : public functor
{
	void operator() () { Sleep(500); cout << "5"; }
};

struct job6 : public functor
{
	void operator() () { Sleep(600); cout << "6"; }
};

struct job7 : public functor
{
	void operator() () { Sleep(700); cout << "7"; }
};



int main()
{
	job1 a;
	job2 b;
	job3 c;
	job4 d;
	job5 e;
	job6 f;
	job7 g;

	executor ex;
	ex.start();
	for(int i = 0; i < 25; i++)
	{
		ex.submitJob(a);
		ex.submitJob(b);
		ex.submitJob(c);
		ex.submitJob(d);
		ex.submitJob(e);
		ex.submitJob(f);
		ex.submitJob(g);
	}
	MessageBox(0, "End main?", "Main", MB_OK);
}
