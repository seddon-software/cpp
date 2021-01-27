/*  
 *  In C++ when we use inheritance, derived classes inherit all the methods from
 *  their base class.  In this example Bus, Car and Van all inherit the methods
 *  start(), refuel() and stop().
 *  Note that you must use public inheritance (protected and private inheritance are
 *  more closely aligned with composition).  Methods in the base class usually have
 *  parameters (I've left them out in this example to keep things simple).
 */

class Vehicle
{
public:
    void start() {}
    void stop() {}
    void refuel() {}
};

class Bus : public Vehicle
{};

class Car : public Vehicle
{};

class Van : public Vehicle
{};

int main()
{
    Bus b;
    Car c;
    Van v;

    b.start();
    b.refuel();
    b.stop();

    c.start();
    c.refuel();
    c.stop();
    
    v.start();
    v.refuel();
    v.stop();

    // note the following is possible, but doesn't make sense:
    // Vehicle vehicle;
    // vehicle.start();
    // vehicle.refuel();
    // vehicle.stop();
}
