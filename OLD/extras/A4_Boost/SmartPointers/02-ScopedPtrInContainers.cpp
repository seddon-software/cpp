////////////////////////////////////////////////////////////
//
//		Scoped Pointer
//
////////////////////////////////////////////////////////////


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <boost/scoped_ptr.hpp>
using namespace std;


class person
{
public:
	person(const string& n) : name(n)
	{
		cout << "CTOR called for " << name << endl;
	}

	~person()
	{
		cout << "DTOR called for " << name << endl; 
	}

	void print(){ cout << name << endl; }
private:
	string name;
};

/////

typedef boost::scoped_ptr<person> SCOPED_PTR;

int main()
{
	{
	    // scoped_ptr can't be copied
		// so can't be used in STL except by pointer
	    vector<SCOPED_PTR*> v;

		SCOPED_PTR john(new person("John"));
	    SCOPED_PTR hilda(new person("Hilda"));
	    SCOPED_PTR peter(new person("Peter"));
	    SCOPED_PTR mary(new person("Mary"));
		v.push_back(&john);
		v.push_back(&hilda);
		v.push_back(&peter);
		v.push_back(&mary);

		for(unsigned i = 0; i < v.size(); ++i)
		{
			SCOPED_PTR& p = *v[i];
			p->print();
		}
	}

	return 0;
}
