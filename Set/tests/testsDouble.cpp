#include <gmock/gmock.h>


#include "../src/Set.h"


using namespace std;


TEST(DoubleSet, ConstructorWithoutParametersTest)
{
    Set <double> setTest1;
    Set <double> setTest2;
    Set <double> setTest3;
    Set <double> setTest4;
    Set <double> setTest5;

    ASSERT_EQ(setTest1.capacity(), 0);
    ASSERT_EQ(setTest2.capacity(), 0);
    ASSERT_EQ(setTest3.capacity(), 0);
    ASSERT_EQ(setTest4.capacity(), 0);
    ASSERT_EQ(setTest5.capacity(), 0);

    ASSERT_EQ(setTest1.size(), 0);
    ASSERT_EQ(setTest2.size(), 0);
    ASSERT_EQ(setTest3.size(), 0);
    ASSERT_EQ(setTest4.size(), 0);
    ASSERT_EQ(setTest5.size(), 0);
}

TEST(DoubleSet, ConstructorCopyTest)
{
    Set <double> setTest(8);
    setTest.addElement(32.342);
    setTest.addElement(26.124);
    setTest.addElement(34.634);
    setTest.addElement(-85.54);
    setTest.addElement(45.5);
    setTest.addElement(65.96);
    setTest.addElement(3658.45);
    setTest.addElement(-98.21);

    Set <double> setCopyTest(setTest);

    ASSERT_EQ(setTest.capacity(), setCopyTest.capacity());
    ASSERT_EQ(setTest.size(), setCopyTest.size());

    for(int i = 0; i < setTest.size(); ++i)
    {
        EXPECT_DOUBLE_EQ(setTest[i], setCopyTest[i]);
    }
}

TEST(DoubleSet, ConstructorMovementTest)
{
    Set <double> setTest(8);
    setTest.addElement(32.342);
    setTest.addElement(26.124);
    setTest.addElement(34.634);
    setTest.addElement(-85.54);
    setTest.addElement(45.5);
    setTest.addElement(65.96);
    setTest.addElement(3658.45);
    setTest.addElement(-98.21);

    Set <double> setMovementTest(setTest);

    ASSERT_EQ(setTest.capacity(),setMovementTest.capacity());
    ASSERT_EQ(setTest.size(), setMovementTest.size());

    for(int i = 0; i < setTest.size(); ++i)
    {
        EXPECT_DOUBLE_EQ(setTest[i], setMovementTest[i]);
    }
}

TEST(DoubleSet, PushTest)
{
    Set <double> set(3);

    ASSERT_EQ(set.capacity(), 3);

    set.addElement(32.478);
    set.addElement(-26.214);
    set.addElement(34.08);

    ASSERT_EQ(set.capacity(), 3);

    EXPECT_DOUBLE_EQ(set[0], 32.478);
    EXPECT_DOUBLE_EQ(set[1], -26.214);
    EXPECT_DOUBLE_EQ(set[2], 34.08);
}

TEST(DoubleSet, PushTestErrorParam)
{
    Set <double> setTest1;

    EXPECT_THROW(setTest1.addElement(12), ErrorParam);

    Set <double> setTest2(4);
    setTest2.addElement(32.234);
    setTest2.addElement(-26.54);
    setTest2.addElement(34.005);
    setTest2.addElement(85.2354);

    EXPECT_THROW(setTest2.addElement(26), ErrorParam);
}

TEST(DoubleSet, popPredTest)
{
    Set <double> setTest1(8);
    setTest1.addElement(10.532);
    setTest1.addElement(20.1346);
    setTest1.addElement(30.134);
    setTest1.addElement(40.8761);
    setTest1.addElement(48.1763);
    setTest1.addElement(60.165);
    setTest1.addElement(3658.4262);
    setTest1.addElement(98.236);

    setTest1.popPred(GreaterThan);

    EXPECT_EQ(setTest1[0], 10.532);
    EXPECT_EQ(setTest1[1], 20.1346);
    EXPECT_EQ(setTest1[2], 30.134);
    EXPECT_EQ(setTest1[3], 40.8761);
    EXPECT_EQ(setTest1[4], 48.1763);

    Set <double> setTest2(8);
    setTest2.addElement(10.532);
    setTest2.addElement(20.1346);
    setTest2.addElement(30.134);
    setTest2.addElement(40.8761);
    setTest2.addElement(48.1763);
    setTest2.addElement(60.165);
    setTest2.addElement(3658.4262);
    setTest2.addElement(98.236);

    setTest2.popPred(LessThan);
    EXPECT_EQ(setTest2[0], 30.134);
    EXPECT_EQ(setTest2[1], 40.8761);
    EXPECT_EQ(setTest2[2], 48.1763);
    EXPECT_EQ(setTest2[3], 60.165);
    EXPECT_EQ(setTest2[4], 3658.4262);
    EXPECT_EQ(setTest2[5], 98.236);
}

