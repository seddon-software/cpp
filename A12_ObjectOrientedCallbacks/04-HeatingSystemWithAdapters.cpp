////////////////////////////////////////////////////////////
//
//		Command Pattern
//
////////////////////////////////////////////////////////////

#include <string>
#include <vector>
#include <iostream>
using namespace std;

/* The previous Command Pattern example shows how this pattern can be used to good effect, but it is 
 * unfortunate that each event is represented by a separate class.  Obviously, in some situations 
 * this could lead to an explosion of event classes.
 * 
 * A refinement of this pattern is to use a CommandAdaptor which dynamically selects the action and 
 * thereby removes the necessity for having a separate class per event.  This is achieved by defining
 * a Heating class for each event represented as a separate method, rather than having separate 
 * HeatingOff, HeatingOn and HeatingService classes.  The CommandAdaptor constructor records the 
 * Heating object and the action (on, off or service) and the callback is made with either an 
 * execute() method or with the operator()() method.  It has become a tradition in C++ to prefer 
 * the overloaded () for the command pattern.
 * 
 * We can define separate CommandAdaptor objects to represent the callbacks:
 *     object "on" represents a callback on the object system with the method Heating::turn_on()
 *     object "off" represents a callback on the object system with the method Heating::turn_off()
 *     object "service" represents a callback on the object system with the method Heating::turn_service()
 * 
 * Clearly we can introduce further Heating objects if required.
 */

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

/////
// hierarchy
//
//                        Command
//                           ^
//                           |
//					   CommandAdapter
//
//             ______________=_____________
//             =             =             =
//	       HeatingOn     HeatingOff     Service		(CommandAdapter objects)
/////

class Command
{
public:
	virtual void execute() = 0;
};

class CommandAdapter : public Command
{
public:
	using FUNCTION_PTR = void (HeatingSystem::*)();
	//typedef void (HeatingSystem::*FP)();

	CommandAdapter(FUNCTION_PTR action, HeatingSystem* system) : action(action), system(system) {}

	virtual void execute()
	{
		(system->*action)();  // both object and method selected at runtime
	}

private:
	FUNCTION_PTR action;
	HeatingSystem* system;
};




/////

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


class TimerController
{
public:
	TimerController(int max) : clock(0), max(max) {}

	void set(Time when, Command* what) 
	{
		events.push_back(what);
		times.push_back(when);
	}

	bool tick()
	{
		cout << endl << clock << ": ";
		++clock;
		fire_events();
		return clock < max;
	}
private:
	void fire_events()
	{
		for(int i = 0; i < (int)events.size(); i++)
		{
			if(times[i] == clock) events[i]->execute();
		}
	}

	vector<Command*> events;
	vector<Time>	 times;
	Time clock;
	Time max;
};

/////

int main()
{
	HeatingSystem systemA("A"), systemB("B");
	TimerController	controller(12);

	CommandAdapter onA	   (&HeatingSystem::turn_on,  &systemA);
	CommandAdapter offA    (&HeatingSystem::turn_off, &systemA);
	CommandAdapter serviceA(&HeatingSystem::service,  &systemA);
	CommandAdapter onB	   (&HeatingSystem::turn_on,  &systemB);
	CommandAdapter offB    (&HeatingSystem::turn_off, &systemB);
	CommandAdapter serviceB(&HeatingSystem::service,  &systemB);

	controller.set(4, &onA);
	controller.set(8, &offA);
	controller.set(10, &serviceA);
	controller.set(2, &onB);
	controller.set(3, &offB);
	controller.set(7, &onB);
	controller.set(8, &offB);
	controller.set(11, &serviceB);

	cout << "start of simulation";
	while(controller.tick());
	cout << endl << "end of simulation" << endl;
}

