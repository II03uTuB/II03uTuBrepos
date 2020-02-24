#include <vector>
#include <list>
#include <gmock/gmock.h>


#include "../src/BinarySearch.h"


TEST(BinarySearch,vectorTests)
{
    vector<int> testVector1 = {1,2,3,4,5,6,7,8,9,10}; //четное число элементов

    EXPECT_EQ(*BinarySearch(testVector1.begin(), testVector1.end(), 1), 1);
    EXPECT_EQ(*BinarySearch(testVector1.begin(), testVector1.end(), 2), 2);
    EXPECT_EQ(*BinarySearch(testVector1.begin(), testVector1.end(), 3), 3);
    EXPECT_EQ(*BinarySearch(testVector1.begin(), testVector1.end(), 4), 4);
    EXPECT_EQ(*BinarySearch(testVector1.begin(), testVector1.end(), 5), 5);
    EXPECT_EQ(*BinarySearch(testVector1.begin(), testVector1.end(), 6), 6);
    EXPECT_EQ(*BinarySearch(testVector1.begin(), testVector1.end(), 7), 7);
    EXPECT_EQ(*BinarySearch(testVector1.begin(), testVector1.end(), 8), 8);
    EXPECT_EQ(*BinarySearch(testVector1.begin(), testVector1.end(), 9), 9);
    EXPECT_EQ(*BinarySearch(testVector1.begin(), testVector1.end(), 10), 10);

    vector<int> testVector2 = {1,2,3,4,5,6,7}; //нечетное число элементов

    EXPECT_EQ(*BinarySearch(testVector2.begin(), testVector2.end(), 1), 1);
    EXPECT_EQ(*BinarySearch(testVector2.begin(), testVector2.end(), 2), 2);
    EXPECT_EQ(*BinarySearch(testVector2.begin(), testVector2.end(), 3), 3);
    EXPECT_EQ(*BinarySearch(testVector2.begin(), testVector2.end(), 4), 4);
    EXPECT_EQ(*BinarySearch(testVector2.begin(), testVector2.end(), 5), 5);
    EXPECT_EQ(*BinarySearch(testVector2.begin(), testVector2.end(), 6), 6);
    EXPECT_EQ(*BinarySearch(testVector2.begin(), testVector2.end(), 7), 7);

    vector<int> testVector3 = {-5,-4,-3,-2,-1,0,1,2,3,4}; //добавим отрицательные числа

    EXPECT_EQ(*BinarySearch(testVector3.begin(), testVector3.end(), -5), -5);
    EXPECT_EQ(*BinarySearch(testVector3.begin(), testVector3.end(), -4), -4);
    EXPECT_EQ(*BinarySearch(testVector3.begin(), testVector3.end(), -3), -3);
    EXPECT_EQ(*BinarySearch(testVector3.begin(), testVector3.end(), -2), -2);
    EXPECT_EQ(*BinarySearch(testVector3.begin(), testVector3.end(), -1), -1);
    EXPECT_EQ(*BinarySearch(testVector3.begin(), testVector3.end(), 0), 0);
    EXPECT_EQ(*BinarySearch(testVector3.begin(), testVector3.end(), 1), 1);
    EXPECT_EQ(*BinarySearch(testVector3.begin(), testVector3.end(), 2), 2);
    EXPECT_EQ(*BinarySearch(testVector3.begin(), testVector3.end(), 3), 3);
    EXPECT_EQ(*BinarySearch(testVector3.begin(), testVector3.end(), 4), 4);

    vector<int> testVector4 = {10}; //вектор из одного элемента

    EXPECT_EQ(*BinarySearch(testVector4.begin(), testVector4.end(), 10), 10);

    vector<int> testVector5 = {10, 20}; //вектор из двух элементов

    EXPECT_EQ(*BinarySearch(testVector5.begin(), testVector5.end(), 10), 10);
    EXPECT_EQ(*BinarySearch(testVector5.begin(), testVector5.end(), 20), 20);

    vector<int> testVector6 = {10, 20, 30}; //ищем элемент, которого нет

    EXPECT_EQ(*BinarySearch(testVector6.begin(), testVector6.end(), 1), 10);
    EXPECT_EQ(*BinarySearch(testVector6.begin(), testVector6.end(), 20), 20);
    EXPECT_EQ(*BinarySearch(testVector6.begin(), testVector6.end(), 0), 10);
    EXPECT_EQ(*BinarySearch(testVector6.begin(), testVector6.end(), 25), 30);

    vector<int> testVector7 ={0};

    EXPECT_EQ(*BinarySearch(testVector7.begin(), testVector7.end(), 12), 0);
    
}
TEST(RecursiveBinarySearch,vectorTests)
{
    vector<int> testVector1 = {1,2,3,4,5,6,7,8,9,10}; //четное число элементов

    EXPECT_EQ(*RecursiveBinarySearch(testVector1.begin(), testVector1.end(), 1), 1);
    EXPECT_EQ(*RecursiveBinarySearch(testVector1.begin(), testVector1.end(), 2), 2);
    EXPECT_EQ(*RecursiveBinarySearch(testVector1.begin(), testVector1.end(), 3), 3);
    EXPECT_EQ(*RecursiveBinarySearch(testVector1.begin(), testVector1.end(), 4), 4);
    EXPECT_EQ(*RecursiveBinarySearch(testVector1.begin(), testVector1.end(), 5), 5);
    EXPECT_EQ(*RecursiveBinarySearch(testVector1.begin(), testVector1.end(), 6), 6);
    EXPECT_EQ(*RecursiveBinarySearch(testVector1.begin(), testVector1.end(), 7), 7);
    EXPECT_EQ(*RecursiveBinarySearch(testVector1.begin(), testVector1.end(), 8), 8);
    EXPECT_EQ(*RecursiveBinarySearch(testVector1.begin(), testVector1.end(), 9), 9);
    EXPECT_EQ(*RecursiveBinarySearch(testVector1.begin(), testVector1.end(), 10), 10);

    vector<int> testVector2 = {1,2,3,4,5,6,7}; //нечетное число элементов

    EXPECT_EQ(*RecursiveBinarySearch(testVector2.begin(), testVector2.end(), 1), 1);
    EXPECT_EQ(*RecursiveBinarySearch(testVector2.begin(), testVector2.end(), 2), 2);
    EXPECT_EQ(*RecursiveBinarySearch(testVector2.begin(), testVector2.end(), 3), 3);
    EXPECT_EQ(*RecursiveBinarySearch(testVector2.begin(), testVector2.end(), 4), 4);
    EXPECT_EQ(*RecursiveBinarySearch(testVector2.begin(), testVector2.end(), 5), 5);
    EXPECT_EQ(*RecursiveBinarySearch(testVector2.begin(), testVector2.end(), 6), 6);
    EXPECT_EQ(*RecursiveBinarySearch(testVector2.begin(), testVector2.end(), 7), 7);

    vector<int> testVector3 = {-5,-4,-3,-2,-1,0,1,2,3,4}; //добавим отрицательные числа

    EXPECT_EQ(*RecursiveBinarySearch(testVector3.begin(), testVector3.end(), -5), -5);
    EXPECT_EQ(*RecursiveBinarySearch(testVector3.begin(), testVector3.end(), -4), -4);
    EXPECT_EQ(*RecursiveBinarySearch(testVector3.begin(), testVector3.end(), -3), -3);
    EXPECT_EQ(*RecursiveBinarySearch(testVector3.begin(), testVector3.end(), -2), -2);
    EXPECT_EQ(*RecursiveBinarySearch(testVector3.begin(), testVector3.end(), -1), -1);
    EXPECT_EQ(*RecursiveBinarySearch(testVector3.begin(), testVector3.end(), 0), 0);
    EXPECT_EQ(*RecursiveBinarySearch(testVector3.begin(), testVector3.end(), 1), 1);
    EXPECT_EQ(*RecursiveBinarySearch(testVector3.begin(), testVector3.end(), 2), 2);
    EXPECT_EQ(*RecursiveBinarySearch(testVector3.begin(), testVector3.end(), 3), 3);
    EXPECT_EQ(*RecursiveBinarySearch(testVector3.begin(), testVector3.end(), 4), 4);

    vector<int> testVector4 = {10}; //вектор из одного элемента

    EXPECT_EQ(*RecursiveBinarySearch(testVector4.begin(), testVector4.end(), 10), 10);

    vector<int> testVector5 = {10, 20}; //вектор из двух элементов

    EXPECT_EQ(*RecursiveBinarySearch(testVector5.begin(), testVector5.end(), 10), 10);
    EXPECT_EQ(*RecursiveBinarySearch(testVector5.begin(), testVector5.end(), 20), 20);

    vector<int> testVector6 = {10, 20, 30}; //ищем элемент, которого нет

    EXPECT_EQ(*RecursiveBinarySearch(testVector6.begin(), testVector6.end(), 1), 0);
    EXPECT_EQ(*RecursiveBinarySearch(testVector6.begin(), testVector6.end(), 20), 20);
    EXPECT_EQ(*RecursiveBinarySearch(testVector6.begin(), testVector6.end(), 0), 0);
    EXPECT_EQ(*RecursiveBinarySearch(testVector6.begin(), testVector6.end(), 25), 0);

}

