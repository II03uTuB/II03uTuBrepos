#include "Dollar.h"


using namespace std;


Dollar::Dollar(double countOfDollar)
{
    _countOfDollar = countOfDollar;
};

void Dollar::Save(ostream& stream) 
{
    stream<<"Dollar "<<_countOfDollar <<"\n";
};

ICurrency* Dollar::Load(ifstream& stream)
{
    double countOfDollar;
    stream >> countOfDollar;

    return new Dollar(countOfDollar);
};

double Dollar::getcountOfDollar()
{
    return _countOfDollar;
};

double Dollar::convertUsdRub()
{
    return _countOfDollar * 63.77;
};

double Dollar::convertUsdEur()
{
    return _countOfDollar * 1.10;
};
