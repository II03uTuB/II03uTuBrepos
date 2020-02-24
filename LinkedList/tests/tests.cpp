#include <algorithm>
#include <iterator>
#include <gmock/gmock.h>


#include "../src/LinkedList.h"


TEST(iterator, PrefixSumTest)
{
    LinkedList<int> listTest;
    listTest.push_back(10);
    listTest.push_back(20);
    listTest.push_back(30);
    listTest.push_back(40);
    listTest.push_back(50);
    listTest.push_back(60);

    LinkedList<int>::iterator i = listTest.begin();

    EXPECT_EQ(*(i++), 10);
    EXPECT_EQ(*(i++), 20);
    EXPECT_EQ(*(i++), 30);
    EXPECT_EQ(*(i++), 40);
    EXPECT_EQ(*(i++), 50);
    EXPECT_EQ(*(i++), 60); 
}

TEST(iterator, PostfixSumTest)
{
    LinkedList<int> listTest;
    listTest.push_back(10);
    listTest.push_back(20);
    listTest.push_back(30);
    listTest.push_back(40);
    listTest.push_back(50);
    listTest.push_back(60);

    LinkedList<int>::iterator i = listTest.begin();

    EXPECT_EQ(*(++i), 20);
    EXPECT_EQ(*(++i), 30);
    EXPECT_EQ(*(++i), 40);
    EXPECT_EQ(*(++i), 50);
    EXPECT_EQ(*(++i), 60);
    EXPECT_EQ(*(++i), 0);
    EXPECT_EQ(*(++i), 10); 
}

TEST(iterator, PrefixDiffTest)
{
    LinkedList<int> listTest;
    listTest.push_back(10);
    listTest.push_back(20);
    listTest.push_back(30);
    listTest.push_back(40);
    listTest.push_back(50);
    listTest.push_back(60);

    LinkedList<int>::iterator i = listTest.end();

    EXPECT_EQ(*(i--), 0);
    EXPECT_EQ(*(i--), 60);
    EXPECT_EQ(*(i--), 50);
    EXPECT_EQ(*(i--), 40);
    EXPECT_EQ(*(i--), 30);
    EXPECT_EQ(*(i--), 20);
    EXPECT_EQ(*(i--), 10); 
}

TEST(iterator, PosfixDiffTest)
{
    LinkedList<int> listTest;
    listTest.push_back(10);
    listTest.push_back(20);
    listTest.push_back(30);
    listTest.push_back(40);
    listTest.push_back(50);
    listTest.push_back(60);

    LinkedList<int>::iterator i = listTest.end();

    EXPECT_EQ(*(--i), 60);
    EXPECT_EQ(*(--i), 50);
    EXPECT_EQ(*(--i), 40);
    EXPECT_EQ(*(--i), 30);
    EXPECT_EQ(*(--i), 20);
    EXPECT_EQ(*(--i), 10); 
    EXPECT_EQ(*(--i), 0);
}

TEST(iterator, EqualAndNotEqualTest)
{
    LinkedList<int> listTest1;
    listTest1.push_back(10);
    listTest1.push_back(20);
    listTest1.push_back(30);
    listTest1.push_back(40);
    listTest1.push_back(50);
    listTest1.push_back(60);

    LinkedList<int> listTest2;
    listTest2.push_back(10);
    listTest2.push_back(20);
    listTest2.push_back(30);
    listTest2.push_back(40);
    listTest2.push_back(50);
    listTest2.push_back(60);

    LinkedList<int>::iterator j = listTest1.end();
    LinkedList<int>::iterator k = listTest2.begin();

    for(auto i = listTest1.begin(); i != listTest1.end(); ++i, ++k)
    {
        EXPECT_TRUE(*(i) == *(k));
    }
    for(auto i = listTest1.begin(); i != listTest1.end(); ++i, ++j)
    {
        EXPECT_TRUE(*(i) != *(k));
    }
}
TEST(iterator, AlgorithmTest) 
{
    LinkedList<int> listTest;
    listTest.push_back(10);
    listTest.push_front(9);
    listTest.push_back(11);
    listTest.push_back(10);
    listTest.push_back(12);
    listTest.push_back(10);
    listTest.push_front(8);

    auto iter = find(listTest.begin(), listTest.end(), 10);
    EXPECT_EQ(*iter, 10);

    int count = std::count(listTest.begin(), listTest.end(), 10);
    EXPECT_EQ(count, 3);

    LinkedList<int> copyList;
    copy(listTest.begin(), listTest.end(), copyList.begin());

    for (LinkedList<int>::iterator i = copyList.begin(); i != copyList.end(); ++i, ++iter) 
    {
        EXPECT_EQ(*i, *iter);
    }

    iter = listTest.begin();
    advance(iter, 3);

    EXPECT_EQ(*iter, 11);
}

