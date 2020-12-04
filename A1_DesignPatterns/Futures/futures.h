#ifndef FUTURES_H
#define FUTURES_H

#include <vector>
#include "thread.h"
using namespace std;


class Futures
{
public:
    void request(thread* t);
    void start();
    int getResult();
private:
    vector<thread*> pool;
};


#endif
