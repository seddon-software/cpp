#include <iostream>
#include <vector>
#include <sstream>
#include <memory>
using namespace std;


/*
 Vehicle
 Bicycle 			Car  						Truck
 Pedal,Motorized	Hatch-back, Sports, Estate	Tail-lift, Refrigerated, Flatbed
 */

/*
 string make;  //make
    string model; // model
    string color;  // color
    int	year;  // year
    int mileage;  // miles on car
	string type;  //Type of vehicle
 */
class Vehicle
{
public: // interface
	virtual ~Vehicle() { cout << "Vehicle::DTOR()" << endl; }
private:
	string color;
};

class Bicycle : public Vehicle
{
public:
	virtual ~Bicycle() { cout << "Rectangle::DTOR()" << endl; }
private:

};

class LicencedVehicle : public Vehicle
{
public:
	virtual string info()
	{
		stringstream s;
		s << make << ","
		  << model << ","
		  << color << ","
		  << year << ","
		  << mileage << ","
		  << registrationNumber;
		  return s.str();
	}
	virtual ~LicencedVehicle() { cout << "LicencedVehicle::DTOR()" << endl; }
private:
	string make;
	string model;
	string color;
	int year;
	int mileage;
	string registrationNumber;
};

class Car : public LicencedVehicle
{
public:
	virtual ~Car() { cout << "Car::DTOR()" << endl; }
};

class Truck : public LicencedVehicle
{
public:
	virtual ~Truck() { cout << "Ellipse::DTOR()" << endl; }
private:
	string tax;
};

class Pedal : public Bicycle {};
class HatchBack : public Car {};
class SportsCar : public Car {};
class EstateCat : public Car {};
class Refrigerated : public Truck {};
class FlatBed : public Truck {};

typedef unique_ptr<Vehicle> VEHICLE;
typedef vector<VEHICLE> VECTOR;

void show_all(VECTOR& v)
{
	for(auto& ptr : v)
	{
//		ptr->show();
	}
}

int main()
{
	VECTOR v;
	v.push_back(VEHICLE(new Pedal()));
	v.push_back(VEHICLE(new HatchBack()));
	show_all(v);
}




