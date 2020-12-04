#include <iostream>
#include <string>
using namespace std;

struct Message
{
	Message(int id) : id(id) {}
	int id;
};

static Message message1(1);
static Message message2(2);
static Message message3(3);
static Message message4(4);
static Message message5(5);

class StateMachine
{
	// forward references
	class State;
	class State1;
	class State2;
	class State3;
	class State4;

	// friends
	friend class State1;
	friend class State2;
	friend class State3;
	friend class State4;
private:

	// 5 possible messages to handle in the various states
	class State
	{
	public:
		virtual State* onMessage(StateMachine& machine) = 0;
	};

	class State1 : public State
	{
	public:
		virtual State* onMessage(StateMachine& machine)
		{
			Message& message = *machine.pMessage;;

			switch(message.id)
			{
				case 1: 
					cout << "State 1 -> 2" << endl; 
					return &machine.state2;
				case 5: 
					cout << "State 1 -> 3" << endl;
					return &machine.state3;
			}
			return 0;
		}
	};

	class State2 : public State
	{
	public:
		virtual State* onMessage(StateMachine& machine)
		{
			Message& message = *machine.pMessage;;

			switch(message.id)
			{
				case 3: 
					cout << "State 2 -> 3" << endl; 
					return &machine.state3;
				case 4: 
					cout << "State 2 -> 1" << endl;
					return &machine.state1;
			}
			return 0;
		}
	};

	class State3 : public State
	{
	public:
		virtual State* onMessage(StateMachine& machine)
		{
			Message& message = *machine.pMessage;;

			switch(message.id)
			{
				case 1: 
					cout << "State 3 -> 1" << endl; 
					return &machine.state1;
				case 5: 
					cout << "State 3 -> 4" << endl;
					return &machine.state4;
			}
			return 0;
		}
	};

	class State4 : public State
	{
	public:
		virtual State* onMessage(StateMachine& machine)
		{
			Message& message = *machine.pMessage;;

			switch(message.id)
			{
				case 2: 
					cout << "State 4 -> 2" << endl; 
					return &machine.state2;
				case 4: 
					cout << "State 4 -> 3" << endl;
					return &machine.state3;
			}
			return 0;
		}
	};

	State1 state1;
	State2 state2;
	State3 state3;
	State4 state4;
	State* currentState;
	Message* pMessage;
public:
	StateMachine() : 
	    currentState(&state1), pMessage(0)
	{}

	void doit(Message& message)
	{
		pMessage = &message;
		currentState = currentState->onMessage(*this);
	}
};




int main()
{
	StateMachine stateMachine;
	stateMachine.doit(message1);
	stateMachine.doit(message3);
	stateMachine.doit(message5);
	stateMachine.doit(message2);
	stateMachine.doit(message4);
	stateMachine.doit(message5);
	stateMachine.doit(message5);
}
