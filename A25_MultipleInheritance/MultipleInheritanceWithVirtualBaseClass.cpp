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
	StoreItem(double p) : price(p) 
    {
        cout << "StoreItem CTOR" << endl;
    }
	
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
	Electrical(double p) :StoreItem(p) 
    {
        cout << "Electrical CTOR" << endl;
        cout << "virtual base class StoreItem CTOR not called for diamond hierachy" << endl;
    }
	
	void Display() 
	{ 
		StoreItem::Display(); 
	}
};

class DIY : virtual public StoreItem
{
public:
	DIY(double p) :StoreItem(p) 
    {
        cout << "DIY CTOR" << endl;
        cout << "virtual base class StoreItem CTOR not called for diamond hierachy" << endl;
    }
	
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
	ElectricalDIY(double p) : StoreItem(p), Electrical(p), DIY(p) 
    {
        cout << "ElectricalDIY CTOR" << endl;
        cout << "base class StoreItem CTOR was called from here" << endl;
    }
	
	void Display() 
	{ 
        cout << "object only contains a single price component" << endl;
		Electrical::Display(); 
		DIY::Display(); 
	}
};

/////

int main()
{
    cout << "      ElectricalDIY" << endl;
    cout << "        |        |" << endl;
    cout << "    Electrical  DIY" << endl;
    cout << "         \\      /" << endl;
    cout << "            |" << endl;
    cout << "         StoreItem" << endl;
    
    cout << "Using virtual multiple inheritance" << endl;
    cout << "item has only one price" << endl;

	// StoreItem constructors fire from 2 classes away for item  
	ElectricalDIY item(19.99);
	item.DIY::SetPrice(29.99);
	item.Electrical::SetPrice(39.99);
	item.Display();

	cout << "\nStoreItem constructors will fire normally for these objects" << endl;  
	Electrical e(5.99);
	DIY 	   d(8.99);
}


