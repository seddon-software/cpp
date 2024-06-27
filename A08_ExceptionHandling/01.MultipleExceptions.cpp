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

#include <iostream>
#include <exception>
using namespace std;

// define your own exceptions more relevent to your problem domain
struct TooHot : exception {};
struct TooCold : exception {};
struct MilesTooHot : exception {};

int main()
{
    int temp = 30;          // try different values
	try
	{
	    if (temp < 0) throw TooCold();
	    if (temp > 100) throw TooHot();
	    if (temp > 300) throw MilesTooHot();
        cout << "important stuff" << endl;      // never called if excepion thrown
	}
	catch(const TooHot& e) { cout << "TooHot" << endl; }  // this will catch A()
	catch(const TooCold& e) { cout << "TooCold" << endl; }
	catch(const MilesTooHot& e) { cout << "MilesTooHot" << endl; }
    catch(...) { cout << "unknown error" << endl;}
    cout << "after catch handlers" << endl;
}
