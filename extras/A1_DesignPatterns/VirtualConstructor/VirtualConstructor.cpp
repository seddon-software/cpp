////////////////////////////////////////////////////////////
//
//		Virtual Construction using Exemplars
//
////////////////////////////////////////////////////////////

#include <list>
#include <string>
using namespace std;


class Exemplar{};   // dummy class to trigger registration

//////////
// Account hierarchy
//////////

class Account
{
private:
	static list<Account*>* exemplars;
	string name;
public:	
    Account(){}
    Account(const string& n): name(n) {}	
    virtual ~Account() {}

    static void Register(Account* e);
    static Account* make(const string& type, const string& name); // virtual CTOR
    virtual Account* build(const string& type, const string& name) = 0 ;

    // normal interface
    virtual void get_balance() = 0;
    virtual void deposit() = 0;
    virtual void withdraw() = 0;
};

class Deposit : public Account
{
public:
	Deposit(const Exemplar&) 
	{ 
		Account::Register(this); 
	}
	Deposit(const string& n) : Account(n) {}
	
	virtual ~Deposit() {}
	virtual void get_balance() {}
	virtual void deposit() {}
	virtual void withdraw() {}

	// virtual CTOR
	Deposit* build(const string&type, const string& name)
	{
		if(type == (string)"Deposit")
           return new Deposit(name);
        return 0;
	}
};

class HiInterest: public Account
{
public:
	HiInterest(const Exemplar&) 
	{ 
		Account::Register(this); 
	}
	HiInterest(const string& n) : Account(n) {}
	
	virtual ~HiInterest() {}
	virtual void get_balance() {}
	virtual void deposit() {}
	virtual void withdraw() {}

	// virtual CTOR
	HiInterest* build(const string& type, const string& name)
	{
		if(type == (string)"HiInterest")
           return new HiInterest(name);
        return 0;
	}
};

class Credit : public Account
{
public:
	Credit(const Exemplar&) 
	{ 
		Account::Register(this); 
	}
	Credit(const string& n) : Account(n) {}
	virtual ~Credit() {}
	virtual void get_balance() {}
	virtual void deposit() {}
	virtual void withdraw() {}

	// virtual CTOR
	Credit* build(const string& type, const string& name)
	{
	    if(type == (string) "Credit")
           return new Credit(name);
        return 0;
	}
};

// definitions of statics
static Deposit depositPrototype = Exemplar();
static HiInterest hiInterestPrototype = Exemplar();
static Credit creditPrototype = Exemplar();
list<Account*>* Account::exemplars;

// method implementations
void Account::Register(Account* e)
{
	if(!exemplars) exemplars = new list<Account*>();
	exemplars->push_back(e);
}

Account* Account::make(const string& type, const string& name)	// delegates to build
{
	Account *p;
	list<Account*>::iterator i;
	for(i = exemplars->begin(); i != exemplars->end(); ++i)
	{
		p = (*i)->build(type, name);
		if(p)break;
	}
	return p;
}


/////

void takeMoney(Account *a)
{
	a->withdraw();
}

/////

int main()
{
    Account* sue = Account::make("Credit", "Sue");
    Account* dave = Account::make("HiInterest", "Dave");
    Account* bruce = Account::make("Deposit", "Bruce");

    takeMoney(sue);
    takeMoney(dave);
    takeMoney(bruce);
}
