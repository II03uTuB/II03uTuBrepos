#include <gmock/gmock.h>


#include "../src/Parking.h"
#include "../src/RegNumber.h"
#include "../src/DataBase.h"
#include "../src/SizeOfCar.h"


class MockDataBase : public DataBase
{
public: 
    MOCK_CONST_METHOD1(trueNumber, bool(unsigned int));
};

class MockRegNumber : public RegNumber
{
public:
    MOCK_CONST_METHOD0(scanNumber, unsigned int());
};

class MockSizeOfCar : public SizeOfCar
{
public:
    MOCK_CONST_METHOD0(scanLenght, double());
    MOCK_CONST_METHOD0(scanWidth, double());
};


TEST(Parking, gates_open) //случай, когда ворота откроются
{
    unsigned int number = 365;
    double lenght = 4.9;
    double widht =1.9;


    MockDataBase mockDb;
    MockRegNumber mockRn;
    MockSizeOfCar mockSoc;


    EXPECT_CALL(mockDb, trueNumber(number)).WillOnce(::testing::Return(true));
    EXPECT_CALL(mockRn, scanNumber()).WillOnce(::testing::Return(number));
    EXPECT_CALL(mockSoc, scanLenght()).WillOnce(::testing::Return(3));
    EXPECT_CALL(mockSoc, scanWidth()).WillOnce(::testing::Return(1.5));

    Parking parking(&mockDb, &mockRn, &mockSoc);
    EXPECT_THAT(parking.GatesOpen(), ::testing::Eq(true));
}

TEST(Parking, width_excess) //ширина больше допустимого
{
    unsigned int number = 365;
    double lenght = 4.9;
    double widht =1.9;


    MockDataBase mockDb;
    MockRegNumber mockRn;
    MockSizeOfCar mockSoc;


    EXPECT_CALL(mockDb, trueNumber(number)).Times(0);
    EXPECT_CALL(mockRn, scanNumber()).Times(0);
    EXPECT_CALL(mockSoc, scanLenght()).WillOnce(::testing::Return(3));
    EXPECT_CALL(mockSoc, scanWidth()).WillOnce(::testing::Return(2.25));

    Parking parking(&mockDb, &mockRn, &mockSoc);
    EXPECT_THAT(parking.GatesOpen(), ::testing::Eq(false));
}

TEST(Parking, no_number) //номера нет в базе данных
{
    unsigned int number = 365;
    double lenght = 4.9;
    double widht =1.9;


    MockDataBase mockDb;
    MockRegNumber mockRn;
    MockSizeOfCar mockSoc;


    EXPECT_CALL(mockDb, trueNumber(number)).WillOnce(::testing::Return(false));
    EXPECT_CALL(mockRn, scanNumber()).WillOnce(::testing::Return(number));
    EXPECT_CALL(mockSoc, scanLenght()).WillOnce(::testing::Return(3));
    EXPECT_CALL(mockSoc, scanWidth()).WillOnce(::testing::Return(1.5));

    Parking parking(&mockDb, &mockRn, &mockSoc);
    EXPECT_THAT(parking.GatesOpen(), ::testing::Eq(false));
}
TEST(Parking, no_number_width_excess) // номера нет в базе данных+
                                      // ширина больше допустимого
{
    unsigned int number = 365;
    double lenght = 4.9;
    double widht =1.9;


    MockDataBase mockDb;
    MockRegNumber mockRn;
    MockSizeOfCar mockSoc;


    EXPECT_CALL(mockDb, trueNumber(number)).Times(0);
    EXPECT_CALL(mockRn, scanNumber()).Times(0);
    EXPECT_CALL(mockSoc, scanLenght()).WillOnce(::testing::Return(3));
    EXPECT_CALL(mockSoc, scanWidth()).WillOnce(::testing::Return(2.50));

    Parking parking(&mockDb, &mockRn, &mockSoc);
    EXPECT_THAT(parking.GatesOpen(), ::testing::Eq(false));
}

TEST(Parking, no_number_lenght_excess_width_excess) // номера нет в базе данных+
                                                    // длина больше допустимого+
                                                    // ширина больше допустимого
{
    unsigned int number = 365;
    double lenght = 4.9;
    double widht =1.9;


    MockDataBase mockDb;
    MockRegNumber mockRn;
    MockSizeOfCar mockSoc;


    EXPECT_CALL(mockDb, trueNumber(number)).Times(0);
    EXPECT_CALL(mockRn, scanNumber()).Times(0);
    EXPECT_CALL(mockSoc, scanLenght()).WillOnce(::testing::Return(5.05));
    EXPECT_CALL(mockSoc, scanWidth()).Times(0);

    Parking parking(&mockDb, &mockRn, &mockSoc);
    EXPECT_THAT(parking.GatesOpen(), ::testing::Eq(false));
}
