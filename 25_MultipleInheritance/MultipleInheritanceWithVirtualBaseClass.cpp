///////////////////////////////////////////////////////////////
//
//		Multiple Inheritance with virtual Base Class
//
///////////////////////////////////////////////////////////////

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

	void Display() 
	{ 
		cout << "Price = " << price << " (address: " << &price << ")" << endl; 
	}
private:
	double price;
};

/////

class Electrical : virtual public StoreItem
{
public:
	Electrical(double p) :StoreItem(p) {}
	
	void Display() 
	{ 
		StoreItem::Display(); 
	}
};

class DIY : virtual public StoreItem
{
public:
	DIY(double p) :StoreItem(p) {}
	
	void Display() 
	{ 
		StoreItem::Display(); 
	}
};

/////

class ElectricalDIY : public Electrical, public DIY
{
public:
	// we initialise StoreItem directly from here
	ElectricalDIY(double p) : StoreItem(p), Electrical(p), DIY(p) {}
	
	void Display() 
	{ 
		Electrical::Display(); 
		DIY::Display(); 
	}
};

/////

int main()
{
	// constructors blank fire for StoreItem 
	ElectricalDIY item(19.99);
	item.DIY::SetPrice(29.99);
	item.Electrical::SetPrice(39.99);
	item.Display();

	// constructors fire normally for StoreItem 
	Electrical e(5.99);
	DIY 	   d(8.99);

	return 0;
}


