///////////////////////////////////////////////////////////////
//
//		Bridge
//
///////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <vector>
using namespace std;

/////
// logging hierarchy
/////

class logging
{
public:
	virtual void write(const string& s) = 0;
};

class file_logging : public logging
{
public:
	virtual void write(const string& s) 
	{ 
		cout << "file: " << s << endl; 
	}
};

class terminal_logging : public logging
{
public:
	virtual void write(const string& s) 
	{ 
		cout << "terminal: " << s << endl; 
	}
};

class null_logging : public logging
{
public:
	virtual void write(const string& s) 
	{ 
		cout << "null:" << endl; 
	}
};

/////
// service hierarchy
/////

class service
{
public:
	service() : log(new null_logging)
	{}

	~service()
	{
		delete log;
	}

	void trace(logging* ptr)
	{
		delete log;
		log = ptr;
	}

	void shutdown()
	{
		log->write("shutdown");
	}

protected:
	logging* log;	// point to polymorphic logging class
};

class http: public service
{
public:
	void get() 
	{ 
		log->write("http get");
	}

	void put() 
	{ 
		log->write("http put");
	}
};

class ftp: public service
{
public:
	void get() 
	{ 
		log->write("ftp get");
	}

	void put() 
	{ 
		log->write("ftp put");
	}
};

/////

int main()
{
	http service1;
	ftp  service2;

	service1.get();
	service1.put();
	service1.trace(new file_logging);
	service1.get();
	service1.put();
	service1.get();
	service1.put();
	service1.shutdown();

	service2.get();
	service2.put();
	service2.trace(new file_logging);
	service2.get();
	service2.put();
	service2.trace(new terminal_logging);
	service2.get();
	service2.put();
	service2.shutdown();

	return 0;
}
