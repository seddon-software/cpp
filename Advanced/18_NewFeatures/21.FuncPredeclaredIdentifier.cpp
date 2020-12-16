#include <iostream>
#include <string>

using namespace std;

/*
 *
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
