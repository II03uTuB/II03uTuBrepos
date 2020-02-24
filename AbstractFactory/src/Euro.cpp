#include "Euro.h"


Euro::Euro(double countOfEuro)
{
    _countOfEuro = countOfEuro;
}

void Euro::Save(ostream& stream) 
{
    stream << "Euro " << _countOfEuro<< "\n";
};

ICurrency* Euro::Load(ifstream &stream)
{
    double countOfEuro;
    stream >> countOfEuro;

    return new Euro(countOfEuro);
};

double Euro::getcountOfEuro()
{
    return _countOfEuro;
};

double Euro::convertEuroRub()
{
    return _countOfEuro * 70.5;
}