TEST(DoubleSet, FindByComparisonTest)
{
    Set <double> setTest1(15);
    setTest1.addElement(25.23);
    setTest1.addElement(-250.54);
    setTest1.addElement(65.01);
    setTest1.addElement(1.09);

    EXPECT_EQ(setTest1.find(25.23), 0);
    EXPECT_EQ(setTest1.find(-250.54), 1);
    EXPECT_EQ(setTest1.find(65.01), 2);
    EXPECT_EQ(setTest1.find(1.09), 3);
    EXPECT_EQ(setTest1.find(250), -1);//не найдено!
}

TEST(DoubleSet, FindPredTest)
{
    Set <double> setTest1(15);
    findEven <int> find;
    setTest1.addElement(250);
    setTest1.addElement(-2732);
    setTest1.addElement(6987);
    setTest1.addElement(2345);

    setTest1.findPred(find);//ищем четные значения

    EXPECT_EQ(setTest1[0], 250);
    EXPECT_EQ(setTest1[1], -2732);
}

TEST(DoubleSet, AssignmentWithCopyTest)
{
    Set <double> setTest1(8);
    setTest1.addElement(32.432);
    setTest1.addElement(-23426.643);
    setTest1.addElement(34.32);
    setTest1.addElement(85.962);
    setTest1.addElement(45.752);
    setTest1.addElement(65.01);
    setTest1.addElement(3658.123);
    setTest1.addElement(98.07);

    Set <double> setTest2(8);
    setTest2.addElement(65.2134);
    setTest2.addElement(-3456.532);
    setTest2.addElement(-23.12);
    setTest2.addElement(-2.23);
    setTest2.addElement(-14256.123);
    setTest2.addElement(36.75);
    setTest2.addElement(23.765);
    setTest2.addElement(-8.75);

    Set <double> AssigmentWithCopyTest(30);
    AssigmentWithCopyTest = setTest1 = setTest2 = setTest2;

    EXPECT_EQ(AssigmentWithCopyTest.capacity(), 30);
    EXPECT_EQ(AssigmentWithCopyTest.size(), 8);

    for(int i = 0; i < setTest1.size(); ++i)
    {
        EXPECT_DOUBLE_EQ(AssigmentWithCopyTest[i],setTest1[i]);
    }

    for(int i = 0; i < setTest2.size(); ++i)
    {
        EXPECT_DOUBLE_EQ(AssigmentWithCopyTest[i],setTest2[i]);
    }
}

TEST(DoubleSet, AssignmentWithCopyTestErrorParam)
{
    Set <double> setTest1(8);
    setTest1.addElement(32.532);
    setTest1.addElement(26.09);
    setTest1.addElement(-34);
    setTest1.addElement(85.4211);

    Set <double> AssigmentWithCopyTest(1);

    EXPECT_THROW(AssigmentWithCopyTest = setTest1, ErrorParam);
}

