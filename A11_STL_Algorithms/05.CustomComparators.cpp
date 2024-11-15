////////////////////////////////////////////////////////////
//
//		Bind and Function
//
////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

/*
 *  We are using the sort algorithm with a templated comparator function.  The idea is to sort
 *  a group of Person objects.  Note the use of the (C++11) enum class in the comparator.
 */

enum class Field { name, address, age };

class Person
{
private:
	string name;
	string address;
	int age;
public:
	Person(string name, string address, int age)
		:name(name), address(address), age(age) {}

	string getName()    const	{ return name; }
	string getAddress() const	{ return address; }
	int    getAge()     const	{ return age; }
	friend ostream& operator<<(ostream&, const Person&);
};

ostream& operator<<(ostream& os, const Person& p)
{
	os << "[" << p.name << ","
	          << p.address << ","
	          << p.age << "]";
	return os;
}


//////

template <typename T>
void printList(vector<T> v)
{
	copy(v.begin(), v.end(), ostream_iterator<T>(cout));
    cout << flush;
}

/*
 *  Comparison function object (object that satisfies the requirements of Compare) returns ​true if 
 *  the first argument is less than the second.  
 * 
 *  The signature of the comparison function should be:
		bool cmp(const T1 &t1, const T2 &t2);
 */

template <typename T, Field F>
class Compare
{
public:
	bool operator() (const T& t1, const T& t2)
	{
		if(F == Field::name)    return t1.getName() < t2.getName();
		if(F == Field::address) return t1.getAddress() < t2.getAddress();
		if(F == Field::age)     return t1.getAge() < t2.getAge();
		return false;
	}
};



int main()
{
	vector<Person> theList;

    theList.push_back(Person("Smith", "London", 43));
    theList.push_back(Person("Jones", "Cardiff", 51));
    theList.push_back(Person("Lee",   "New York", 24));

    cout << endl << "sort on age" << endl;
    sort(theList.begin(),
         theList.end(),
         Compare<Person,Field::age>());

    printList(theList);

    cout << endl << "sort on name" << endl;
    sort(theList.begin(),
         theList.end(),
         Compare<Person,Field::name>());
    printList(theList);

    cout << endl << "sort on address" << endl;
    sort(theList.begin(),
         theList.end(),
         Compare<Person,Field::address>());
    printList(theList);
}

