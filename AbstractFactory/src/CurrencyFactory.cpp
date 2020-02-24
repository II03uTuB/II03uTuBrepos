#include "CurrencyFactory.h"


void CurrencyFactory::RegisterLoader(string typeName, CurrencyLoaderPtr loader)
{
    _registered[typeName] = loader;
};

CurrencyLoaderPtr CurrencyFactory::GetLoader(string typeName)
{
    if(_registered.find(typeName) == _registered.end())
    {
        throw runtime_error("Illegal type");
    }

    return _registered[typeName];
};

CurrencyFactory& CurrencyFactory::GetInstance()
{
    static CurrencyFactory soleInstance;

    return soleInstance;
};

void RegisterLoaders()
{
    CurrencyFactory::GetInstance().RegisterLoader("Dollar", Dollar::Load);
    CurrencyFactory::GetInstance().RegisterLoader("Euro", Euro::Load);
};

bool Save(const char *fileName, ICurrency **objects, size_t size)
{
    ofstream outFile(fileName);
    if (!outFile)
    {
        return false;
    }
    for (int i = 0; i < size; ++i)
    {
        objects[i]->Save(outFile);
    }
    
    return true;
};

vector<ICurrency*> Load(const char *fileName)
{
    ifstream inFile(fileName);
    if (!inFile)
    {
        throw runtime_error("Cannot open file!");
    }
    vector<ICurrency *> result;
    string typeName;
    while(inFile >> typeName)
    {
        ICurrency *_currency = CurrencyFactory::GetInstance().GetLoader(typeName)(inFile);
        result.push_back(_currency);
    }
    
    return result;
};
