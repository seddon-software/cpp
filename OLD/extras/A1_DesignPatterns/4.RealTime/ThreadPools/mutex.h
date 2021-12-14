#include "mutex_impl.h"
using namespace std;



class Mutex
{
public:
	Mutex();
	~Mutex();
	void lock();
	void unlock();
private:
	MutexImpl* pMutexImpl;
};



