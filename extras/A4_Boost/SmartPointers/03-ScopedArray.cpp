////////////////////////////////////////////////////////////
//
//		Scoped Array
//
////////////////////////////////////////////////////////////

#include <iostream>
#include <boost/scoped_array.hpp> 
using namespace std;

class person
{
friend ostream& operator<<(ostream&, const person&);
public:
	person(const string& n = "") : name(n)
	{
		cout << "CTOR called for " << name << endl;
	}

	~person()
	{
		cout << "DTOR called for " << name << endl;
	}
	void f(){}
private:
	string name;
};

ostream& operator<<(ostream& os, const person& rhs)
{
	return os << rhs.name;
}

int main() 
{ 
	boost::scoped_array<person> array(new person[5]);
	array[0] = person("John");
	array[1] = person("Mary");
	array[2] = person("Bill");
	array[3] = person("Mike");
	array[4] = person("Jane");

	for(int i = 0; i < 5; i++)
	{
		cout << array[i] << endl;
	}
	// retreive pointer
	person* ptr = array.get();

	// objects get cleaned up when they go out of scope
}
