////////////////////////////////////////////////////////////
//
//		Command Pattern
//
////////////////////////////////////////////////////////////

#include <string>
#include <vector>
#include <functional>
#include <iostream>
#include "demangle.h"
#include <functional>
using namespace std;

/*
 *  bind_front is intended as a replacement for bind; using bind_front should simplify code.  Here we 
 *  revisit the HeatingSystemWithAdapters example from the previous chapter to check this out.  IMHO
 *  it looks simpler to me.
 */

class Time
{
public:
	Time(int t) : ticks(t) {}
	operator int() { return ticks; }
	bool operator<(Time& t) { return ticks < t; }
	void operator++() { ticks++; }
private:
	int ticks;
};

class HeatingSystem
{
public:
	HeatingSystem(string name) : name(name) {}
	void turn_on()	{ cout << "turn on:" << name; }
	void turn_off() { cout << "turn off:" << name; }
	void service()  { cout << "service:" << name; }
private:
	string name;
};

class TimerController
{
public:
    TimerController(int max):max(max){}
	bool tick()
	{
		cout << endl << clock << ": ";
		++clock;
		fire_events();
		return clock < max;
	}
	void fire_events()
	{
		for(int i = 0; i < (int)events.size(); i++)
		{
            if(times[i] == clock) events[i]();
		}
	}
    void set(auto time, auto event)
    {
        events.push_back(event);
        times.push_back(time);
    }
private:
	Time clock = 0;
	Time max;
    using BF = std::_Bind_front<void (HeatingSystem::*)(), HeatingSystem*>;
    vector<BF> events;
	vector<Time> times;
};

/////

int main()
{
	HeatingSystem systemA("A"), systemB("B");
    TimerController controller{12};

	controller.set( 4, bind_front(&HeatingSystem::turn_on,  &systemA));
	controller.set( 8, bind_front(&HeatingSystem::turn_off, &systemA));
	controller.set(10, bind_front(&HeatingSystem::service,  &systemA));
	controller.set( 2, bind_front(&HeatingSystem::turn_on,  &systemB));
	controller.set( 3, bind_front(&HeatingSystem::turn_off, &systemB));
	controller.set( 7, bind_front(&HeatingSystem::turn_on,  &systemB));
	controller.set( 8, bind_front(&HeatingSystem::turn_off, &systemB));
	controller.set(11, bind_front(&HeatingSystem::service,  &systemB));

	cout << "start of simulation";
	while(controller.tick());
	cout << endl << "end of simulation" << endl;
}