TEST(BinarySearch,listTests)
{
    list<int> testList1 = {1,2,3,4,5,6,7,8,9,10}; //четное число элементов

    EXPECT_EQ(*BinarySearch(testList1.begin(), testList1.end(), 1), 1);
    EXPECT_EQ(*BinarySearch(testList1.begin(), testList1.end(), 2), 2);
    EXPECT_EQ(*BinarySearch(testList1.begin(), testList1.end(), 3), 3);
    EXPECT_EQ(*BinarySearch(testList1.begin(), testList1.end(), 4), 4);
    EXPECT_EQ(*BinarySearch(testList1.begin(), testList1.end(), 5), 5);
    EXPECT_EQ(*BinarySearch(testList1.begin(), testList1.end(), 6), 6);
    EXPECT_EQ(*BinarySearch(testList1.begin(), testList1.end(), 7), 7);
    EXPECT_EQ(*BinarySearch(testList1.begin(), testList1.end(), 8), 8);
    EXPECT_EQ(*BinarySearch(testList1.begin(), testList1.end(), 9), 9);
    EXPECT_EQ(*BinarySearch(testList1.begin(), testList1.end(), 10), 10);

    list<int> testList2 = {1,2,3,4,5,6,7}; //нечетное число элементов

    EXPECT_EQ(*BinarySearch(testList2.begin(), testList2.end(), 1), 1);
    EXPECT_EQ(*BinarySearch(testList2.begin(), testList2.end(), 2), 2);
    EXPECT_EQ(*BinarySearch(testList2.begin(), testList2.end(), 3), 3);
    EXPECT_EQ(*BinarySearch(testList2.begin(), testList2.end(), 4), 4);
    EXPECT_EQ(*BinarySearch(testList2.begin(), testList2.end(), 5), 5);
    EXPECT_EQ(*BinarySearch(testList2.begin(), testList2.end(), 6), 6);
    EXPECT_EQ(*BinarySearch(testList2.begin(), testList2.end(), 7), 7);

    list<int> testList3 = {-5,-4,-3,-2,-1,0,1,2,3,4}; //добавим отрицательные числа

    EXPECT_EQ(*BinarySearch(testList3.begin(), testList3.end(), -5), -5);
    EXPECT_EQ(*BinarySearch(testList3.begin(), testList3.end(), -4), -4);
    EXPECT_EQ(*BinarySearch(testList3.begin(), testList3.end(), -3), -3);
    EXPECT_EQ(*BinarySearch(testList3.begin(), testList3.end(), -2), -2);
    EXPECT_EQ(*BinarySearch(testList3.begin(), testList3.end(), -1), -1);
    EXPECT_EQ(*BinarySearch(testList3.begin(), testList3.end(), 0), 0);
    EXPECT_EQ(*BinarySearch(testList3.begin(), testList3.end(), 1), 1);
    EXPECT_EQ(*BinarySearch(testList3.begin(), testList3.end(), 2), 2);
    EXPECT_EQ(*BinarySearch(testList3.begin(), testList3.end(), 3), 3);
    EXPECT_EQ(*BinarySearch(testList3.begin(), testList3.end(), 4), 4);

    list<int> testList4 = {10}; //список из одного элемента

    EXPECT_EQ(*BinarySearch(testList4.begin(), testList4.end(), 10), 10);

    list<int> testList5 = {10, 20}; //список из двух элементов

    EXPECT_EQ(*BinarySearch(testList5.begin(), testList5.end(), 10), 10);
    EXPECT_EQ(*BinarySearch(testList5.begin(), testList5.end(), 20), 20);

    list<int> testList6 = {10, 20, 30}; 

    EXPECT_EQ(*BinarySearch(testList6.begin(), testList6.end(), 1), 10);
    EXPECT_EQ(*BinarySearch(testList6.begin(), testList6.end(), 20), 20);
    EXPECT_EQ(*BinarySearch(testList6.begin(), testList6.end(), 0), 10);
    EXPECT_EQ(*BinarySearch(testList6.begin(), testList6.end(), 25), 30);

    list<int> testList7; //пустой вектор

    EXPECT_EQ(*BinarySearch(testList7.begin(), testList7.end(), 0), 0);
    
}

