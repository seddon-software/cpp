////////////////////////////////////////////////////////////
//
//		State
//
////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
using namespace std;

enum State { STATE_0, STATE_1, STATE_2, STATE_END = -1 };
enum Event { EVENT_0, EVENT_1, EVENT_2, AUTO_EVENT, EVENT_END = -1 };
enum Type  { MANUAL,  AUTO, TYPE_END = -1 };

void ACTION_0() { cout << "action 0" << endl; }
void ACTION_1() { cout << "action 1" << endl; }
void ACTION_2() { cout << "action 2" << endl; }
void ACTION_3() { cout << "action 3" << endl; }

struct StateTableEntry
{
	State old_state;
	Event event;
	State new_state;
	void (*pAction)();
};

StateTableEntry state_table[] =
{
	// state can only have 1 auto event (=> no manual transitions)
	// prev      event       next         action	type
	{ STATE_0,	EVENT_1,	STATE_1,	ACTION_0 },
	{ STATE_1,	AUTO_EVENT,	STATE_2,	ACTION_1 },
	{ STATE_2,	EVENT_0,	STATE_1,	ACTION_2 },
	{ STATE_2,	EVENT_2,	STATE_0,	ACTION_3 },
	{ STATE_END, EVENT_END, STATE_END,	0,		 }
};

class StateEngine
{
public:
	StateEngine(State initialState) : currentState(initialState) {}
	void DoEvent(int event);
	void CheckForAutoEvents();
private:
	State currentState;
};

void StateEngine::CheckForAutoEvents()
{
	DoEvent(AUTO_EVENT);	// won't fire if auto event doesn't exist
}

void StateEngine::DoEvent(int event)
{
	// state doesn't change if no corresponding entry in state table
	for(int i = 0; state_table[i].old_state != STATE_END; i++)
	{
		if(state_table[i].old_state == currentState && state_table[i].event == event)
		{
			// state transition found
			state_table[i].pAction();
			currentState = state_table[i].new_state;
			CheckForAutoEvents();
			break;
		}
	}
}


int main()
{
	StateEngine engine(STATE_0);
	engine.DoEvent(EVENT_1);
	engine.DoEvent(EVENT_1);
	engine.DoEvent(EVENT_0);
	engine.DoEvent(EVENT_1);
	engine.DoEvent(EVENT_2);
}



