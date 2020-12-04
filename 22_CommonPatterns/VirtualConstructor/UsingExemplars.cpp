////////////////////////////////////////////////////////////
//
//		Virtual Construction using Exemplars
//
////////////////////////////////////////////////////////////

#include <iostream>
#include <list>
#include <string>
using namespace std;


class Exemplar{};

class Account
{
private:
	static list<Account*>* exemplars;
protected:
	string name;
public:	
	Account(){}
	Account(const string& n)
		: name(n)
	{}
	static void Register(Account* e)
	{
		if(!exemplars) exemplars = new list<Account*>();
		exemplars->push_back(e);
	}
	
	virtual ~Account() {}
	virtual void get_balance() = 0;
	virtual void deposit() = 0;
	virtual void withdraw() = 0;
	
	// virtual CTOR
	static Account* make(const string& type, const string& name)	// calls build to do the real work
	{
		Account *p;
		list<Account*>::iterator i;
		for(i = exemplars->begin(); i != exemplars->end(); ++i)
		{
			Account& theAccount = **i;
			p = theAccount.build(type, name);
			//p = (*i)->build(type);
			if(p)break;
		}
		return p;
	}

	virtual Account* build(const string&, const string& name) = 0 ;
};

class Deposit : public Account
{
public:
	Deposit(const Exemplar&) 
	{ 
		Account::Register(this); 
	}
	Deposit(const string& n) : Account(n)
	{}
	
	virtual ~Deposit() {}
	virtual void get_balance() {}
	virtual void deposit() {}
	virtual void withdraw() { cout << name << " is withdrawing from Deposit account" << endl; }

	// virtual CTOR
	Deposit* build(const string& type, const string& name)
	{
		if(type == (string)"Deposit")
           return new Deposit(name);
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
	Credit(const string& n) : Account(n)
	{}

	virtual ~Credit() {}
	virtual void get_balance() {}
	virtual void deposit() {}
	virtual void withdraw() { cout << name << " is withdrawing from Credit account" << endl; }

	// virtual CTOR
	Credit* build(const string& type, const string& name)
	{
	    if(type == (string) "Credit")
           return new Credit(name);
        return 0;
	}
};

class Saver : public Account
{
public:
	Saver(const Exemplar&)
	{
		Account::Register(this);
	}
	Saver(const string& n) : Account(n)
	{}

	virtual ~Saver() {}
	virtual void get_balance() {}
	virtual void deposit() {}
	virtual void withdraw() { cout << name << " is withdrawing from Saver account" << endl; }

	// virtual CTOR
	Saver* build(const string& type, const string& name)
	{
	    if(type == (string) "Saver")
           return new Saver(name);
        return 0;
	}
};

static Credit CreditFactory = Exemplar();
static Deposit DepositFactory = Exemplar();
static Saver SaverFactory = Exemplar();
list<Account*>* Account::exemplars;

/////

void takeMoney(Account *a)
{
	a->withdraw();
}

/////

int main()
{
	// complete decoupling
	Account* bruce = Account::make("Deposit", "Bruce");
	takeMoney(bruce);
	
	Account* dave = Account::make("Credit", "Dave");
	takeMoney(dave);

	Account* bridget = Account::make("Saver", "Bridget");
	takeMoney(bridget);
}
