#ifndef CASHTERMINAL_IDATABASE_H
#define CASHTERMINAL_IDATABASE_H


class IDataBase
{
public:
    virtual bool CheckPin(unsigned cardId, unsigned pinCode) = 0;
    virtual unsigned GetBalance(unsigned cardId) = 0;
    virtual void WithDraw(unsigned sum) = 0;
    virtual void Deposit(unsigned sum) = 0;
};


#endif//CASHTERMINAL_IDATABASE_H
