////////////////////////////////////////////////////////////
//
//		Bind and Function
//
////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


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
	void print() const
	{
		cout << "[" << name << ","
		            << address << ","
		            << age << "]" << endl;
	}
};


//////

void printList(vector<Person> list)
{
	vector<Person>::iterator i;
	for(i = list.begin(); i != list.end(); ++i)
	{
		i->print();
	}
	cout << "xxxx" << endl;
}

template <typename T, int N>
class Compare
{
public:
	bool operator() (const T& _1, const T& _2)
	{
		if(N == 1) return _1.getName() < _2.getName();
		if(N == 2) return _1.getAddress() < _2.getAddress();
		if(N == 3) return _1.getAge() < _2.getAge();
		return false;
	}
};



int main()
{
	vector<Person> theList;

    theList.push_back(Person("Smith", "London", 43));
    theList.push_back(Person("Jones", "Cardiff", 51));
    theList.push_back(Person("Lee",   "New York", 24));

    // sort on age
    sort(theList.begin(),
         theList.end(),
         Compare<Person,3>());

    printList(theList);

    // sort on name
    sort(theList.begin(),
         theList.end(),
         Compare<Person,1>());
    printList(theList);

    // sort on address
    sort(theList.begin(),
         theList.end(),
         Compare<Person,2>());
    printList(theList);
}

