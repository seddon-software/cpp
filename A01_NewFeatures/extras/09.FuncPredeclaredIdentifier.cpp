#include <iostream>
#include <string>

using namespace std;

/*
 *  __func__ is useful for diagnostics 
 */

struct MyClass {
	MyClass() : name(__func__) {}
	void methodA()
	{
		cout << "calling " << __func__ << "() ..." << endl;
	}
	string name;;
};

int main()
{
    MyClass m;
    cout << "Class name = " << m.name << endl;
    m.methodA();
}
