#ifndef ABSTRACTFACTORY_DOLLAR_H
#define ABSTRACTFACTORY_DOLLAR_H


#include <fstream>
#include <iostream>


#include "ICurrency.h"


using namespace std;


class Dollar : public ICurrency
{
public:
    Dollar(double countOfDollar);
    void Save(ostream& stream) override;
    static ICurrency *Load(ifstream& stream);
    double getcountOfDollar();
    double convertUsdRub();
    double convertUsdEur();
    ~Dollar(){};
private:
    double _countOfDollar;
};


#endif //ABSTRACTFACTORY_DOLLAR_H
