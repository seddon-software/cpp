////////////////////////////////////////////////////////////
//
//		List - value semantics
//
////////////////////////////////////////////////////////////

#include <iostream>
#include <list>
#include <string>
#include <iterator>
#include <algorithm>

using namespace std;

/*
 *  STL containers use value semantics; when items are added to a collection they are copied.  The
 *  containers do not allow passing in references.  If you don't want to use copies in a collection
 *  you can use pointers as the container type.
 *
 *  Here we add copies of Employees to a list and then to check for value semantics, we make a change
 *  to one of the original Employees and then check the collection remains unchanged.
 * 
 *  Notice the use of the copy algorithm in conjunction with an ostream_iterator to print out the 
 *  collection.
 */

class Employee
{
friend ostream& operator<<(ostream& os, const Employee& e);
public:
	Employee(string theName, int theSalary)
	:
		name  (theName),
		salary(theSalary)
	{}

	string getName() const { return name; }
	int getSalary() const { return salary; }

	void setSalary(int salary)
	{ 
		(*this).salary = salary; 
	}
private:
	string name;
	int    salary;
};

/////

ostream& operator<<(ostream& os, const Employee& e)
{
	os << e.getName() << " " << e.getSalary();
	return os;
}

/////

int main()
{
	list<Employee> collection;

	Employee worker1("Steven", 25000);
	Employee worker2("Mary",   28000);
	Employee worker3("John",   20000);
	Employee worker4("Susan",  36500);
	Employee worker5("Rose",   17500);

    // add copies of workers to the collection
	collection.push_back(worker1);
	collection.push_back(worker2);
	collection.push_back(worker3);
	collection.push_back(worker4);
	collection.push_back(worker5);

    // change one of the original workers
	worker1.setSalary(22222);	// doesn't change collection
	cout << "changed worker1: " << worker1 << endl;

	// use copy algorithm to print entire collection using ostream_iterator
	cout << "\nPrinting Collection" << endl;
	copy(collection.begin(), collection.end(), ostream_iterator<Employee>(cout, "\n"));
}

