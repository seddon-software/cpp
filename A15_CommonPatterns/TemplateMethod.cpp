////////////////////////////////////////////////////////////
//
//		Template Method
//
////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;


class Employee
{
public:
	// this method is partially defined in the base class
	// ... and partially defined in the derived class
	void ChangeDepartment() 
	{
		SetDepartment();	// can't be overriden
		SetSalary();		// must be overriden
		Report();			// can be overriden
	}
private:
	virtual void SetSalary() = 0;
	virtual void Report() { cout << "basic report" << endl; }
	void SetDepartment() { cout << "setting department" << endl; }
};

class FullTime : public Employee
{
private:
	virtual void SetSalary() { cout << "setting salary for Full Time employees" << endl; }
	virtual void Report() { cout << "Full Time report" << endl; }
};

class PartTime : public Employee
{
private:
	virtual void SetSalary() { cout << "setting salary for Part Time employees" << endl; }
};

class Contractor : public Employee
{
private:
	virtual void SetSalary() { cout << "setting salary for Contractor employees" << endl; }
};

////////////////////////////////////////////////////////////

int main()
{
	FullTime john;
	PartTime sue;
	Contractor bill;
	john.ChangeDepartment();
	sue.ChangeDepartment();
	bill.ChangeDepartment();
}