TEST(reverse_iterator, PostfixDiffTest) 
{
    LinkedList<int> listTest;

    for (int i = 0; i <= 15; i++)
    {
        listTest.push_back(i);
    }

    int value = 15;
    for (auto iter = listTest.rbegin(); iter != listTest.rend(); ++iter) 
    {
        EXPECT_EQ(*iter, (value--));
    }
}
TEST(LinkedList, ConstructorCopyTest) 
{
    LinkedList<int> listTest;
    listTest.push_back(10);
    listTest.push_front(9);
    listTest.push_back(11);
    listTest.push_back(12);
    listTest.push_front(8);

    LinkedList<int> copyList(listTest);

    for (auto i = listTest.begin(), copyi = copyList.begin(); i != listTest.end(); ++i, ++copyi) 
    {
        EXPECT_EQ(*i, *copyi);
    }
}

auto f() {
    LinkedList<int> listTest;
    listTest.push_back(1);
    listTest.push_back(0);
    listTest.push_back(-345);

    return listTest;
}

TEST(LinkedList, ConstructorMovingTest) 
{
    LinkedList<int> copyList(f());

    auto iter = copyList.begin();
    EXPECT_EQ(*(iter++), 1);
    EXPECT_EQ(*(iter++), 0);
    EXPECT_EQ(*iter, -345);
}

TEST(LinkedList, ConstructorAssigmentCopyTest) 
{
    LinkedList<int> listTest;
    listTest.push_back(10);
    listTest.push_front(9);
    listTest.push_back(11);
    listTest.push_back(12);
    listTest.push_front(8);

    LinkedList<int> copyList;

    copyList = listTest;

    auto copyIter = copyList.begin();
    for (auto iter = listTest.begin(); iter != listTest.end(); ++iter) 
    {
        EXPECT_EQ(*iter, *(copyIter++));
    }
}

TEST(LinkedList, ConstructorAssigmentMovingTest) 
{
    LinkedList<int> copyList;

    copyList = f();

    auto iter = copyList.begin();
    EXPECT_EQ(*(iter++), 1);
    EXPECT_EQ(*(iter++), 0);
    EXPECT_EQ(*iter, -345);
}

TEST(LinkedList, EmptyTest) 
{
    LinkedList<int> listTest;

    EXPECT_TRUE(listTest.empty());

    listTest.push_back(10);
    EXPECT_FALSE(listTest.empty());

    listTest.remove(10);
    EXPECT_TRUE(listTest.empty());
}

TEST(LinkedList, InsertTest)
{
    LinkedList<int> listTest;
   
    LinkedList<int>::iterator i = listTest.begin();
    listTest.insert(++i, 10);
    listTest.insert(--i, 20);
    listTest.insert(--i, 30);
    listTest.insert(++i, 40);
    listTest.insert(--i, 50);
    listTest.insert(++i, 60);

    LinkedList<int>::iterator j = listTest.begin();

    EXPECT_EQ(*(++j), 20);
    EXPECT_EQ(*(++j), 50);
    EXPECT_EQ(*(++j), 40);
    EXPECT_EQ(*(++j), 60);
    EXPECT_EQ(*(++j), 10);
    EXPECT_EQ(*(++j), 0);
    EXPECT_EQ(*(++j), 30); 
}

