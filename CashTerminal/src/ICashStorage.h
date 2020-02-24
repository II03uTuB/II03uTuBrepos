#ifndef CASHTERMINAL_ICASHESTORAGE_H
#define CASHTERMINAL_ICASHESTORAGE_H


class ICashStorage
{
public:
    virtual void GiveOut(unsigned sum) = 0;
    virtual void PutIn(unsigned sum) = 0;
};


#endif//CASHTERMINAL_ICASHSTORAGE_H
