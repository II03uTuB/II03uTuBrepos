#include "Officer.h"


Officer::Officer(IMilitaryMan **subordinates, unsigned int count) : _count(count) {
    ++countDestructors;
    _subordinates = new IMilitaryMan*[count];
    for (int i = 0; i < _count; ++i)
        {
            _subordinates[i] = subordinates[i];
        }
}

void Officer::Serve() {
   for (int i = 0; i < _count; ++i)
       {
           _subordinates[i]->Serve();
       }
}

Officer::~Officer() 
{
    --countDestructors;
    for (int i = 0; i < _count; ++i)
        {
            delete _subordinates[i];
        }  
    delete[] _subordinates;
}
