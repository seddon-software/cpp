#include "futures.h"

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
    HANDLE* handles = new HANDLE[pool.size()];

    for(unsigned i = 0; i < pool.size(); i++)
    {
        handles[i] = pool[i]->getHandle();
    }

    WaitForMultipleObjects(3, handles, true, INFINITE);

    int result = 0;
    for(unsigned i = 0; i < pool.size(); i++)
    {
        result += pool[i]->result();
    }
    return result;
}
