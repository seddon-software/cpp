////////////////////////////////////////////////////////////
//
//		Template Method
//
////////////////////////////////////////////////////////////


class Employee
{
public:
	// this method is partially defined in the base class
	// ... and partially defined in the derived class
	void ChangeDepartment() 
	{
		SetDepartment();	// defined in base class
		SetSalary();		// defined in derived class
	}
private:
	virtual void SetSalary() = 0;

	void SetDepartment()
	{
		// implementation for all employees
	}
};

class FullTime : public Employee
{
private:
	virtual void SetSalary() 
	{
		// implementation for Full Time employees
	}
};

class PartTime : public Employee
{
private:
	virtual void SetSalary() 
	{
		// implementation for Part Time employees
	}
};

////////////////////////////////////////////////////////////

int main()
{
	FullTime john;
	PartTime sue;
	john.ChangeDepartment();
	sue.ChangeDepartment();
}