TEST(RecursiveBinarySearch,listTests)
{
    list<int> testList1 = {1,2,3,4,5,6,7,8,9,10}; //четное число элементов

    EXPECT_EQ(*RecursiveBinarySearch(testList1.begin(), testList1.end(), 1), 1);
    EXPECT_EQ(*RecursiveBinarySearch(testList1.begin(), testList1.end(), 2), 2);
    EXPECT_EQ(*RecursiveBinarySearch(testList1.begin(), testList1.end(), 3), 3);
    EXPECT_EQ(*RecursiveBinarySearch(testList1.begin(), testList1.end(), 4), 4);
    EXPECT_EQ(*RecursiveBinarySearch(testList1.begin(), testList1.end(), 5), 5);
    EXPECT_EQ(*RecursiveBinarySearch(testList1.begin(), testList1.end(), 6), 6);
    EXPECT_EQ(*RecursiveBinarySearch(testList1.begin(), testList1.end(), 7), 7);
    EXPECT_EQ(*RecursiveBinarySearch(testList1.begin(), testList1.end(), 8), 8);
    EXPECT_EQ(*RecursiveBinarySearch(testList1.begin(), testList1.end(), 9), 9);
    EXPECT_EQ(*RecursiveBinarySearch(testList1.begin(), testList1.end(), 10), 10);

    list<int> testList2 = {1,2,3,4,5,6,7}; //нечетное число элементов

    EXPECT_EQ(*RecursiveBinarySearch(testList2.begin(), testList2.end(), 1), 1);
    EXPECT_EQ(*RecursiveBinarySearch(testList2.begin(), testList2.end(), 2), 2);
    EXPECT_EQ(*RecursiveBinarySearch(testList2.begin(), testList2.end(), 3), 3);
    EXPECT_EQ(*RecursiveBinarySearch(testList2.begin(), testList2.end(), 4), 4);
    EXPECT_EQ(*RecursiveBinarySearch(testList2.begin(), testList2.end(), 5), 5);
    EXPECT_EQ(*RecursiveBinarySearch(testList2.begin(), testList2.end(), 6), 6);
    EXPECT_EQ(*RecursiveBinarySearch(testList2.begin(), testList2.end(), 7), 7);

    list<int> testList3 = {-5,-4,-3,-2,-1,0,1,2,3,4}; //добавим отрицательные числа

    EXPECT_EQ(*RecursiveBinarySearch(testList3.begin(), testList3.end(), -5), -5);
    EXPECT_EQ(*RecursiveBinarySearch(testList3.begin(), testList3.end(), -4), -4);
    EXPECT_EQ(*RecursiveBinarySearch(testList3.begin(), testList3.end(), -3), -3);
    EXPECT_EQ(*RecursiveBinarySearch(testList3.begin(), testList3.end(), -2), -2);
    EXPECT_EQ(*RecursiveBinarySearch(testList3.begin(), testList3.end(), -1), -1);
    EXPECT_EQ(*RecursiveBinarySearch(testList3.begin(), testList3.end(), 0), 0);
    EXPECT_EQ(*RecursiveBinarySearch(testList3.begin(), testList3.end(), 1), 1);
    EXPECT_EQ(*RecursiveBinarySearch(testList3.begin(), testList3.end(), 2), 2);
    EXPECT_EQ(*RecursiveBinarySearch(testList3.begin(), testList3.end(), 3), 3);
    EXPECT_EQ(*RecursiveBinarySearch(testList3.begin(), testList3.end(), 4), 4);

    list<int> testList4 = {10}; //список из одного элемента

    EXPECT_EQ(*RecursiveBinarySearch(testList4.begin(), testList4.end(), 10), 10);

    list<int> testList5 = {10, 20}; //список из двух элементов

    EXPECT_EQ(*RecursiveBinarySearch(testList5.begin(), testList5.end(), 10), 10);
    EXPECT_EQ(*RecursiveBinarySearch(testList5.begin(), testList5.end(), 20), 20);

    list<int> testList6 = {10, 20, 30}; //ищем элемент, которого нет

    EXPECT_EQ(*RecursiveBinarySearch(testList6.begin(), testList6.end(), 1), 3);
    EXPECT_EQ(*RecursiveBinarySearch(testList6.begin(), testList6.end(), 20), 20);
    EXPECT_EQ(*RecursiveBinarySearch(testList6.begin(), testList6.end(), 0), 3);
    EXPECT_EQ(*RecursiveBinarySearch(testList6.begin(), testList6.end(), 25), 3);

    list<int> testList7 ={0};

    EXPECT_EQ(*RecursiveBinarySearch(testList7.begin(), testList7.end(), 12), 1);
}
