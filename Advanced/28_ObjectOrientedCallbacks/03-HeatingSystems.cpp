////////////////////////////////////////////////////////////
//
//		Command Pattern
//
////////////////////////////////////////////////////////////

// Original example developed by Kevlin Henney

/*
The Command pattern is designed to decouple a request for an operation from its execution.  An operation is defined in
terms of an object bound to a method; a separate class is used to record this information.

In this example, the load_event method records several operations (function pointer) in a vector along with the times
when the callback is to be made.  The fire_events method decides whether or not to execute the request.

If a system is to model several different events then the simplest approach is to define a separate class for each event.
Of course the class must implement the Command interface.  The example defines two events: turn_off and turn_on a
heating system.  These events are modelled by the HeatingOff and HeatingOn classes respectively.

The main programme creates the event objects and a Timer object is used to record the events and timings.  The simulation
sets off the timer and events are fired at various times.
*/

#include <string>
#include <vector>
#include <iostream>
using namespace std;

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
// command hierarchy
//
//                        Command
//                           ^
//             ______________|____________________
//            |                        |          |
//	       HeatingOn     HeatingOff            Service
/////

class Command
{
public:
    virtual void execute() = 0;
};

class HeatingOn : public Command
{
public:
	HeatingOn(HeatingSystem* t) : target(t) {}

	virtual void execute()
	{
		target->turn_on();
	}
private:
	HeatingSystem* target;
};

class HeatingOff : public Command
{
public:
	HeatingOff(HeatingSystem* t) : target(t) {}

	virtual void execute()
	{
		target->turn_off();
	}
private:
	HeatingSystem* target;
};

class Service : public Command
{
public:
	Service(HeatingSystem* t) : target(t) {}

	virtual void execute()
	{
		target->service();
	}
private:
	HeatingSystem* target;
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
			if(times[i] == clock)
			{
				events[i]->execute();
			}
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

	HeatingOn onA(&systemA), onB(&systemB);
	HeatingOff offA(&systemA), offB(&systemB);
	Service serviceA(&systemA), serviceB(&systemB);

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

	return 0;
}

