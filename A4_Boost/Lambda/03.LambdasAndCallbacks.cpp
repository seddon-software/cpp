////////////////////////////////////////////////////////////
//
//		Lambda
//
////////////////////////////////////////////////////////////


#include <iostream>
#include <string>
#include <boost/function.hpp>
#include <boost/lambda/bind.hpp>
#include <boost/lambda/lambda.hpp>

using namespace std;
using namespace boost::lambda;

typedef boost::function<string(const string&, const string&)> FP;

class Button
{
public:    
    void onPress(const string& name, const FP& callbackFunction)
    {
        this->name = name;
        this->callbackFunction = callbackFunction;
    }
    string press()
    {
        return callbackFunction(name, string(" pressed ")); // _1 and _2
    }
private:
    string name;
    FP callbackFunction;
};

/////


int main()
{
    Button button1;
    Button button2;
    Button button3;

    // register callback functions for each button
    button1.onPress("button 1", ret<string>(_1 + ":" + _2));  // this does compile
    // this defines a lambda:
    	// string lambda_function(string _1, string _2)
    	// {
    	//   return _1 + ":" + _2
    	// }
    button2.onPress("button 2", ret<string>(_2 + _1));    
    button3.onPress("button 3", _1);    

    // Simulation
    cout << button2.press() << endl;    
    cout << button3.press() << endl;    
    cout << button1.press() << endl;    
    cout << button2.press() << endl;    
    cout << button1.press() << endl;    
    cout << button2.press() << endl;    
    cout << button3.press() << endl;    
    cout << button3.press() << endl;    
    cout << button1.press() << endl;    

    return 0;
}
