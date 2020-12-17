#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <boost/tuple/tuple.hpp>

using namespace std;
using namespace boost;

namespace StateMachine
{
	struct State 
	{
		State(int id) : id(id) {}
		int id;
	};

	struct Message
	{
		Message(int id) : id(id) {}
		int id;
	};

	typedef void (*PF)(Message& message);

	struct Action
	{
		Action(PF message) : message(message) {}
		PF message;
	};

	typedef boost::tuple<Message&, State&, State&, Action> TUPLE;

	struct Query
	{
		Query(State currentState, Message message)
			: currentState(currentState),
		      message(message)
		{}

		bool operator() (const TUPLE& t)
		{
			Message& candidateMessage = get<0>(t);
			State& entryState = get<1>(t);
			if(candidateMessage.id != this->message.id) return false;
			if(entryState.id != this->currentState.id) return false;
			return true;
		}

		State currentState;
		Message message;
	};

	class Machine
	{
	public:
		vector<TUPLE> list;
		Machine(State& initialState)
		{
			pCurrentState = &initialState;
		}
		void Register(TUPLE& t)
		{
			list.push_back(t);
		}
		void doit(Message& message)
		{
			Query q(*pCurrentState, message);
			vector<TUPLE>::iterator i;
			i = find_if(list.begin(), list.end(), q);

			if(i != list.end())
			{
				Action& action = get<3>(*i);
				State& newState = get<2>(*i);
				cout << "States: " << pCurrentState->id
					<< "=>"       << newState.id << " : ";
				action.message(message);
				pCurrentState = &newState;
			}
		}
		State* pCurrentState;
	};
}

using namespace StateMachine;

void f1(Message& message)
{
	cout << "f1:message " << message.id << endl;
}

void f2(Message& message)
{
	cout << "f2:message " << message.id << endl;
}

void f3(Message& message)
{
	cout << "f3:message " << message.id << endl;
}

int main()
{
	Message message1(100), message2(200), message3(300);
	State state1(1), state2(2), state3(3);
	Action action1(f1), action2(f2), action3(f3);
	Machine machine(state1);

	TUPLE t1(message1, state1, state2, action1);
	TUPLE t2(message2, state2, state3, action1);
	TUPLE t3(message3, state3, state1, action2);
	TUPLE t4(message2, state3, state1, action3);
	TUPLE t5(message3, state1, state3, action2);
	machine.Register(t1);
	machine.Register(t2);
	machine.Register(t3);
	machine.Register(t4);
	machine.Register(t5);
							 // start in state1
	machine.doit(message1);  // action1,goto state2
	machine.doit(message2);  // action1,goto state3
	machine.doit(message3);  // action2,goto state1
	machine.doit(message3);  // action2,goto state3
	machine.doit(message2);  // action1,goto state1

}
