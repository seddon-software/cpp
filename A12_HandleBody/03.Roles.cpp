//////////////////////////////////////////////////////////////////////
//
//		Roles
//
//////////////////////////////////////////////////////////////////////

#include <string>
#include <map>
#include <iostream>
#include <memory>
#include <vector>
using namespace std;

/*  
 *  A slightly different example of handle-body is in the use of roles.  We can use roles to 
 *  effectively allow an object to dynamically change class.  We create a hierarchy of roles 
 *  as follows:
 *
 *
 *    Employee ----------  Role
 *	                         ^
 *	      	                 |
 *            --------------------------------
 *	          |              |               |
 *	    AssociateRole >> ManagerRole >> DirectorRole
 *
 * 
 *  The RoleMap class keeps a tracks these relationships.  Next, we create several Employee 
 *  objects, each associated with a role.  We can't change the class of these objects, but 
 *  we can change their roles, effectively promoting employees (see the Employee::promote method).
 */

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
	virtual ~AssociateRole() { cout << "AssociateRole DTOR" << endl; }
private:
	const string roleName = "Associate";
};

/////

class ManagerRole : public Role 
{
public:
	double pay (double s) const { return s * 1.2; }
	string getRole () const { return roleName; }
	virtual ~ManagerRole() { cout << "ManagerRole DTOR" << endl; }
private:
	const string roleName = "Manager";
};

/////

class DirectorRole : public Role
{
public:
	double pay (double s) const { return s * 1.5; }
	string getRole () const { return roleName; }
	virtual ~DirectorRole() { cout << "DirectorRole DTOR" << endl; }
private:
	const string roleName = "Director";
};

// global
vector<shared_ptr<Role>> rollMap 
{ 
    {shared_ptr<Role>(new AssociateRole())},
    {shared_ptr<Role>(new ManagerRole())},
    {shared_ptr<Role>(new DirectorRole())}
}; 

////////////////////////////////////////////////////////////
// implementations

class Employee
{
private:
	int dob;
	string name;
	double salary;
	shared_ptr<Role> job;
    int index = 0;
public:
	Employee (int d, const string& n, double s): dob (d), name (n), salary (s)
    {
        job = rollMap[index];
    }
	double setSalary()
    {
        salary = job->pay(salary); 
        return salary;
    }
	void print () const
    {
        cout << name << " " << job->getRole() 
            << " " << salary << endl;
    }
	void promote()
    {
        index++;
        job = rollMap[index];
    }
};

////////////////////////////////////////////////////////////

int main()
{
	Employee zoe(2022, "zoe", 25000.0);
	zoe.setSalary();
	zoe.print();
	zoe.promote();
	zoe.setSalary();   // 20% increase in salary
	zoe.print();
	zoe.promote();
	zoe.setSalary();    // 50% increase in salary
	zoe.print();
}

