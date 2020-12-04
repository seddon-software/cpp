#ifndef DEPOSIT_H
#define DEPOSIT_H

#include "Account.hpp"
#include "AccountFactory.hpp"

class Deposit : public Account, public IAccountFactory
{
public:
	Deposit(const Exemplar&);
	Deposit(const string& n) : Account(n) {}
	virtual ~Deposit() {}
	virtual Deposit* clone(const string& name) const;
	virtual void get_balance() {}
	virtual void deposit() {}
	virtual void withdraw() {}

	// virtual CTOR
	Deposit* build(const string&type, const string& name);
};


#endif
