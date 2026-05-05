#include "IRManager.h"

void IRManager::begin()
{
    irrecv.enableIRIn();
}

void IRManager::update()
{
    if(irrecv.decode(&results))
    {
        irrecv.resume();
    }
}