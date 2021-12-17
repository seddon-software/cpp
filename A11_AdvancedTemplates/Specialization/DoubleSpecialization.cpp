#include <iostream>
using namespace std;


template <typename T>
class Foo
{
public:
	template <typename U>
    void bar(U var)
	{
		cout << "Generic bar(U)" << endl;
	}

    void bar(int var)
    {
    	// __PRETTY_FUNCTION__ is a gcc extension
		cout << "Generic bar(int)" << __PRETTY_FUNCTION__ << endl;
    }
};

// full specialization on the class AND
// full specialization on the method
template <> template<>
void Foo<int>::bar<int>(int x)
{
	cout << "Specialization bar(int)" << __PRETTY_FUNCTION__ << endl;
}

int main()
{
	Foo<int> f;
	f.bar(5.0);
	f.bar(5);
	f.bar<int>(5);
}

