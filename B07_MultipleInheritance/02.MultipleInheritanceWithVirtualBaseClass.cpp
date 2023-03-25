///////////////////////////////////////////////////////////////
//
//		Multiple Inheritance with virtual Base Class
//
///////////////////////////////////////////////////////////////


/*
 *  In an attempt to avoid repeated based classes, C++ allows us to use virtual inheritance.  In this
 *  case the StoreItem class is only inherited once and its components (price) are not repeated as in
 *  the previous example.  However, initialization now becomes a problem.  Normally a derived class
 *  will initialize its immediate base class, but if that were the case StoreItem would be initialized 
 *  twice.  So with virtual inheritance the derived classes don't call the base constructor at and 
 *  instead leave the initialization to their super class, ElectricalDIY.  
 * 
 *           ElectricalDIY
 *              /    \
 *            /        \
 *        Electrical    DIY
 *            \         /
 *              \     /
 *            StoreItem (virtual)
 * 
 *  Although the Electrical and DIY classes have code to initialize their base classes, the compiler only
 *  generates these call if we are not in a "Diamond" inheritance hierarchy.  If you step through the code 
 *  below, you will notice the StoreItem constructor is called from the ElectricalDIY class and not from
 *  Electrical and DIY.  However, when we create Electrical and DIY objects, the StoreItem constructor is
 *  indeed called, because these objects are not part of a "Diamond" inheritance hierarchy.
 *
 *
 */

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
    cout << "           /  \\" << endl;
    cout << "         /      \\" << endl;
    cout << "    Electrical  DIY" << endl;
    cout << "         \\      /" << endl;
    cout << "           \\  /" << endl;
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


