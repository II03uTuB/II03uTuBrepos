#include <gmock/gmock.h>


#include "../src/CashTerminal.h"
#include "../src/ICashStorage.h"
#include "../src/IDataBase.h"
#include "../src/IDisplay.h"
#include "../src/IKeyboard.h"


class MockICashStorage : public ICashStorage
{
public:
    MOCK_METHOD1(GiveOut, void(unsigned));
    MOCK_METHOD1(PutIn, void(unsigned));
};
class MockIDataBase : public IDataBase
{
public:
    MOCK_METHOD2(CheckPin, bool(unsigned, unsigned));
    MOCK_METHOD1(GetBalance, unsigned(unsigned));
    MOCK_METHOD1(WithDraw, void(unsigned int));
    MOCK_METHOD1(Deposit, void(unsigned int));
};

class MockIDisplay : public IDisplay
{
public:
    MOCK_METHOD0(PrintMenu, void());
    MOCK_METHOD1(PrintBalance, void(unsigned));
    MOCK_METHOD1(PrintMessage, void(const char*));
};

class MockIKeyboard : public IKeyboard
{
public: 
    MOCK_METHOD0(ReadInput, unsigned());
};

TEST(CashTerminal,StartSessionSuccessful) //успешный вход в терминал
{
    unsigned pin = 2510;
    unsigned cardId= 58003443;

    MockICashStorage mockICashStorage;
    MockIDataBase mockIDataBase;
    MockIDisplay mockIDisplay;
    MockIKeyboard mockIKeyboard;


    EXPECT_CALL(mockIKeyboard, ReadInput()).WillOnce(::testing::Return(pin));
    EXPECT_CALL(mockIDataBase, CheckPin(cardId,pin)).WillOnce(::testing::Return(true));
    EXPECT_CALL(mockIDisplay,PrintMenu()).WillOnce(::testing::Return());

    CashTerminal cashTerminal(&mockICashStorage,
                              &mockIDataBase,
                              &mockIDisplay,
                              &mockIKeyboard);
    cashTerminal.StartSession(cardId);
}
TEST(CashTerminal,StartSessionWrongId)//ошибка, неверный Id
{
    unsigned pin = 2510;
    unsigned cardId = 58003443;

    MockICashStorage mockICashStorage;
    MockIDataBase mockIDataBase;
    MockIDisplay mockIDisplay;
    MockIKeyboard mockIKeyboard;

    EXPECT_CALL(mockIKeyboard, ReadInput()).WillOnce(::testing::Return(pin));
    EXPECT_CALL(mockIDataBase, CheckPin(cardId, pin)).WillOnce(::testing::Return(false));
    EXPECT_CALL(mockIDisplay, PrintMenu()).Times(0);
    EXPECT_CALL(mockIDisplay, PrintMessage(::testing::StrEq("Invalid pinCode"))).Times(1);

    CashTerminal cashTerminal(&mockICashStorage,
                              &mockIDataBase,
                              &mockIDisplay,
                              &mockIKeyboard);
    cashTerminal.StartSession(cardId);
}

TEST(CashTerminal,PrintBalance)//вывести текущий баланс
{
    unsigned pin = 2510;
    unsigned sum = 65438;//сумма на балансе
    unsigned cardId = 58003443;

    MockICashStorage mockICashStorage;
    MockIDataBase mockIDataBase;
    MockIDisplay mockIDisplay;
    MockIKeyboard mockIKeyboard;

    EXPECT_CALL(mockIKeyboard, ReadInput()).WillOnce(::testing::Return(pin));
    EXPECT_CALL(mockIDataBase, CheckPin(cardId, pin)).WillOnce(::testing::Return(true));
    EXPECT_CALL(mockIDisplay, PrintMenu()).WillOnce(::testing::Return());

    CashTerminal cashTerminal(&mockICashStorage,
                              &mockIDataBase,
                              &mockIDisplay,
                              &mockIKeyboard);
    cashTerminal.StartSession(cardId);

    EXPECT_CALL(mockIDataBase, GetBalance(cardId)).WillOnce(::testing::Return(sum));
    EXPECT_CALL(mockIDisplay, PrintBalance(sum)).Times(1);

    cashTerminal.PrintBalance();
}

TEST(CashTerminal,PrintBalanceWrongId)//вывод баланса невозможен
                                      //из-за неправильного Id
{
    unsigned pin = 2510;
    unsigned sum = 65438;
    unsigned cardId = 58003443;

    MockICashStorage mockICashStorage;
    MockIDataBase mockIDataBase;
    MockIDisplay mockIDisplay;
    MockIKeyboard mockIKeyboard;

    EXPECT_CALL(mockIKeyboard, ReadInput()).WillOnce(::testing::Return(pin));
    EXPECT_CALL(mockIDataBase, CheckPin(cardId, pin)).WillOnce(::testing::Return(false));
    EXPECT_CALL(mockIDisplay, PrintMenu()).Times(0);
    EXPECT_CALL(mockIDisplay, PrintMessage(::testing::StrEq("Invalid pinCode"))).Times(1);

    CashTerminal cashTerminal(&mockICashStorage,
                              &mockIDataBase,
                              &mockIDisplay,
                              &mockIKeyboard);
    cashTerminal.StartSession(cardId);

    EXPECT_CALL(mockIDataBase, GetBalance(cardId)).Times(0);
    EXPECT_CALL(mockIDisplay, PrintBalance(sum)).Times(0);

    cashTerminal.PrintBalance();
}

