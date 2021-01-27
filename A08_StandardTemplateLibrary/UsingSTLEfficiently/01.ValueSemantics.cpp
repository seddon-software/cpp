////////////////////////////////////////////////////////////
//
//		List - value semantics
//
////////////////////////////////////////////////////////////

#include <iostream>
#include <list>
#include <string>
#include <algorithm>

using namespace std;


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
	bool operator==(const Employee& e) const { return name == e.name; };
	bool operator!=(const Employee& e) const { return name != e.name; };
private:
	string name;
	int    salary;
};

/////

ostream& operator<<(ostream& os, const Employee& e)
{
	os << e.getName() << " " <<e.getSalary();
	return os;
}

/////

int main()
{
	list<Employee> collection;
	list<Employee>::iterator i;

	Employee worker1("Steven", 25000);
	Employee worker2("Mary",   28000);
	Employee worker3("John",   20000);
	Employee worker4("Susan",  36500);
	Employee worker5("Rose",   17500);

	collection.push_back(worker1);	// copies
	collection.push_back(worker2);
	collection.push_back(worker3);
	collection.push_back(worker4);
	collection.push_back(worker5);

	worker1.setSalary(22222);	// doesn't change collection
	cout << worker1 << endl;

	// print entire collection
	cout << "Printing Collection1" << endl;
//	for_each(collection.begin(), collection.end(), Print);
	copy(collection.begin(), collection.end(), ostream_iterator<Employee>(cout, "\n"));

}

