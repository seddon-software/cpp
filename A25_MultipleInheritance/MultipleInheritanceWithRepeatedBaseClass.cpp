///////////////////////////////////////////////////////////////
//
//		Multiple Inheritance with repeated Base Class
//
///////////////////////////////////////////////////////////////

/*
 *  The ElectricalDIY class below multiply inherits from the Electrical and DIY classes.  Each of these 
 *  inherit from the StoreItem class.  This means ElectricalDIY will potentially have two separate 
 *  StoreItem classes.  However this means an ElectricalDIY object will have two prices.  This is the 
 *  default behaviour.  If instead you want the ElectricalDIY object to have a single price you have to
 *  use virtual inheritance.
 * 
 *  In this example we use non virtual inheritance (the default) and allow the ElectricalDIY object to 
 *  have two prices.  This will of course lead to logical difficulties later in the code, so you might 
 *  prefer virtual inheritance (see next example).  Unfortunatey, virtual inheritance has its own 
 *  idiosyncracies.
 *  
 *  Neither system works well - multiple inheritance is well known to be difficult to formulate.
 */

#include <iostream>
using namespace std;

class StoreItem
{
public:
	StoreItem(double p) : price(p) {}
	
	void SetPrice(double p) 
	{
		price = p; 
	}

	void Display(auto parent) 
	{ 
		cout << parent << " price = " << price << " (address: " << &price << ")" << endl; 
	}
private:
	double price;
};

/////

class Electrical : public StoreItem
{
public:
	Electrical(double p) :StoreItem(p) {}
	
	void Display() 
	{ 
		StoreItem::Display("Electrical"); 
	}
};

class DIY : public StoreItem
{
public:
	DIY(double p) :StoreItem(p) {}
	
	void Display() 
	{ 
		StoreItem::Display("DIY"); 
	}
};


/////

class ElectricalDIY : public Electrical, public DIY
{
public:
	ElectricalDIY(double p) : Electrical(p),DIY(p) {}
	
	void Display() 
	{ 
		Electrical::Display(); 
		DIY::Display(); 
	}
};

/////

int main()
{
    cout << "Using non-virtual multiple inheritance" << endl;
    cout << "item has 2 separate prices" << endl;
	ElectricalDIY item(19.99);
	item.DIY::SetPrice(29.99);
	item.Electrical::SetPrice(39.99);
	item.Display();
}