TEST(CashTerminal,GetMoneySuccessful)//обналичить средства
{
    unsigned pin = 2510;
    unsigned sum = 65438;//сумма на балансе
    unsigned cardId = 58003443;
    unsigned money = 14061;//сколько хотим обналичить

    MockICashStorage mockICashStorage;
    MockIDataBase mockIDataBase;
    MockIDisplay mockIDisplay;
    MockIKeyboard mockIKeyboard;

    EXPECT_CALL(mockIKeyboard, ReadInput()).WillOnce(::testing::Return(pin));
    EXPECT_CALL(mockIDataBase, CheckPin(cardId, pin)).WillOnce(::testing::Return(true));
    EXPECT_CALL(mockIDisplay, PrintMenu()).WillOnce(::testing::Return());

    CashTerminal cashTerminal(&mockICashStorage,
                              &mockIDataBase,
                              &mockIDisplay,
                              &mockIKeyboard);
    cashTerminal.StartSession(cardId);
    EXPECT_CALL(mockIDisplay, PrintMessage(::testing::StrEq("Input cash sum"))).Times(1);
    EXPECT_CALL(mockIKeyboard, ReadInput()).WillOnce(::testing::Return(money));
    EXPECT_CALL(mockIDataBase, GetBalance(cardId)).WillOnce(::testing::Return(sum));
    EXPECT_CALL(mockIDataBase, WithDraw(testing::Eq(money))).Times(1);
    EXPECT_CALL(mockICashStorage, GiveOut(testing::Eq(money))).Times(1);

    cashTerminal.GetCash();
}

TEST(CashTerminal,GetMoneyNoCashOnAccount)//захотели снять больше чем есть)
{
    unsigned pin = 2510;
    unsigned sum = 65438;//сумма на балансе
    unsigned cardId = 58003443;
    unsigned money = 74061;//сколько хотим обналичить
                           //желаемая сумма больше доступной

    MockICashStorage mockICashStorage;
    MockIDataBase mockIDataBase;
    MockIDisplay mockIDisplay;
    MockIKeyboard mockIKeyboard;

    EXPECT_CALL(mockIKeyboard, ReadInput()).WillOnce(::testing::Return(pin));
    EXPECT_CALL(mockIDataBase, CheckPin(cardId, pin)).WillOnce(::testing::Return(true));
    EXPECT_CALL(mockIDisplay, PrintMenu()).WillOnce(::testing::Return());

    CashTerminal cashTerminal(&mockICashStorage,
                              &mockIDataBase,
                              &mockIDisplay,
                              &mockIKeyboard);
    cashTerminal.StartSession(cardId);

    EXPECT_CALL(mockIDisplay, PrintMessage(::testing::StrEq("Input cash sum"))).Times(1);
    EXPECT_CALL(mockIKeyboard, ReadInput()).WillOnce(::testing::Return(money));
    EXPECT_CALL(mockIDataBase, GetBalance(cardId)).WillOnce(::testing::Return(sum));
    EXPECT_CALL(mockIDisplay, PrintMessage(::testing::StrEq("Not enough money"))).Times(1);
    EXPECT_CALL(mockIDataBase, WithDraw(testing::Eq(money))).Times(0);
    EXPECT_CALL(mockICashStorage, GiveOut(testing::Eq(money))).Times(0);

    cashTerminal.GetCash();
}

TEST(CashTerminal,InsertMoney)//внести наличные
{
    unsigned pin = 2510;
    unsigned cardId = 58003443;
    unsigned money = 14061;

    MockICashStorage mockICashStorage;
    MockIDataBase mockIDataBase;
    MockIDisplay mockIDisplay;
    MockIKeyboard mockIKeyboard;

    EXPECT_CALL(mockIKeyboard, ReadInput()).WillOnce(::testing::Return(pin));
    EXPECT_CALL(mockIDataBase, CheckPin(cardId, pin)).WillOnce(::testing::Return(true));
    EXPECT_CALL(mockIDisplay, PrintMenu()).WillOnce(::testing::Return());

    CashTerminal cashTerminal(&mockICashStorage,
                              &mockIDataBase,
                              &mockIDisplay,
                              &mockIKeyboard);
    cashTerminal.StartSession(cardId);

    EXPECT_CALL(mockICashStorage, PutIn(::testing::Eq(money))).Times(1);
    EXPECT_CALL(mockIDataBase, Deposit(::testing::Eq(money))).Times(1);

    cashTerminal.InsertCash(money);
}

