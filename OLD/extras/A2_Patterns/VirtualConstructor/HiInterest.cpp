#include "HiInterest.hpp"

static HiInterest hiInterestPrototype = Exemplar();

HiInterest::HiInterest(const Exemplar&) 
{ 
	AccountFactory::Register(this); 
}

HiInterest* HiInterest::build(const string& type, const string& name)
{
	if(type == (string)"HiInterest")
       return new HiInterest(name);
    return 0;
}

HiInterest* HiInterest::clone(const string& name) const
{
   return new HiInterest(name);
}

