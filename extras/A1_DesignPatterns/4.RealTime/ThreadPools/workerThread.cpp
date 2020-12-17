#include "workerThread.h"

workerThread::workerThread(executor& e) : ex(e) {}

int workerThread::run() 
{
	while(true)
	{
		functor* fp = ex.getJob();
		if(fp)
		{
			functor& f = *fp;
			f();	// perform job
		}
		Sleep(100);
	}

	return 0; 
}
