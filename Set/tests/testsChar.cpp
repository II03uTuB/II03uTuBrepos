#include <gmock/gmock.h>


#include "../src/Set.h"
#include "../src/ComparisonElem.h"


using namespace std;


TEST(CharSet, ConstructorWithoutParametersTest)
{
    Set <char> setTest1;
    Set <char> setTest2;
    Set <char> setTest3;
    Set <char> setTest4;
    Set <char> setTest5;

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

TEST(CharSet, ConstructorCopyTest)
{
    Set <char> setTest(8);
    setTest.addElement('D');
    setTest.addElement('e');
    setTest.addElement('K');
    setTest.addElement('M');
    setTest.addElement(':');
    setTest.addElement('3');
    setTest.addElement('c');
    setTest.addElement('L');

    Set <char> setCopyTest(setTest);

    ASSERT_EQ(setTest.capacity(), setCopyTest.capacity());
    ASSERT_EQ(setTest.size(), setCopyTest.size());

    for(int i = 0; i < setTest.size(); ++i)
    {
        EXPECT_EQ(setTest[i], setCopyTest[i]);
    }
}

TEST(CharSet, ConstructorMovementTest)
{
    Set <char> setTest(8);
    setTest.addElement('N');
    setTest.addElement('Z');
    setTest.addElement('/');
    setTest.addElement('4');
    setTest.addElement('s');
    setTest.addElement('B');
    setTest.addElement('M');
    setTest.addElement('c');

    Set <char> setMovementTest(setTest);

    ASSERT_EQ(setTest.capacity(),setMovementTest.capacity());
    ASSERT_EQ(setTest.size(), setMovementTest.size());

    for(int i = 0; i < setTest.size(); ++i)
    {
        EXPECT_EQ(setTest[i], setMovementTest[i]);
    }
}

TEST(CharSet, PushTest)
{
    Set <char> set(3);

    ASSERT_EQ(set.capacity(), 3);

    set.addElement('K');
    set.addElement('t');
    set.addElement('A');

    ASSERT_EQ(set.capacity(), 3);

    EXPECT_EQ(set[0], 'K');
    EXPECT_EQ(set[1], 't');
    EXPECT_EQ(set[2], 'A');
}

TEST(CharSet, PushTestErrorParam)
{
    Set <char> setTest1;

    EXPECT_THROW(setTest1.addElement(12), ErrorParam);

    Set <char> setTest2(4);
    setTest2.addElement('p');
    setTest2.addElement('N');
    setTest2.addElement('g');
    setTest2.addElement('?');

    EXPECT_THROW(setTest2.addElement(26), ErrorParam);
}

TEST(CharSet, popPredTest)
{
    Set <char> setTest1(8);
    setTest1.addElement('A');
    setTest1.addElement('a');
    setTest1.addElement('B');
    setTest1.addElement('b');
    setTest1.addElement('C');
    setTest1.addElement('c');
    setTest1.addElement('D');
    setTest1.addElement('d');

    setTest1.popPred(LowerCase);

    EXPECT_EQ(setTest1[0], 'A');
    EXPECT_EQ(setTest1[1], 'B');
    EXPECT_EQ(setTest1[2], 'C');
    EXPECT_EQ(setTest1[3], 'D');

    Set <char> setTest2(8);
    setTest2.addElement('A');
    setTest2.addElement('a');
    setTest2.addElement('B');
    setTest2.addElement('b');
    setTest2.addElement('C');
    setTest2.addElement('c');
    setTest2.addElement('D');
    setTest2.addElement('d');

    setTest2.popPred(UpperCase);
 
    EXPECT_EQ(setTest2[0], 'a');
    EXPECT_EQ(setTest2[1], 'b');
    EXPECT_EQ(setTest2[2], 'c');
    EXPECT_EQ(setTest2[3], 'd');
}

TEST(CharSet, FindPredTest)
{
    Set <char> setTest1(15);
    findNumber <int> find;
    setTest1.addElement('2');
    setTest1.addElement('6');
    setTest1.addElement('b');
    setTest1.addElement('S');

    setTest1.findPred(find);//ищем числа

    EXPECT_EQ(setTest1[0], '2');
    EXPECT_EQ(setTest1[1], '6');
}

TEST(CharSet, AssignmentWithCopyTest)
{
    Set <char> setTest1(8);
    setTest1.addElement('I');
    setTest1.addElement('J');
    setTest1.addElement('e');
    setTest1.addElement('1');
    setTest1.addElement('F');
    setTest1.addElement('w');
    setTest1.addElement('Q');
    setTest1.addElement('d');

    Set <char> setTest2(8);
    setTest2.addElement('y');
    setTest2.addElement('u');
    setTest2.addElement(';');
    setTest2.addElement('4');
    setTest2.addElement('7');
    setTest2.addElement('m');
    setTest2.addElement('n');
    setTest2.addElement('R');

    Set <char> AssigmentWithCopyTest(30);
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

TEST(CharSet, AssignmentWithCopyTestErrorParam)
{
    Set <char> setTest1(8);
    setTest1.addElement('.');
    setTest1.addElement('S');
    setTest1.addElement('e');
    setTest1.addElement('B');

    Set <char> AssigmentWithCopyTest(1);

    EXPECT_THROW(AssigmentWithCopyTest = setTest1, ErrorParam);
}

TEST(CharSet, AssignmentWithMovementTest)
{
    Set <char> setTest1(5);
    setTest1.addElement('2');
    setTest1.addElement('N');
    setTest1.addElement('r');
    setTest1.addElement('o');

    Set <char> setTest2(20);

    Set <char> AssignmentWithMovement(35);
    AssignmentWithMovement.addElement('M');
    AssignmentWithMovement.addElement('n');
    AssignmentWithMovement.addElement('Z');

    setTest1 = AssignmentWithMovement;
    setTest2 = AssignmentWithMovement;

    EXPECT_EQ(setTest1.capacity(), 5);
    EXPECT_EQ(setTest1.size(), 3);
    EXPECT_EQ(setTest1[0], 'M');
    EXPECT_EQ(setTest1[1], 'n');
    EXPECT_EQ(setTest1[2], 'Z');

    EXPECT_EQ(setTest2.capacity(), 20);
    EXPECT_EQ(setTest2.size(), 3);
    EXPECT_EQ(setTest2[0], 'M');
    EXPECT_EQ(setTest2[1], 'n');
    EXPECT_EQ(setTest2[2], 'Z');
}

TEST(CharSet, AssignmentWithMovementTestErrorParam)
{
    Set <char> setTest1(1);

    Set <char> AssignmentWithMovement(3);
    AssignmentWithMovement.addElement('k');
    AssignmentWithMovement.addElement('D');

    EXPECT_THROW(setTest1 = AssignmentWithMovement, ErrorParam);
}

TEST(CharSet, AssociationTest)
{
    
    Set <char> setTest1(4);
    setTest1.addElement('K');
    setTest1.addElement('D');
    setTest1.addElement('t');
    setTest1.addElement('l');

    Set <char> setTest2(3);
    setTest2.addElement('h');
    setTest2.addElement('K');
    setTest2.addElement('x');

    Set <char> AssociationSet = setTest1 + setTest2;
    
    EXPECT_EQ(AssociationSet.capacity(), 7);
    EXPECT_EQ(AssociationSet.size(), 6);
    EXPECT_EQ(AssociationSet[0], 'K');
    EXPECT_EQ(AssociationSet[1], 'D');
    EXPECT_EQ(AssociationSet[2], 't');
    EXPECT_EQ(AssociationSet[3], 'l');
    EXPECT_EQ(AssociationSet[4], 'h');
    EXPECT_EQ(AssociationSet[5], 'x');
}

TEST(CharSet, IntersectionTest)
{
    Set <char> setTest1(6);
    setTest1.addElement('k');
    setTest1.addElement('r');
    setTest1.addElement('c');
    setTest1.addElement('3');

    Set <char> setTest2(7);
    setTest2.addElement('s');
    setTest2.addElement('r');
    setTest2.addElement('c');
    setTest2.addElement('N');
    setTest2.addElement('O');
    setTest2.addElement('g');

    Set <char> IntersectionSet = setTest1 * setTest2;
    EXPECT_EQ(IntersectionSet.size(), 2);
    EXPECT_EQ(IntersectionSet[0], 'r');
    EXPECT_EQ(IntersectionSet[1], 'c');
}

TEST(CharSet, DifferenceTest)
{
    Set <char> setTest1(6);
    setTest1.addElement('S');
    setTest1.addElement('z');
    setTest1.addElement('W');
    setTest1.addElement('[');

    Set <char> setTest2(7);
    setTest2.addElement('S');
    setTest2.addElement('W');
    setTest2.addElement('[');
    setTest2.addElement('g');
    setTest2.addElement('U');
    setTest2.addElement('E');

    Set <char> DifferenceSet = setTest2 - setTest1;
    EXPECT_EQ(DifferenceSet.capacity(), setTest1.capacity());
    EXPECT_EQ(DifferenceSet.size(), 3);
    EXPECT_EQ(DifferenceSet[0], 'g');
    EXPECT_EQ(DifferenceSet[1], 'U');
    EXPECT_EQ(DifferenceSet[2], 'E');
}
