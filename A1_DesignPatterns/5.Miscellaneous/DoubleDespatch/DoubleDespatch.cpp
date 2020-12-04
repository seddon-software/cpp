#include <iostream>
using namespace std;

class Person;

class Car 
{
public:
	virtual void DoDrive(Person& p);
};

class CompanyCar : public Car 
{ 
public:
	virtual void DoDrive(Person& p);	
};

class Person 
{
public:
  virtual void Drive(Car& c);
  virtual void Drive(CompanyCar& cc);
};

class Employee : public Person 
{
public:
  virtual void Drive(Car&);
  virtual void Drive(CompanyCar& cc);
};

void Car::DoDrive(Person& p) {}		
void CompanyCar::DoDrive(Person& p) {}	
void Person::Drive(Car& c) { c.DoDrive(*this); }
void Person::Drive(CompanyCar& cc) { cc.DoDrive(*this); }
void Employee::Drive(Car& c) { c.DoDrive(*this); }
void Employee::Drive(CompanyCar& cc) { cc.DoDrive(*this); }

int main()
{
    Person john;
    Employee johnson;
    Car c;
    CompanyCar cc;

    Person& personRef = johnson;
    Car& carRef = cc;
    john.Drive(carRef); 	 // calls Person::Drive(Car&) and not Person::Drive(CompanyCar&)  	 
    personRef.Drive(carRef); // calls Employee::Drive(Car&) and not Employee::Drive(CompanyCar&)
}
