#ifndef CASHTERMINAL_CASHTERMINAL_H
#define CASHTERMINAL_CASHTERMINAL_H


#include "ICashStorage.h"
#include "IDataBase.h"
#include "IDisplay.h"
#include "IKeyboard.h"


class CashTerminal
{
public:
    CashTerminal(ICashStorage *_cashStorage,
                 IDataBase *_dataBase,
                 IDisplay *_display,
                 IKeyboard *_keyboard);
    void StartSession(unsigned cardId);
    void PrintBalance();
    void GetCash();
    void InsertCash(unsigned sum);
    void StopSession();
private:
    ICashStorage* _cashStorage;
    IKeyboard* _keyboard;
    IDisplay* _display;
    IDataBase* _dataBase;
    unsigned _cardId;
};


#endif//CASHTERMINAL_CASHTERMINAL_H
