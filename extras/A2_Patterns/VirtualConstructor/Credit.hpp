#ifndef CREDIT_H
#define CREDIT_H

#include "Account.hpp"
#include "AccountFactory.hpp"

class Credit : public Account, public IAccountFactory
{
public:
	Credit(const Exemplar&);
	Credit(const string& n) : Account(n) {}
	virtual ~Credit() {}
	virtual Credit* clone(const string& name) const;
	virtual void get_balance() {}
	virtual void deposit() {}
	virtual void withdraw() {}

	// virtual CTOR
	Credit* build(const string& type, const string& name);
};

#endif
