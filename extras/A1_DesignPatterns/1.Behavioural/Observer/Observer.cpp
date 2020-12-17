////////////////////////////////////////////////////////////
//
//		Observer
//
////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class IObserver
{
public:
	virtual void Callback(string state) = 0; 
};



class ISubject
{
public:
	virtual void Register(IObserver* pObserver) = 0; 
	virtual void UnRegister(IObserver* pObserver) = 0; 
	virtual void Notify() = 0;
};

class ConcreteSubject : public ISubject
{
public:
	virtual void Register(IObserver* pObserver)
	{
		observers.push_back(pObserver);
	}
	
	virtual void UnRegister(IObserver* pObserver)
	{
		vector<IObserver*>::iterator iObserver = observers.begin();
		
		while( iObserver != observers.end())
		{
			if (pObserver == *iObserver)
			{
				observers.erase(iObserver);
			}
			iObserver++;
		}		
	}
	
	virtual void Notify()
	{
		vector<IObserver*>::iterator iObserver = observers.begin();
		
		while( iObserver != observers.end())
		{
			IObserver& theObserver = **iObserver;
			theObserver.Callback(state);
			iObserver++;
		}
	}
private:
	vector<IObserver*> observers;
	string state;
};



class ConcreteObserver : public IObserver
{
public:
	ConcreteObserver(string id) : id(id) {}  
	virtual void Callback(string state) 
	{
		cout << "callback for: " << id << endl;
	}
private:
	string id;
};


////////////////////////////////////////////////////////////

int main()
{
	ConcreteSubject publisher;
	ConcreteObserver subscriber1("1");
	ConcreteObserver subscriber2("2");
	ConcreteObserver subscriber3("3");
	
	publisher.Register(&subscriber1);
	publisher.Register(&subscriber2);
	publisher.Register(&subscriber3);

	publisher.Notify();
	
	publisher.UnRegister(&subscriber2);
	
	publisher.Notify();	
}
