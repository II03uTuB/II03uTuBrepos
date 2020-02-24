#include <gmock/gmock.h>
#include <string>

#include "../src/ForwardList.h"


using namespace std;


TEST(ForwardList, DefaultConstructor)
{
    ForwardList <int> listTest1;
    ForwardList <char> listTest2;
    ForwardList <double> listTest3;
    ForwardList <string> listTest4;
    ForwardList <unsigned> listTest5;

    EXPECT_EQ(listTest1.size(), 0);
    EXPECT_EQ(listTest2.size(), 0);
    EXPECT_EQ(listTest3.size(), 0);
    EXPECT_EQ(listTest4.size(), 0);
    EXPECT_EQ(listTest5.size(), 0);
}

TEST(ForwardList, CopyConstructor)
{
    ForwardList <int> listTest;
    listTest.push_back(32);
    listTest.push_back(24);
    listTest.push_back(12);
    listTest.push_back(124);
    listTest.push_back(14);
    listTest.push_back(14);
    listTest.push_back(76);

    ForwardList <int> listCopyTest(listTest);

    EXPECT_EQ(listTest.size(), listCopyTest.size());

    for(int i = 1; i <= listTest.size(); ++i)
    {
        EXPECT_EQ(listTest.get(i), listCopyTest.get(i));
    }
}


TEST(ForwardList, clearTest)
{
    ForwardList <int> listTest;
    listTest.push_back(32);
    listTest.push_back(24);
    listTest.push_back(12);
    listTest.push_back(124);
    listTest.push_back(14);
    listTest.push_back(14);
    listTest.push_back(76);

    EXPECT_EQ(listTest.size(), 7);
    listTest.clear();
    EXPECT_EQ(listTest.size(), 0);
}

TEST(ForwardList, insertAfterTest)
{
    ForwardList <int> listTest;
    listTest.push_back(61);
    listTest.push_back(32);
    listTest.push_back(24);
    listTest.push_back(12);
    listTest.push_back(124);

    listTest.insert_after(listTest.first(), 21);//вставим на 2 позицию
    listTest.insert_after(listTest.findIndex(3), 46);//вставим на 4 позицию
    listTest.insert_after(listTest.findIndex(5), 80);//вставим на 6 позицию
    EXPECT_EQ(listTest.get(1), 61);
    EXPECT_EQ(listTest.get(2), 21);
    EXPECT_EQ(listTest.get(3), 32);
    EXPECT_EQ(listTest.get(4), 46);
    EXPECT_EQ(listTest.get(5), 24);
    EXPECT_EQ(listTest.get(6), 80);
    EXPECT_EQ(listTest.get(7), 12);
    EXPECT_EQ(listTest.get(8), 124);
    EXPECT_THROW(listTest.get(9), OutOfRange);

}
TEST(ForwardList, pushFrontTest)
{
    ForwardList <int> listTest;
    listTest.push_front(61);
    listTest.push_front(60);
    listTest.push_front(59);
    listTest.push_front(58);
    listTest.push_front(57);

    EXPECT_EQ(listTest.get(1), 57);
    EXPECT_EQ(listTest.get(2), 58);
    EXPECT_EQ(listTest.get(3), 59);
    EXPECT_EQ(listTest.get(4), 60);
    EXPECT_EQ(listTest.get(5), 61);
    EXPECT_THROW(listTest.get(6), OutOfRange); //не найдено!
}
TEST(ForwardList, pushBackTest)
{
    ForwardList <int> listTest;
    listTest.push_back(61);
    listTest.push_back(60);
    listTest.push_back(59);
    listTest.push_back(58);
    listTest.push_back(57);

    EXPECT_EQ(listTest.get(1), 61);
    EXPECT_EQ(listTest.get(2), 60);
    EXPECT_EQ(listTest.get(3), 59);
    EXPECT_EQ(listTest.get(4), 58);
    EXPECT_EQ(listTest.get(5), 57);
    EXPECT_THROW(listTest.get(6), OutOfRange); //не найдено!
}

TEST(ForwardList, removeTest)
{
    ForwardList <int> listTest;
    listTest.push_back(32);
    listTest.push_back(24);
    listTest.push_back(12);
    listTest.push_back(124);
    listTest.push_back(17);
    listTest.push_back(14);
    listTest.push_back(76);

    EXPECT_EQ(listTest.size(), 7);

    listTest.remove(32);
    EXPECT_EQ(listTest.get(1), 24);
    EXPECT_EQ(listTest.size(), 6);

    listTest.remove(124);
    EXPECT_EQ(listTest.get(3), 17);
    EXPECT_EQ(listTest.size(), 5);

    listTest.remove(14);
    EXPECT_EQ(listTest.get(4), 76);
    EXPECT_EQ(listTest.size(), 4);
}
TEST(ForwardList, removeTestIdenticalElements)
{
    ForwardList <int> listTest;
    listTest.push_back(32);
    listTest.push_back(24);
    listTest.push_back(32);
    listTest.push_back(124);
    listTest.push_back(32);
    listTest.push_back(14);
    listTest.push_back(32);

    listTest.remove(32); //удалили 4 элемента со значением 32
    EXPECT_EQ(listTest.size(), 3);
}

