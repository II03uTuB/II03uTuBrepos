#include "Soldier.h"


 unsigned int countDestructors = 0;


Soldier::Soldier() : _jobCount(0) 
{
    ++countDestructors;
}

void Soldier::Serve()
{
    ++_jobCount;
}

unsigned int Soldier::getServe() 
{
    return _jobCount;
}

Soldier::~Soldier() 
{
    --countDestructors;
}