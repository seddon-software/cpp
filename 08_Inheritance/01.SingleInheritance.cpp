/*  
 *  In C++ when we use inheritance, derived classes inherit all the methods and attributes from
 *  their base class.  In this example Bus, Car and Van all inherit the methods
 *              start(), refuel() and stop().
 *
 *  Note that you must use public inheritance (protected and private inheritance are more closely
 *  related to aggregation/composition).  Methods in the base class usually have parameters (I've left 
 *  them out in this example to keep things simple).
 * 
 *  The idea behind inheritance is code reuse.  This in turn implies that classes in an inheritance
 *  hierarchy must be closely related.  Since all derived classes inherit methods and attributes from their 
 *  base class, they can substitute for base class objects in functions.  This is called:
 *          THE SUBSTITUTION RULE
 * 
 *  Here Bus, Car and Van objects can substitute for Vehicle objects.  In the function:
 *          void refuelAnyVehicle(Vehicle& x) { ... }
 * 
 *  The reference to a Vehicle in this function indicates that a Bus, Car or Van object might be passed 
 *  to the function instead of a Vehicle.  In turn, the function can only call methods defined in the Vehicle
 *  class, but this is fine because all derived classes will inherit these methods.
 * 
 *  Derived classes are free to add additional methods and attributes, but these can't be used in routines
 *  where a Vehicle reference is passed.
 * 
 *  It is important to realize that derived classes always contain at least he same number of methods and 
 *  attributes as their base class and hence the substitution rule is one way; a derived object can
 *  substitute for a base class object, but because the base class might be missing some of the derived 
 *  class's methods and attributes, a base class object can't substitute for a derived object.
 * 
 *  Note that derived classes can provide additional versions of base class methods if they need different
 *  behaviour from the base class; the Bus class provides a second version of the refuel method.  This means
 *  the Bus class now has 4 methods:
 *          Vehicle::start()
 *          Vehicle::stop()
 *          Vehicle::refuel()
 *          Bus::refuel()
 */

#include <iostream>
using namespace std;


// this class acts as a placeholder for methods shared with derived classes.  
// we do not expect to create objects of this class
class Vehicle
{
public:
    void start() { cout << "vehicle starting ..." << endl; }
    void stop() { cout << "vehicle stopping ..." << endl; }
    void refuel() { cout << "vehicle refueling ..." << endl; }
};

class Bus : public Vehicle // inherits 3 methods from Vehicle
{
public:
    void refuel() { cout << "bus refueling ..." << endl; }
};

class Car : public Vehicle // inherits 3 methods from Vehicle
{};

class Van : public Vehicle // inherits 3 methods from Vehicle
{};

// code reuse:  this function can be used by any class derived from Vehicle
void refuelAnyVehicle(Vehicle& x)
{
    // note that the base class method is always called despite passing by Vehicle&
    // this behaviour is undesirable and is fixed by using 'virtual functions' see next chapter on polymorphism
    x.refuel();
}

int main()
{
    Bus b;
    b.start();
    b.refuel();  // note the Bus::refuel() method is called, not Vehicle::refuel()
    b.stop();

    Car c;
    c.start();
    c.refuel();
    c.stop();
    
    Van v;
    v.start();
    v.refuel();
    v.stop();

    // now use the SUBSTITUTION RULE to refuel all 3 vehicles
    refuelAnyVehicle(b);
    refuelAnyVehicle(c);
    refuelAnyVehicle(v);

    // note the following is possible, but doesn't make sense
    // because Vehicle is abstract:

    Vehicle vehicle;
    vehicle.start();
    vehicle.refuel();
    vehicle.stop();
}
