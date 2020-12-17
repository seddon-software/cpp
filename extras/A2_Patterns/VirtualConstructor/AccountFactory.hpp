#ifndef ACCOUNTFACTORY_H
#define ACCOUNTFACTORY_H

#include <list>
#include <string>
#include "Account.hpp"

using namespace std;


class Exemplar{};   // dummy class to trigger registration

class IAccountFactory
{
public:
    virtual Account* build(const string& type, const string& name) = 0 ;
	virtual Account* clone(const string& name) const = 0;
};

class AccountFactory : public IAccountFactory
{
private:
	static list<Account*>* exemplars;
public:	
    static void Register(Account* e);
    static Account& make(const string& type, const string& name); // virtual CTOR
	static Account& clone(const Account& original, const string& name);
};


#endif