TEST(CashTerminal,InsertMoneyWrongId)//нельзя внести - неверный Id
{
    unsigned pin = 2510;
    unsigned cardId = 58003443;
    unsigned money = 14061;

    MockICashStorage mockICashStorage;
    MockIDataBase mockIDataBase;
    MockIDisplay mockIDisplay;
    MockIKeyboard mockIKeyboard;

    EXPECT_CALL(mockIKeyboard, ReadInput()).WillOnce(::testing::Return(pin));
    EXPECT_CALL(mockIDataBase, CheckPin(cardId, pin)).WillOnce(::testing::Return(false));
    EXPECT_CALL(mockIDisplay, PrintMenu()).Times(0);
    EXPECT_CALL(mockIDisplay,PrintMessage(::testing::StrEq("Invalid pinCode"))).Times(1);

    CashTerminal cashTerminal(&mockICashStorage,
                              &mockIDataBase,
                              &mockIDisplay,
                              &mockIKeyboard);
    cashTerminal.StartSession(cardId);

    EXPECT_CALL(mockICashStorage, PutIn(money)).Times(0);
    EXPECT_CALL(mockIDataBase, Deposit(money)).Times(0);
    cashTerminal.InsertCash(money);
}

TEST(CashTerminal,StopSession)//завершить работу
{
    unsigned pin = 2510;
    unsigned cardId= 58003443;

    MockICashStorage mockICashStorage;
    MockIDataBase mockIDataBase;
    MockIDisplay mockIDisplay;
    MockIKeyboard mockIKeyboard;

    EXPECT_CALL(mockIKeyboard, ReadInput()).WillOnce(::testing::Return(pin));
    EXPECT_CALL(mockIDataBase, CheckPin(cardId,pin)).WillOnce(::testing::Return(true));
    EXPECT_CALL(mockIDisplay,PrintMenu()).WillOnce(::testing::Return());

    CashTerminal cashTerminal(&mockICashStorage,
                              &mockIDataBase,
                              &mockIDisplay,
                              &mockIKeyboard);
    cashTerminal.StartSession(cardId);

    EXPECT_CALL(mockIDisplay,PrintMessage(::testing::StrEq("GoodBye!"))).Times(1);
    cashTerminal.StopSession();
}

TEST(CashTerminal,StopSessionWrongStart)//выход невозможен, т.к. для того,
                                        //чтобы выйти необходимо сначала войти
{
    unsigned pin = 2510;
    unsigned cardId= 58003443;

    MockICashStorage mockICashStorage;
    MockIDataBase mockIDataBase;
    MockIDisplay mockIDisplay;
    MockIKeyboard mockIKeyboard;

    EXPECT_CALL(mockIKeyboard, ReadInput()).WillOnce(::testing::Return(pin));
    EXPECT_CALL(mockIDataBase, CheckPin(cardId,pin)).WillOnce(::testing::Return(false));
    EXPECT_CALL(mockIDisplay,PrintMenu()).Times(0);
    EXPECT_CALL(mockIDisplay,PrintMessage(::testing::StrEq("Invalid pinCode"))).Times(1);

    CashTerminal cashTerminal(&mockICashStorage,
                              &mockIDataBase,
                              &mockIDisplay,
                              &mockIKeyboard);
    cashTerminal.StartSession(cardId);
    cashTerminal.StopSession();
}
using::testing::Sequence;
TEST(CashTerminal,GetMoneySuccessfulInSecuences)//обналичить средства
{
    unsigned pin = 2510;
    unsigned sum = 65438;//сумма на балансе
    unsigned cardId = 58003443;
    unsigned money = 14061;//сколько хотим обналичить

    MockICashStorage mockICashStorage;
    MockIDataBase mockIDataBase;
    MockIDisplay mockIDisplay;
    MockIKeyboard mockIKeyboard;

    Sequence s1,s2,s3,s4,s5,s6;

    EXPECT_CALL(mockIKeyboard, ReadInput()).InSequence(s1,s2).WillOnce(::testing::Return(pin));
    EXPECT_CALL(mockIDataBase, CheckPin(cardId, pin)).InSequence(s1).WillOnce(::testing::Return(true));
    EXPECT_CALL(mockIDisplay, PrintMenu()).InSequence(s2).WillOnce(::testing::Return());

    CashTerminal cashTerminal(&mockICashStorage,
                              &mockIDataBase,
                              &mockIDisplay,
                              &mockIKeyboard);
    cashTerminal.StartSession(cardId);
    
    EXPECT_CALL(mockIDisplay, PrintMessage(::testing::StrEq("Input cash sum"))).Times(1);
    EXPECT_CALL(mockIKeyboard, ReadInput()).InSequence(s4,s5,s6).WillOnce(::testing::Return(money));
    EXPECT_CALL(mockIDataBase, GetBalance(cardId)).InSequence(s4).WillOnce(::testing::Return(sum));
    EXPECT_CALL(mockIDataBase, WithDraw(testing::Eq(money))).InSequence(s5).Times(1);
    EXPECT_CALL(mockICashStorage, GiveOut(testing::Eq(money))).InSequence(s6).Times(1);

    cashTerminal.GetCash();
}