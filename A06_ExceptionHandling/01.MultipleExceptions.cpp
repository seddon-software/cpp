#include <iostream>
#include <exception>
using namespace std;

/*
 *  With exception handling, you can define several catch handlers.  When an exception is thrown
 *  only one handler will be called.  The compiler will ensure the handler matches the class of 
 *  the object throw, unless you are using inheritance (see later examples).
 * 
 *  Note: in this example we've used a struct because everything is public with a struct including
 *  defaulting to public inheritance (a class uses private inheritance by default).
 * 
 *  By using struct and public inheritance, we simplify our code while still supporting the substitution
 *  rule (which requires public inheritance).
 */

struct A : exception {};
struct B : exception {};
struct C : exception {};

int main()
{
	try
	{
	    throw A();
	}
	catch(const A& e) { cout << "A" << endl; }  // this will catch A()
	catch(const B& e) { cout << "B" << endl; }
	catch(const C& e) { cout << "C" << endl; }

	try
	{
	    throw B();
	}
	catch(const A& e) { cout << "A" << endl; }
	catch(const B& e) { cout << "B" << endl; }  // this will catch B()
	catch(const C& e) { cout << "C" << endl; }

	try
	{
	    throw C();
	}
	catch(const A& e) { cout << "A" << endl; }
	catch(const B& e) { cout << "B" << endl; }
	catch(const C& e) { cout << "C" << endl; }  // this will catch C()
}
