#include <iostream>
#include <exception>
using namespace std;

struct A : exception {};
struct B : exception {};
struct C : exception {};

int main()
{
	try
	{
	    throw A();
	}
	catch(const A& e) { cout << "A" << endl; }
	catch(const B& e) { cout << "B" << endl; }
	catch(const C& e) { cout << "C" << endl; }

	try
	{
	    throw B();
	}
	catch(const A& e) { cout << "A" << endl; }
	catch(const B& e) { cout << "B" << endl; }
	catch(const C& e) { cout << "C" << endl; }

	try
	{
	    throw C();
	}
	catch(const A& e) { cout << "A" << endl; }
	catch(const B& e) { cout << "B" << endl; }
	catch(const C& e) { cout << "C" << endl; }
}
