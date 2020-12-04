#include <iostream>
#include <vector>
#include <functional>
using namespace std;

using CALLBACK_TYPE = std::function<void(double)>;

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
	void Register(CALLBACK_TYPE& observerCallback)
	{
		observerCallbacks.push_back(observerCallback);
	}
private:
	vector<CALLBACK_TYPE> observerCallbacks;
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
	CALLBACK_TYPE callback;
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

