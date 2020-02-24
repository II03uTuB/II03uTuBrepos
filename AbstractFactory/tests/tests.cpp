#include <gmock/gmock.h>


#include "../src/CurrencyFactory.h"
#include "../src/Dollar.h"
#include "../src/Euro.h"
#include "../src/ICurrency.h"


using namespace std;


TEST(AbstractFactory, SerializationTest)
{
    RegisterLoaders();
    ICurrency **money = new ICurrency*[10]{new Dollar(325), new Euro(3.74), 
                                           new Euro(38.879657),new Dollar(7665.769), 
                                           new Euro(867), new Euro(2342.98757),
                                           new Dollar(7654.87),new Dollar(4572.9876), 
                                           new Euro(84644), new Dollar(1455)};
    Save("AbstractFactoryTests.txt", money, 10);
    //Чтобы убедиться в корректной записи
    //достаточно зайти в файл AbstractFactoryTests.txt
}

TEST(AbstractFactory, DeSerializationTest)
{
    vector<ICurrency*> loaderMoney = Load("AbstractFactoryTests.txt");
    int size = loaderMoney.size();
    ASSERT_EQ(10, size);
}

TEST(AbstractFactory, DollarTests)
{
    ICurrency **money = new ICurrency*[3]{new Dollar(325), new Dollar (500),new Dollar (10000)};
    ASSERT_EQ(325,static_cast<Dollar*>(money[0])->getcountOfDollar());
    ASSERT_EQ(500,static_cast<Dollar*>(money[1])->getcountOfDollar());
    ASSERT_EQ(10000,static_cast<Dollar*>(money[2])->getcountOfDollar());
    ASSERT_FLOAT_EQ(20725.25,static_cast<Dollar*>(money[0])->convertUsdRub());
    ASSERT_FLOAT_EQ(31885,static_cast<Dollar*>(money[1])->convertUsdRub());
    ASSERT_FLOAT_EQ(637700,static_cast<Dollar*>(money[2])->convertUsdRub());
    ASSERT_FLOAT_EQ(357.5,static_cast<Dollar*>(money[0])->convertUsdEur());
    ASSERT_FLOAT_EQ(550,static_cast<Dollar*>(money[1])->convertUsdEur());
    ASSERT_FLOAT_EQ(11000,static_cast<Dollar*>(money[2])->convertUsdEur());
}

TEST(AbstractFactory, EuroTests)
{
    ICurrency **money = new ICurrency*[3]{new Euro(34.745), new Euro (380),new Euro (13.87)};
    ASSERT_EQ(34.745,static_cast<Euro*>(money[0])->getcountOfEuro());
    ASSERT_EQ(380,static_cast<Euro*>(money[1])->getcountOfEuro());
    ASSERT_EQ(13.87,static_cast<Euro*>(money[2])->getcountOfEuro());
    ASSERT_FLOAT_EQ(2449.5225,static_cast<Euro*>(money[0])->convertEuroRub());
    ASSERT_FLOAT_EQ(26790,static_cast<Euro*>(money[1])->convertEuroRub());
    ASSERT_FLOAT_EQ(977.83502,static_cast<Euro*>(money[2])->convertEuroRub());
}
