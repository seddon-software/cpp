#include <iostream>
#include <vector>
#include <functional>
using namespace std;

/*  
 *  Another application of callbacks is in the software pattern Pub/Sub (publish and subscribe).
 *  The pattern has a publisher (in our case a TemperaturMonitor) and a number of Observers.  The   
 *  publisher notifies interested parties when an event occurs using a callback.  Typically all the 
 *  observers register with the publisher with an optional condition (in our case the observer 
 *  wants to be notified when the temperature has reached a threshold).
 */

using CALLBACK = std::function<void(double)>;

class TemperatureMonitor
{
public:
	void setTemperature(double current)
	{
		temperature = current;
		if(temperature > 25.0) notifyAll();
	}
	void notifyAll()
	{
		for(auto callback : observerCallbacks)
		{
			callback(temperature);
		}
	}
	void Register(CALLBACK& observerCallback)
	{
		observerCallbacks.push_back(observerCallback);
	}
private:
	vector<CALLBACK> observerCallbacks;
	double temperature;
};

class Observer
{
public:
	Observer(int n)
	{
		callback = [n](double temperature)
				   {
			           cout << "observer " << n << " has been contacted: "
			        		    << temperature << endl;
				   };
	}
	void doRegister(TemperatureMonitor& tm)
	{
		tm.Register(callback);
	}
private:
	CALLBACK callback;
};


int main()
{
	TemperatureMonitor publisher;
	Observer observer1{1};
	Observer observer2{2};
	Observer observer3{3};
	observer1.doRegister(publisher);
	observer2.doRegister(publisher);
	observer3.doRegister(publisher);

	vector<double> temperatures = { 18.0, 21.0, 24.5, 27.3, 26.2, 23.5 };
	for(auto temperature : temperatures)
	{
		publisher.setTemperature(temperature);
	}
}