TEST(ForwardList, firstAndLastTest)
{
    ForwardList <int> listTest1;
    listTest1.push_back(32);
    listTest1.push_back(24);
    listTest1.push_back(35);
    listTest1.push_back(124);
    listTest1.push_back(234);
    listTest1.push_back(14);
    listTest1.push_back(2567);

    ForwardList <int> listTest2;
    listTest2.push_back(32);

    EXPECT_EQ(listTest2.first(), listTest2.last());

    ForwardList <int> listTest3;

    EXPECT_THROW(listTest3.first(), ListIsEmpty);
}

TEST(ForwardList, getTest)
{
    ForwardList <int> listTest;
    listTest.push_back(32);
    listTest.push_back(24);
    listTest.push_back(35);
    listTest.push_back(124);
    listTest.push_back(234);
    listTest.push_back(14);
    listTest.push_back(2567);

    EXPECT_EQ(listTest.size(), 7);

    EXPECT_THROW(listTest.get(-100), OutOfRange);
    EXPECT_THROW(listTest.get(0), OutOfRange); 
    EXPECT_EQ(listTest.get(1), 32);
    EXPECT_EQ(listTest.get(2), 24);
    EXPECT_EQ(listTest.get(3), 35);
    EXPECT_EQ(listTest.get(4), 124);
    EXPECT_EQ(listTest.get(5), 234);
    EXPECT_EQ(listTest.get(6), 14);
    EXPECT_EQ(listTest.get(7), 2567);
    EXPECT_THROW(listTest.get(8), OutOfRange);
}

TEST(ForwardList, emptyTest)
{
    ForwardList <int> listTest;

    EXPECT_TRUE(listTest.empty());

    listTest.push_back(35);
    listTest.push_back(124);

    EXPECT_FALSE(listTest.empty()); 
}

TEST(ForwardList, reverseTest)
{
    ForwardList <int> listTest;
    listTest.push_back(32);
    listTest.push_back(24);
    listTest.push_back(35);
    listTest.push_back(124);
    listTest.push_back(234);
    listTest.push_back(14);
    listTest.push_back(2567);

    EXPECT_EQ(listTest.get(1), 32);
    EXPECT_EQ(listTest.get(2), 24);
    EXPECT_EQ(listTest.get(3), 35);
    EXPECT_EQ(listTest.get(4), 124);
    EXPECT_EQ(listTest.get(5), 234);
    EXPECT_EQ(listTest.get(6), 14);
    EXPECT_EQ(listTest.get(7), 2567);

    listTest.reverse();

    EXPECT_EQ(listTest.get(1), 2567);
    EXPECT_EQ(listTest.get(2), 14);
    EXPECT_EQ(listTest.get(3), 234);
    EXPECT_EQ(listTest.get(4), 124);
    EXPECT_EQ(listTest.get(5), 35);
    EXPECT_EQ(listTest.get(6), 24);
    EXPECT_EQ(listTest.get(7), 32);
    EXPECT_THROW(listTest.get(8), OutOfRange);//ничего лишнего!
}

TEST(ForwardList, sizeTest)
{
    ForwardList <int> listTest;
    EXPECT_EQ(listTest.size(), 0);

    listTest.push_back(32);
    EXPECT_EQ(listTest.size(), 1);

    listTest.push_back(24);
    EXPECT_EQ(listTest.size(), 2);

    listTest.push_back(35);
    EXPECT_EQ(listTest.size(), 3);

    listTest.push_back(124);
    EXPECT_EQ(listTest.size(), 4);

    listTest.push_back(234);
    EXPECT_EQ(listTest.size(), 5);

    listTest.push_back(14);
    EXPECT_EQ(listTest.size(), 6);

    listTest.push_back(2567);
    EXPECT_EQ(listTest.size(), 7);
}

TEST(ForwardList, equalTest)
{
    ForwardList <int> listTest1;
    listTest1.push_back(32);
    listTest1.push_back(24);
    listTest1.push_back(35);
    listTest1.push_back(124);
    listTest1.push_back(234);
    listTest1.push_back(14);
    listTest1.push_back(2567);

    ForwardList <int> listTest2;
    listTest2.push_back(32);
    listTest2.push_back(24);
    listTest2.push_back(35);
    listTest2.push_back(124);
    listTest2.push_back(234);
    listTest2.push_back(14);
    listTest2.push_back(2567);

    EXPECT_EQ(listTest1 == listTest2, true);

    listTest2.remove(32);

    EXPECT_EQ(listTest1 == listTest2, false);
}

TEST(ForwardList, notEqualTest)
{
    ForwardList <int> listTest1;
    listTest1.push_back(32);
    listTest1.push_back(24);
    listTest1.push_back(35);
    listTest1.push_back(124);
    listTest1.push_back(234);
    listTest1.push_back(14);
    listTest1.push_back(2567);

    ForwardList <int> listTest2;
    listTest2.push_back(32);
    listTest2.push_back(24);
    listTest2.push_back(35);
    listTest2.push_back(124);
    listTest2.push_back(234);

    EXPECT_EQ(listTest1 != listTest2, true);

    listTest2.push_back(14);
    listTest2.push_back(2567);

    EXPECT_EQ(listTest1 != listTest2, false);
}