TEST(LinkedList, PushBacktest)
{
    LinkedList<int> listTest;
    listTest.push_back(10);
    listTest.push_back(20);
    listTest.push_back(30);
    listTest.push_back(40);
    listTest.push_back(50);
    listTest.push_back(60);
    listTest.push_back(70);
    listTest.push_back(80);
    listTest.push_back(90);
    listTest.push_back(100);

    LinkedList<int>::iterator i = listTest.begin();

    EXPECT_EQ(*(i++), 10);
    EXPECT_EQ(*(i++), 20);
    EXPECT_EQ(*(i++), 30);
    EXPECT_EQ(*(i++), 40);
    EXPECT_EQ(*(i++), 50);
    EXPECT_EQ(*(i++), 60);
    EXPECT_EQ(*(i++), 70);
    EXPECT_EQ(*(i++), 80);
    EXPECT_EQ(*(i++), 90);
    EXPECT_EQ(*(i++), 100);
}

TEST(LinkedList, PushFrontTest) 
{
    LinkedList<int> listTest;
    listTest.push_front(10);
    listTest.push_front(11);
    listTest.push_front(12);

    int answer = 12;

    for (LinkedList<int>::iterator i = listTest.begin(); i != listTest.end(); ++i) 
    {
        EXPECT_EQ(*i, (answer--));
    }
}

TEST(LinkedList, PushTest) 
{
    LinkedList<int> listTest;
    listTest.push_back(10);
    listTest.push_front(9);
    listTest.push_back(11);
    listTest.push_back(12);
    listTest.push_front(8);

    int answer = 8;

    for (LinkedList<int>::iterator i = listTest.begin(); i != listTest.end(); ++i)
    {
        EXPECT_EQ(*i, (answer++));
    }
}

TEST(LinkedList, EraseTest) 
{
    LinkedList<int> listTest;
    listTest.push_back(10);
    listTest.push_front(9);
    listTest.push_back(11);
    listTest.push_back(-19);
    listTest.push_back(12);
    listTest.push_front(8);
    listTest.push_front(-19);

    for (LinkedList<int>::iterator i = listTest.begin(); i != listTest.end(); ++i) 
    {
        if (*i == -19) listTest.erase(i);
    }

    int answer = 8;
    for (LinkedList<int>::iterator i = listTest.begin(); i != listTest.end(); ++i) 
    {
        EXPECT_EQ(*i, (answer++));
    }
}

TEST(LinkedList, RemoveTest) 
{
    LinkedList<int> listTest;

    listTest.push_back(10);
    listTest.push_front(9);
    listTest.push_back(11);

    listTest.remove(11);

    int answer = 9;
    for (LinkedList<int>::iterator i = listTest.begin(); i != listTest.end(); ++i) 
    {
        EXPECT_EQ(*i, (answer++));
    }
}

TEST(LinkedList, ReverseTest) 
{
    LinkedList<int> listTest;
    listTest.push_back(10);
    listTest.push_front(9);
    listTest.push_back(11);
    listTest.push_back(12);
    listTest.push_front(8);

    int answer = 8;
    for (LinkedList<int>::iterator i = listTest.begin(); i != listTest.end(); ++i) 
    {
        EXPECT_EQ(*i, (answer++));
    }

    listTest.reverse();

    answer = 12;
    for (LinkedList<int>::reverse_iterator i = listTest.rbegin(); i != listTest.rend(); ++i) 
    {
        EXPECT_EQ(*i, (answer--));
    }
}

TEST(LinkedListConst, ConstructorCopyTest) 
{
    LinkedList<double> listTest;
    listTest.push_back(12.3);
    listTest.push_back(9.1);
    listTest.push_back(-99.09);

    const LinkedList<double> copyList(listTest);

    auto copyi = copyList.rbegin();
    auto i = listTest.rbegin();
    for (; i != listTest.rend(); ++i) 
    {
        EXPECT_EQ(*i, *(copyi++));
    }
}