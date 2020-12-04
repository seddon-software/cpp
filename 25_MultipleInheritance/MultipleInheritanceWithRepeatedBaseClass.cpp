///////////////////////////////////////////////////////////////
//
//		Multiple Inheritance with repeated Base Class
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

class Electrical : public StoreItem
{
public:
	Electrical(double p) :StoreItem(p) {}
	
	void Display() 
	{ 
		StoreItem::Display(); 
	}
};

class DIY : public StoreItem
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
	ElectricalDIY item(19.99);
	item.DIY::SetPrice(29.99);
	item.Electrical::SetPrice(39.99);
	item.Display();

	return 0;
}


