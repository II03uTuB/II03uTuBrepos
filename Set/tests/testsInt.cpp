#include <gmock/gmock.h>


#include "../src/Set.h"
#include "../src/ComparisonElem.h"


using namespace std;


TEST(IntSet, ConstructorWithoutParametersTest)
{
    Set <int> setTest1;
    Set <int> setTest2;
    Set <int> setTest3;
    Set <int> setTest4;
    Set <int> setTest5;

    EXPECT_EQ(setTest1.capacity(), 0);
    EXPECT_EQ(setTest2.capacity(), 0);
    EXPECT_EQ(setTest3.capacity(), 0);
    EXPECT_EQ(setTest4.capacity(), 0);
    EXPECT_EQ(setTest5.capacity(), 0);

    EXPECT_EQ(setTest1.size(), 0);
    EXPECT_EQ(setTest2.size(), 0);
    EXPECT_EQ(setTest3.size(), 0);
    EXPECT_EQ(setTest4.size(), 0);
    EXPECT_EQ(setTest5.size(), 0);
}

TEST(IntSet, ConstructorCopyTest)
{
    Set <int> setTest(8);
    setTest.addElement(32);
    setTest.addElement(26);
    setTest.addElement(34);
    setTest.addElement(85);
    setTest.addElement(45);
    setTest.addElement(65);
    setTest.addElement(3658);
    setTest.addElement(98);

    Set <int> setCopyTest(setTest);

    EXPECT_EQ(setTest.capacity(), setCopyTest.capacity());
    EXPECT_EQ(setTest.size(), setCopyTest.size());

    for(int i = 0; i < setTest.size(); ++i)
    {
        EXPECT_EQ(setTest[i], setCopyTest[i]);
    }
}

TEST(IntSet, ConstructorMovementTest)
{
    Set <int> setTest(8);
    setTest.addElement(32);
    setTest.addElement(26);
    setTest.addElement(34);
    setTest.addElement(85);
    setTest.addElement(45);
    setTest.addElement(65);
    setTest.addElement(3658);
    setTest.addElement(98);

    Set <int> setMovementTest(setTest);

    EXPECT_EQ(setTest.capacity(),setMovementTest.capacity());
    EXPECT_EQ(setTest.size(), setMovementTest.size());

    for(int i = 0; i < setTest.size(); ++i)
    {
        EXPECT_EQ(setTest[i], setMovementTest[i]);
    }
}

TEST(IntSet, PushTest)
{
    Set <int> set(3);

    EXPECT_EQ(set.capacity(), 3);

    set.addElement(32);
    set.addElement(26);
    set.addElement(34);

    EXPECT_EQ(set.capacity(), 3);

    EXPECT_EQ(set[0], 32);
    EXPECT_EQ(set[1], 26);
    EXPECT_EQ(set[2], 34);
}

TEST(IntSet, PushTestErrorParam)
{
    Set <int> setTest1;

    EXPECT_THROW(setTest1.addElement(12), ErrorParam);

    Set <int> setTest2(4);
    setTest2.addElement(32);
    setTest2.addElement(26);
    setTest2.addElement(34);
    setTest2.addElement(85);

    EXPECT_THROW(setTest2.addElement(26), ErrorParam);
}

TEST(IntSet, popPredTest)
{
    Set <int> setTest1(8);
    setTest1.addElement(10);
    setTest1.addElement(20);
    setTest1.addElement(30);
    setTest1.addElement(40);
    setTest1.addElement(48);
    setTest1.addElement(60);
    setTest1.addElement(3658);
    setTest1.addElement(98);

    setTest1.popPred(GreaterThan);

    EXPECT_EQ(setTest1[0], 10);
    EXPECT_EQ(setTest1[1], 20);
    EXPECT_EQ(setTest1[2], 30);
    EXPECT_EQ(setTest1[3], 40);
    EXPECT_EQ(setTest1[4], 48);

    Set <int> setTest2(8);
    setTest2.addElement(10);
    setTest2.addElement(20);
    setTest2.addElement(21);
    setTest2.addElement(29);
    setTest2.addElement(48);
    setTest2.addElement(60);
    setTest2.addElement(3658);
    setTest2.addElement(98);

    setTest2.popPred(LessThan);
 
    EXPECT_EQ(setTest2[0], 48);
    EXPECT_EQ(setTest2[1], 60);
    EXPECT_EQ(setTest2[2], 3658);
    EXPECT_EQ(setTest2[3], 98);
}

TEST(IntSet, FindByComparisonTest)
{
    Set <int> setTest1(15);
    setTest1.addElement(25);
    setTest1.addElement(-250);
    setTest1.addElement(65);
    setTest1.addElement(1);

    EXPECT_EQ(setTest1.find(25), 0);
    EXPECT_EQ(setTest1.find(-250), 1);
    EXPECT_EQ(setTest1.find(65), 2);
    EXPECT_EQ(setTest1.find(1), 3);
    EXPECT_EQ(setTest1.find(250), -1);//не найдено!
}

TEST(IntSet, FindPredTest)
{
    Set <int> setTest1(15);
    findEven <int> find;
    setTest1.addElement(250);
    setTest1.addElement(-2732);
    setTest1.addElement(6987);
    setTest1.addElement(2345);

    setTest1.findPred(find);//ищем четные значения

    EXPECT_EQ(setTest1[0], 250);
    EXPECT_EQ(setTest1[1], -2732);
}

