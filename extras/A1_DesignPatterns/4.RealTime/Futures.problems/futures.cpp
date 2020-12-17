#include "futures.h"
#include "thread.h"
using namespace std;


void Futures::request(thread* t)
{
    pool.push_back(t);
}

void Futures::start()
{
    for(unsigned i = 0; i < pool.size(); i++)
    {
        pool[i]->start();
    }
}

int Futures::getResult()
{
    int* handles = new int[pool.size()];

    for(unsigned i = 0; i < pool.size(); i++)
    {
        handles[i] = pool[i]->getId();
    }

    WaitForMultipleObjects(pool.size(), handles, true, INFINITE);

    int result = 0;
    for(unsigned i = 0; i < pool.size(); i++)
    {
        result += pool[i]->result();
    }
    return result;
}
