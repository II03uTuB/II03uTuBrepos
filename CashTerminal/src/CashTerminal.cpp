#include "CashTerminal.h"


CashTerminal::CashTerminal(ICashStorage *cashStorage,
                           IDataBase *dataBase,
                           IDisplay *display,
                           IKeyboard *keyboard):
                           _cashStorage(cashStorage),
                           _dataBase(dataBase),
                           _display(display),
                           _keyboard(keyboard)
 {

 }
void CashTerminal::StartSession(unsigned cardId)
{
    unsigned pin = _keyboard->ReadInput();
    if (!_dataBase->CheckPin(cardId, pin))
    {
        _display->PrintMessage("Invalid pinCode");
        return;
    }

    _display->PrintMenu();
    _cardId = cardId;
}

void CashTerminal::PrintBalance()
{
    if (_cardId == 0)
        return;

    _display->PrintBalance(_dataBase->GetBalance(_cardId));
}

void CashTerminal::GetCash()
{
    if (_cardId == 0)
        return;
    _display->PrintMessage("Input cash sum");

    unsigned sum = _keyboard->ReadInput();
    unsigned balance = _dataBase->GetBalance(_cardId);

    if(sum > balance)
    {
        _display->PrintMessage("Not enough money");
        return ;
    }

    _dataBase->WithDraw(sum);
    _cashStorage->GiveOut(sum);
}

void CashTerminal::InsertCash(unsigned sum)
{
    if (_cardId == 0)
        return;

    _cashStorage->PutIn(sum);
    _dataBase->Deposit(sum);
}

void CashTerminal::StopSession()
{
    if (_cardId == 0)
        return;

    _cardId = 0;
    _display->PrintMessage("GoodBye!");
}
