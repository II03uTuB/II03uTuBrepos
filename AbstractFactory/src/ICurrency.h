#ifndef ABSTRACTFACTORY_ICURRENCY_H
#define ABSTRACTFACTORY_ICURRENCY_H


#include <fstream>
#include <iostream>


using namespace std;


struct ICurrency
{
    virtual ~ICurrency() {};
    virtual void Save(ostream& stream) = 0;
};


#endif //ABSTRACTFACTORY_ICURRENCY_H