TEST(IntSet, AssignmentWithCopyTest)
{
    Set <int> setTest1(8);
    setTest1.addElement(32);
    setTest1.addElement(26);
    setTest1.addElement(34);
    setTest1.addElement(85);
    setTest1.addElement(45);
    setTest1.addElement(65);
    setTest1.addElement(3658);
    setTest1.addElement(98);

    Set <int> setTest2(8);
    setTest2.addElement(65);
    setTest2.addElement(-3456);
    setTest2.addElement(-23);
    setTest2.addElement(-2);
    setTest2.addElement(-14256);
    setTest2.addElement(36);
    setTest2.addElement(23);
    setTest2.addElement(-8);

    Set <int> AssigmentWithCopyTest(30);
    AssigmentWithCopyTest = setTest1 = setTest2 = setTest2;

    EXPECT_EQ(AssigmentWithCopyTest.capacity(), 30);
    EXPECT_EQ(AssigmentWithCopyTest.size(), 8);

    for(int i = 0; i < setTest1.size(); ++i)
    {
        EXPECT_EQ(AssigmentWithCopyTest[i],setTest1[i]);
    }

    for(int i = 0; i < setTest2.size(); ++i)
    {
        EXPECT_EQ(AssigmentWithCopyTest[i],setTest2[i]);
    }
}

TEST(IntSet, AssignmentWithCopyTestErrorParam)
{
    Set <int> setTest1(8);
    setTest1.addElement(32);
    setTest1.addElement(26);
    setTest1.addElement(34);
    setTest1.addElement(85);

    Set <int> AssigmentWithCopyTest(1);

    EXPECT_THROW(AssigmentWithCopyTest = setTest1, ErrorParam);
}

TEST(IntSet, AssignmentWithMovementTest)
{
    Set <int> setTest1(5);
    setTest1.addElement(-233);
    setTest1.addElement(35);
    setTest1.addElement(867);
    setTest1.addElement(543);

    Set <int> setTest2(20);

    Set <int> AssignmentWithMovement(35);
    AssignmentWithMovement.addElement(-346);
    AssignmentWithMovement.addElement(21);
    AssignmentWithMovement.addElement(88);

    setTest1 = AssignmentWithMovement;
    setTest2 = AssignmentWithMovement;

    EXPECT_EQ(setTest1.capacity(), 5);
    EXPECT_EQ(setTest1.size(), 3);
    EXPECT_EQ(setTest1[0], -346);
    EXPECT_EQ(setTest1[1], 21);
    EXPECT_EQ(setTest1[2], 88);

    EXPECT_EQ(setTest2.capacity(), 20);
    EXPECT_EQ(setTest2.size(), 3);
    EXPECT_EQ(setTest2[0], -346);
    EXPECT_EQ(setTest2[1], 21);
    EXPECT_EQ(setTest2[2], 88);
}

TEST(IntSet, AssignmentWithMovementTestErrorParam)
{
    Set <int> setTest1(1);

    Set <int> AssignmentWithMovement(3);
    AssignmentWithMovement.addElement(23);
    AssignmentWithMovement.addElement(54);

    EXPECT_THROW(setTest1 = AssignmentWithMovement, ErrorParam);
}

TEST(IntSet, AssociationTest)
{
    Set <int> setTest1(4);
    setTest1.addElement(32);
    setTest1.addElement(26);
    setTest1.addElement(34);
    setTest1.addElement(85);

    Set <int> setTest2(3);
    setTest2.addElement(76);
    setTest2.addElement(32);
    setTest2.addElement(64);

    Set <int> AssociationSet = setTest1 + setTest2;
    
    EXPECT_EQ(AssociationSet.capacity(), 7);
    EXPECT_EQ(AssociationSet.size(), 6);
    EXPECT_EQ(AssociationSet[0], 32);
    EXPECT_EQ(AssociationSet[1], 26);
    EXPECT_EQ(AssociationSet[2], 34);
    EXPECT_EQ(AssociationSet[3], 85);
    EXPECT_EQ(AssociationSet[4], 76);
    EXPECT_EQ(AssociationSet[5], 64);
}

TEST(IntSet, IntersectionTest)
{
    Set <int> setTest1(6);
    setTest1.addElement(32);
    setTest1.addElement(26);
    setTest1.addElement(-34);
    setTest1.addElement(85);

    Set <int> setTest2(7);
    setTest2.addElement(32);
    setTest2.addElement(-34);
    setTest2.addElement(85);
    setTest2.addElement(-987);
    setTest2.addElement(-654);
    setTest2.addElement(2);

    Set <int> IntersectionSet = setTest1 * setTest2;
    EXPECT_EQ(IntersectionSet.size(), 3);
    EXPECT_EQ(IntersectionSet[0], 32);
    EXPECT_EQ(IntersectionSet[1], 26);
    EXPECT_EQ(IntersectionSet[2], -34);
}

TEST(IntSet, DifferenceTest)
{
    Set <int> setTest1(6);
    setTest1.addElement(32);
    setTest1.addElement(26);
    setTest1.addElement(-34);
    setTest1.addElement(85);

    Set <int> setTest2(7);
    setTest2.addElement(32);
    setTest2.addElement(-34);
    setTest2.addElement(85);
    setTest2.addElement(-987);
    setTest2.addElement(-654);
    setTest2.addElement(2);

    Set <int> DifferenceSet = setTest2 - setTest1;
    EXPECT_EQ(DifferenceSet.capacity(), setTest1.capacity());
    EXPECT_EQ(DifferenceSet.size(), 3);
    EXPECT_EQ(DifferenceSet[0], -987);
    EXPECT_EQ(DifferenceSet[1], -654);
    EXPECT_EQ(DifferenceSet[2], 2);
}
