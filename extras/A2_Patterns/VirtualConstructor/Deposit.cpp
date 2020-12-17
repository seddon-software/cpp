#include "Deposit.hpp"

static Deposit depositPrototype = Exemplar();


Deposit::Deposit(const Exemplar&) 
{ 
	AccountFactory::Register(this); 
}

Deposit* Deposit::build(const string&type, const string& name)
{
	if(type == (string)"Deposit")
       return new Deposit(name);
    return 0;
}

Deposit* Deposit::clone(const string& name) const
{
	return new Deposit(name);
}

