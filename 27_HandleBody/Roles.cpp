//////////////////////////////////////////////////////////////////////
//
//		Roles
//
//////////////////////////////////////////////////////////////////////

#include <string>
#include <map>
#include <iostream>
using namespace std;


//  Employee ---------  Role
//	                     ^
//	      	             |
//        --------------------------------
//	      |              |               |
//	AssociateRole >> ManagerRole >> DirectorRole
//
////////////////////////////////////////////////////////////

class Role
{
public:
	virtual double pay (double) const = 0;
	virtual string getRole() const = 0;
	virtual ~Role() {}
};

/////

class AssociateRole : public Role 
{
public:
	double pay (double s) const { return s; }
	string getRole () const { return roleName; }
private:
	const string roleName = "Associate";
};

/////

class ManagerRole : public Role 
{
public:
	double pay (double s) const { return s * 1.2; }
	string getRole () const { return roleName; }
private:
	const string roleName = "Manager";
};

/////

class DirectorRole : public Role
{
public:
	double pay (double s) const { return s * 1.5; }
	string getRole () const { return roleName; }
private:
	const string roleName = "Director";
};

class RoleMap
{
public:
	RoleMap()
	{
		roleMap["Associate"] = new ManagerRole();
		roleMap["Manager"] = new DirectorRole();
		roleMap["Director"] = new DirectorRole();
	}
	Role* operator[](const string& key)
	{
        return roleMap[key];
	}
private:
	map<string, Role*> roleMap;
};
RoleMap theMap;

////////////////////////////////////////////////////////////
// implementations

class Employee
{
private:
	[[ maybe_unused ]] int dob;
	string name;
	double salary;
	Role *job;
public:
	Employee (int d, const string& n, double s);
	~Employee ();
	double pay ();
	void print () const;
	void promote ();
};

Employee::Employee (int d, const string& n, double s)
	: dob (d), name (n), salary (s)
{
	job = new AssociateRole();
}

Employee::~Employee ()
{
	delete job; 
}

double Employee::pay ()
{
	salary = job->pay(salary); 
	return salary;
}

void Employee::print () const 
{
	cout << name << " " << job->getRole() 
	     << " " << salary << endl;
}

void Employee::promote () 
{
	string current_job = job->getRole();
	Role* new_role = theMap[current_job];
	delete job;
    job = new_role;
}

////////////////////////////////////////////////////////////

int main()
{
	Employee zoe(2005, "zoe", 25000.0);
	zoe.pay();
	zoe.print();
	zoe.promote();
	zoe.pay();
	zoe.print();
	zoe.promote();
	zoe.pay();
	zoe.print();

	return 0;
}

