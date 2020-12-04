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
friend void Print(const Employee& e);
public:
	Employee(string theName, int theSalary)
	:
		name  (theName),
		salary(theSalary)
	{}

	int GetSalary() const 
	{ 
		return salary; 
	}

	void SetSalary(int salary)
	{ 
		(*this).salary = salary; 
	}

	void Print() const
	{ 
		cout << name << ", " << salary << endl; 
	}

	bool operator==(const Employee& e) const { return name == e.name; };
	bool operator!=(const Employee& e) const { return name != e.name; };
private:
	string name;
	int    salary;
};

/////

void Print(const Employee& e)
{
	e.Print();
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

	worker1.SetSalary(22222);	// doesn't change collection

	// print entire collection
	cout << "Printing Collection1" << endl;
	for_each(collection.begin(), collection.end(), Print);

	return 0;
}

