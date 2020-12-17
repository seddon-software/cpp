#include "AccountFactory.hpp"


list<Account*>* AccountFactory::exemplars;

void AccountFactory::Register(Account* e)
{
	if(!exemplars) exemplars = new list<Account*>();
	exemplars->push_back(e);
}

Account& AccountFactory::make(const string& type, const string& name)	// delegates to build
{
	Account *p;
	list<Account*>::iterator i;
	for(i = exemplars->begin(); i != exemplars->end(); ++i)
	{
		// exemplars are Account objects, but we
		// want to call build (defined in the factory)
		// so we have to cast to IAccountFactory&
		IAccountFactory& af = dynamic_cast<IAccountFactory&>(**i);
		p = af.build(type, name);
		if(p)break;
	}
	return *p;
}

Account& AccountFactory::clone(const Account& original, const string& name)
{
	// original is an Account object, but we
	// want to call clone (defined in the factory)
	// so we have to cast to IAccountFactory&
	const IAccountFactory& af = dynamic_cast<const IAccountFactory&>(original);
	return *af.clone(name);
}