TEST(DoubleSet, AssignmentWithMovementTest)
{
    Set <double> setTest1(5);
    setTest1.addElement(-233.04);
    setTest1.addElement(35.2354);
    setTest1.addElement(867.53);
    setTest1.addElement(543.321);

    Set <double> setTest2(20);

    Set <double> AssignmentWithMovement(35);
    AssignmentWithMovement.addElement(346.43);
    AssignmentWithMovement.addElement(21.98);
    AssignmentWithMovement.addElement(88.77);

    setTest1 = AssignmentWithMovement;
    setTest2 = AssignmentWithMovement;

    EXPECT_EQ(setTest1.capacity(), 5);
    EXPECT_EQ(setTest1.size(), 3);
    EXPECT_DOUBLE_EQ(setTest1[0], 346.43000000000001);
    EXPECT_DOUBLE_EQ(setTest1[1], 21.98);
    EXPECT_DOUBLE_EQ(setTest1[2], 88.769999999999996);

    EXPECT_DOUBLE_EQ(setTest2.capacity(), 20);
    EXPECT_DOUBLE_EQ(setTest2.size(), 3);
    EXPECT_DOUBLE_EQ(setTest2[0], 346.43000000000001);
    EXPECT_DOUBLE_EQ(setTest2[1], 21.98);
    EXPECT_DOUBLE_EQ(setTest2[2], 88.769999999999996);
}

TEST(DoubleSet, AssignmentWithMovementTestErrorParam)
{
    Set <double> setTest1(1);

    Set <double> AssignmentWithMovement(3);
    AssignmentWithMovement.addElement(23.76);
    AssignmentWithMovement.addElement(54.8765);

    EXPECT_THROW(setTest1 = AssignmentWithMovement, ErrorParam);
}

TEST(DoubleSet, AssociationTest)
{
    
    Set <double> setTest1(4);
    setTest1.addElement(32.456);
    setTest1.addElement(26.8921);
    setTest1.addElement(34.776);
    setTest1.addElement(85.4321);

    Set <double> setTest2(3);
    setTest2.addElement(76.98);
    setTest2.addElement(32.456);
    setTest2.addElement(64.088);

    Set <double> AssociationSet = setTest1 + setTest2;
    
    EXPECT_EQ(AssociationSet.capacity(), 7);
    EXPECT_EQ(AssociationSet.size(), 6);
    EXPECT_DOUBLE_EQ(AssociationSet[0], 32.456000000000003);
    EXPECT_DOUBLE_EQ(AssociationSet[1], 26.892099999999999);
    EXPECT_DOUBLE_EQ(AssociationSet[2], 34.776000000000003);
    EXPECT_DOUBLE_EQ(AssociationSet[3], 85.432100000000005);
    EXPECT_DOUBLE_EQ(AssociationSet[4], 76.980000000000004);
    EXPECT_DOUBLE_EQ(AssociationSet[5], 64.087999999999994);
}

TEST(DoubleSet, IntersectionTest)
{
    Set <double> setTest1(6);
    setTest1.addElement(32.546);
    setTest1.addElement(26.7654);
    setTest1.addElement(-34.629);
    setTest1.addElement(85.9876564);

    Set <double> setTest2(7);
    setTest2.addElement(32.546);
    setTest2.addElement(-34.629);
    setTest2.addElement(85.9876564);
    setTest2.addElement(-987.865);
    setTest2.addElement(-654.0004);
    setTest2.addElement(2.3546);

    Set <double> IntersectionSet = setTest1 * setTest2;
    EXPECT_EQ(IntersectionSet.size(), 3);
    EXPECT_DOUBLE_EQ(IntersectionSet[0], 32.545999999999999);
    EXPECT_DOUBLE_EQ(IntersectionSet[1], 26.7654);
    EXPECT_DOUBLE_EQ(IntersectionSet[2], -34.628999999999998);
}

TEST(DoubleSet, DifferenceTest)
{
    Set <double> setTest1(6);
    setTest1.addElement(32.81);
    setTest1.addElement(26.51);
    setTest1.addElement(-34.15);
    setTest1.addElement(85.16);

    Set <double> setTest2(7);
    setTest2.addElement(32.81);
    setTest2.addElement(-34.15);
    setTest2.addElement(85.16);
    setTest2.addElement(-987.06);
    setTest2.addElement(654.78);
    setTest2.addElement(2.23);

    Set <double> DifferenceSet = setTest2 - setTest1;
    EXPECT_EQ(DifferenceSet.capacity(), setTest1.capacity());
    EXPECT_EQ(DifferenceSet.size(), 3);
    EXPECT_DOUBLE_EQ(DifferenceSet[0], -987.05999999999995);
    EXPECT_DOUBLE_EQ(DifferenceSet[1], 654.77999999999997);
    EXPECT_DOUBLE_EQ(DifferenceSet[2], 2.23);
}
