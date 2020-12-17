#ifndef HIINTEREST_H
#define HIINTEREST_H

#include "Account.hpp"
#include "AccountFactory.hpp"

class HiInterest: public Account, public IAccountFactory
{
public:
	HiInterest(const Exemplar&);
	HiInterest(const string& n) : Account(n) {}
	virtual ~HiInterest() {}
	virtual HiInterest* clone(const string& name) const;
	virtual void get_balance() {}
	virtual void deposit() {}
	virtual void withdraw() {}

	// virtual CTOR
	HiInterest* build(const string& type, const string& name);
};

#endif
