////////////////////////////////////////////////////////////
//
//		Non Virtual Interface Pattern
//
////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
using namespace std;

/*
 *  The non-virtual interface pattern (NVI) controls how methods in a base class are overridden. 
 *  It is related to the template method pattern.
 *
 *  Looking at the Car base class, you will find 3 pure virtual methods:
 *      	virtual void start() = 0;
 *          virtual void drive() = 0;
 *          virtual void stop() = 0;
 *
 *  Implementations for these metohds are provided in the 2 derived classes:
 *          class SportsCar
 *          class ElectricCar
 * 
 *   In the base class, doJourney() implements the template method; it controls which virtual methods
 *   are called and in what order.  This means that when doJourney is called for each type of car,
 *   although same virtual methods are called, they are customized for each derived class.   
 */

class Car {
public:
	Car(const string& type) : type(type) {}
	void doJourney() {
		// template method
		start();
		drive();
		stop();
	}
	virtual ~Car() {}
protected:
	string type;
private:
	// these methods are hidden from the class user
	// i.e. not part of the public interface
	virtual void start() = 0;
	virtual void drive() = 0;
	virtual void stop() = 0;
};

class SportsCar : public Car
{
public:
	SportsCar(const string& type) : Car(type) {}
private:
	// customization in derived class (V-Tables ignore private)
	virtual void start() { cout << "starting " << type << endl; }
	virtual void drive() { cout << "driving " << type << endl; }
	virtual void stop() { cout << "stopping " << type << endl; }
};

class ElectricCar : public Car
{
public:
	ElectricCar(const string& type) : Car(type) {}
private:
	// customization in derived class (V-Tables ignore private)
	virtual void start() { cout << "starting quietly " << type << endl; }
	virtual void drive() { cout << "driving  quietly " << type << endl; }
	virtual void stop()  { cout << "stopping  quietly " << type << endl; }
};

/////

int main()
{
	Car* sportsCar = new SportsCar("Sports Car");
	sportsCar->doJourney();

	Car* electricCar = new ElectricCar("Electric Car");
	electricCar->doJourney();
}
