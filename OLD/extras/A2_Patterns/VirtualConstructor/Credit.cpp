#include "Credit.hpp"

static Credit creditPrototype = Exemplar();

Credit::Credit(const Exemplar&) 
{ 
	AccountFactory::Register(this); 
}

// virtual CTOR
Credit* Credit::build(const string& type, const string& name)
{
    if(type == (string) "Credit")
       return new Credit(name);
    return 0;
}

Credit* Credit::clone(const string& name) const
{
	return new Credit(name);
}


