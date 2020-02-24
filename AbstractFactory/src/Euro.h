#ifndef ABSTRACTFACTORY_EURO_H
#define ABSTRACTFACTORY_EURO_H


#include <iostream>
#include <fstream>


#include "ICurrency.h"


class Euro : public ICurrency
{
public:
    Euro(double countOfEuro);
    void Save(ostream& stream) override;
    static ICurrency *Load(ifstream &stream);
    double getcountOfEuro();
    double convertEuroRub();
    ~Euro(){};
private:
    double _countOfEuro;
};


#endif //ABSTRACTFACTORY_EURO_H
