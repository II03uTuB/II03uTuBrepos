#ifndef ABSTRACTFACTORY_CURRENCYFACTORY_H
#define ABSTRACTFACTORY_CURRENCYFACTORY_H


#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>


#include "Dollar.h"
#include "Euro.h"
#include "ICurrency.h"


using namespace std;


typedef ICurrency *(*CurrencyLoaderPtr)(ifstream &stream);

struct CurrencyFactory
{
    void RegisterLoader(string typeName, CurrencyLoaderPtr loader);
    CurrencyLoaderPtr GetLoader(string typeName);
    static CurrencyFactory& GetInstance();
private:
    map<string, CurrencyLoaderPtr> _registered;
};

extern void RegisterLoaders();

extern bool Save(const char *fileName, ICurrency **objects, size_t size);

extern vector<ICurrency*> Load(const char *fileName);


#endif //ABSTRACTFACTORY_CURRENCYFACTORY_H
