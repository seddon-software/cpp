////////////////////////////////////////////////////////////
//
//		Template Method
//
////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;


/*
 *  The template method controls how other methods are called from a public method.  Typically a given
 *  method is partially defined in the base class and partially defined in a derived class.  
 *  
 *  Note, in this example, the ChangeDepartment() method first calls SetDepartment() using early binding
 *  and hence can't be overridden by a derived class.  
 *  Next, it calls the pure virtual method SetSalary(), which means it must be overridden in a derived 
 *  class.
 *  Finally Report() is called.  As this is a virtual method, optionally, it can be overridden in a 
 *  derived class, but this is not mandatory, as the base class defines a default version of this method.
 * 
 *  This combination of non-virtual, pure virtual and virtual methods gives maximum flexibility to the
 *  template method.  Obviously, other examples can use permutations of these methods.
 */

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
