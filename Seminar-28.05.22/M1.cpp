#include <mutex>
using namespace std;

mutex mtxR;
mutex mtxW;

int readers = 0;

void read()
{
    mtxR.lock();

    ++readers;
    if (readers == 1)
        mtxW.lock();
    mtxR.unlock();

    //reading data

    mtxR.lock();

    --readers;
    if (readers == 0)
        mtxW.unlock();

    mtxR.unlock();
}

void write()
{
    mtxW.lock();
    
    //writing data

    mtxW.unlock();
}
