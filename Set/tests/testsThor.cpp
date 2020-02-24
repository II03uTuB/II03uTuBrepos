#include <gmock/gmock.h>


#include "../src/Thor.h"
#include "../src/Set.h"
#include "../src/FunctionalClasses.h"


TEST(ThorSet, ConstructorWithoutParametersTest)
{
    Set <Thor> setTest1;
    Set <Thor> setTest2;
    Set <Thor> setTest3;
    Set <Thor> setTest4;
    Set <Thor> setTest5;

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

TEST(ThorSet, ConstructorCopyTest)
{
    Set <Thor> setTest(20);
    setTest.addElement(Thor(32, 21, 14));
    setTest.addElement(Thor(26, 14, 32));
    setTest.addElement(Thor(34, 22, 11));
    setTest.addElement(Thor(85, 44, 32));
    setTest.addElement(Thor(45, 78, 43));
    setTest.addElement(Thor(65, 4, 22));
    setTest.addElement(Thor(38, 53, 21));
    setTest.addElement(Thor(98, 22, 12));

    Set <Thor> setCopyTest(setTest);

    EXPECT_EQ(setTest.capacity(), setCopyTest.capacity());
    EXPECT_EQ(setTest.size(), setCopyTest.size());

    for(int i = 0; i < setTest.size(); ++i)
    {
        EXPECT_DOUBLE_EQ(setTest[i].getExternalRadius(), setCopyTest[i].getExternalRadius());
        EXPECT_DOUBLE_EQ(setTest[i].getInternalRadius(), setCopyTest[i].getInternalRadius());
        EXPECT_DOUBLE_EQ(setTest[i].getThickness(), setCopyTest[i].getThickness());
    }
}

TEST(ThorSet, ConstructorMovementTest)
{
    Set <Thor> setTest(20);
    setTest.addElement(Thor(32.42, 21.36, 14.1784));
    setTest.addElement(Thor(26.284, 14, 32.09));
    setTest.addElement(Thor(34.156, 22.369, 11.7459));
    setTest.addElement(Thor(85.264, 44.2794, 32.2784));
    setTest.addElement(Thor(45.794, 78.2905, 43.001));
    setTest.addElement(Thor(65.2884, 4.2875, 22.25));
    setTest.addElement(Thor(38.43, 53.658, 21.334));
    setTest.addElement(Thor(98.346, 22.235, 12));

    Set <Thor> setMovementTest(setTest);

    EXPECT_EQ(setTest.capacity(), setMovementTest.capacity());
    EXPECT_EQ(setTest.size(), setMovementTest.size());

    for(int i = 0; i < setTest.size(); ++i)
    {
        EXPECT_DOUBLE_EQ(setTest[i].getExternalRadius(), setMovementTest[i].getExternalRadius());
        EXPECT_DOUBLE_EQ(setTest[i].getInternalRadius(), setMovementTest[i].getInternalRadius());
        EXPECT_DOUBLE_EQ(setTest[i].getThickness(), setMovementTest[i].getThickness());
    }
}

TEST(ThorSet, PushTest)
{
    Set <Thor> set(3);

    ASSERT_EQ(set.capacity(), 3);

    set.addElement(Thor(98.237, 24.73, 15.584));
    set.addElement(Thor(38.42, 218.36, 1.1784));
    set.addElement(Thor(32.424, 21.3623, 141.1784));

    
    ASSERT_EQ(set.capacity(), 3);

    EXPECT_DOUBLE_EQ(set[0].getExternalRadius(), 98.237);
    EXPECT_DOUBLE_EQ(set[0].getInternalRadius(), 24.73);
    EXPECT_DOUBLE_EQ(set[0].getThickness(), 15.584);

    EXPECT_DOUBLE_EQ(set[1].getExternalRadius(), 38.42);
    EXPECT_DOUBLE_EQ(set[1].getInternalRadius(), 218.36);
    EXPECT_DOUBLE_EQ(set[1].getThickness(), 1.1784);

    EXPECT_DOUBLE_EQ(set[2].getExternalRadius(), 32.423999999999999);
    EXPECT_DOUBLE_EQ(set[2].getInternalRadius(), 21.3623);
    EXPECT_DOUBLE_EQ(set[2].getThickness(), 141.1784);
}

TEST(ThorSet, PushTestErrorParam)
{
    Set <Thor> setTest1;

    EXPECT_THROW(setTest1.addElement(Thor(32.42, 21.36, 14.1784)), ErrorParam);

    Set <Thor> setTest2(4);
    setTest2.addElement(Thor(3.42, 21.36, 34.1784));
    setTest2.addElement(Thor(2.42, 21.08, 14.653));
    setTest2.addElement(Thor(87.42, 246.36, 71.1784));
    setTest2.addElement(Thor(32.04, 21.865, 14.89));

    EXPECT_THROW(setTest2.addElement(Thor(32.42, 21.36, 14.1784)), ErrorParam);
}
TEST(ThorSet, PushTestErrorMake)
{
    Set <Thor> setTest1;

    EXPECT_THROW(setTest1.addElement(Thor(-32.42, 21.36, -14.1784)), ErrorMake);

    Set <Thor> setTest2(4);
    EXPECT_THROW(setTest2.addElement(Thor(3.42, -21.36, 34.1784)), ErrorMake) ;
    EXPECT_THROW(setTest2.addElement(Thor(2.42, 21.08, -14.653)), ErrorMake);
    EXPECT_THROW(setTest2.addElement(Thor(-87.42, 246.36, 71.1784)), ErrorMake);
    EXPECT_THROW(setTest2.addElement(Thor(-32.04, -21.865, -14.89)), ErrorMake);
    EXPECT_THROW(setTest2.addElement(Thor(32.42, 0, 14.1784)), ErrorMake);
}

TEST(ThorSet, GetVolumeTest)
{
    Set <Thor> set(3);

    set.addElement(Thor(98.237, 24.73, 15.584));
    set.addElement(Thor(38.42, 218.36, 1.1784));
    set.addElement(Thor(32.424, 21.3623, 141.1784));

    EXPECT_DOUBLE_EQ(set[0].getVolume(), 1185913.6424891807);
    EXPECT_DOUBLE_EQ(set[1].getVolume(), 36160403.907214612);
    EXPECT_DOUBLE_EQ(set[2].getVolume(), 292073.63203925471);
}
TEST(ThorSet, GetAreaTest)
{
    Set <Thor> set(3);

    set.addElement(Thor(98.237, 24.73, 15.584));
    set.addElement(Thor(38.42, 218.36, 1.1784));
    set.addElement(Thor(32.424, 21.3623, 141.1784));

    EXPECT_DOUBLE_EQ(set[0].getArea(), 95908.907601227722);
    EXPECT_DOUBLE_EQ(set[1].getArea(), 331199.88923992135);
    EXPECT_DOUBLE_EQ(set[2].getArea(), 27344.773927831247);
}
TEST(ThorSet, findVolumeTest)
{
    Set <Thor> setTest1(5);
    lessVolume <int> less;
    setTest1.addElement(Thor(10, 15, 20));
    setTest1.addElement(Thor(11, 9, 3));
    setTest1.addElement(Thor(9, 20, 14));
    setTest1.addElement(Thor(3, 6, 8));

    setTest1.findPred(less, 50000);

    EXPECT_DOUBLE_EQ(setTest1[0].getVolume(), 44413.219804902117);
    EXPECT_DOUBLE_EQ(setTest1[1].getVolume(), 17587.635042741236);
}
TEST(ThorSet, AssignmentWithCopyTest)
{
    Set <Thor> setTest1(8);
    setTest1.addElement(Thor(13.37, 21.36, 34.1784));
    setTest1.addElement(Thor(21.534, 21.36, 34.1784));
    setTest1.addElement(Thor(9.172, 21.36, 336.14724));
    setTest1.addElement(Thor(8.23, 21.36, 34.1784));
    setTest1.addElement(Thor(0.64, 21.1624, 34.254));
    setTest1.addElement(Thor(124, 21.36, 34.1784));
    setTest1.addElement(Thor(362.479, 21.36, 284.1784));
    setTest1.addElement(Thor(3.42, 21.36, 34.14));

    Set <Thor> setTest2(8);
    setTest2.addElement(Thor(13.37, 21.36, 0.4));
    setTest2.addElement(Thor(13.37, 21.36, 344));
    setTest2.addElement(Thor(346.37, 274.36, 34.178));
    setTest2.addElement(Thor(3.323, 21.36, 12.34));
    setTest2.addElement(Thor(964.37, 21.098, 34.4));
    setTest2.addElement(Thor(13.2905, 264.36, 342.22));
    setTest2.addElement(Thor(2356.37, 21.3685, 31.478));
    setTest2.addElement(Thor(13.28795, 21, 3));

    Set <Thor> AssigmentWithCopyTest(30);
    AssigmentWithCopyTest = setTest1 = setTest2 = setTest2;

    EXPECT_EQ(AssigmentWithCopyTest.capacity(), 30);
    EXPECT_EQ(AssigmentWithCopyTest.size(), 8);

    for(int i = 0; i < setTest1.size(); ++i)
    {
        EXPECT_DOUBLE_EQ(AssigmentWithCopyTest[i].getExternalRadius(),setTest1[i].getExternalRadius());
        EXPECT_DOUBLE_EQ(AssigmentWithCopyTest[i].getInternalRadius(),setTest1[i].getInternalRadius());
        EXPECT_DOUBLE_EQ(AssigmentWithCopyTest[i].getThickness(),setTest1[i].getThickness());
    }

    for(int i = 0; i < setTest2.size(); ++i)
    {
        EXPECT_DOUBLE_EQ(AssigmentWithCopyTest[i].getExternalRadius(),setTest2[i].getExternalRadius());
        EXPECT_DOUBLE_EQ(AssigmentWithCopyTest[i].getInternalRadius(),setTest2[i].getInternalRadius());
        EXPECT_DOUBLE_EQ(AssigmentWithCopyTest[i].getThickness(),setTest2[i].getThickness());
    }
}

TEST(ThorSet, AssignmentWithCopyTestErrorParam)
{
    Set <Thor> setTest1(8);
    setTest1.addElement(Thor(13.37, 21.36, 34.1784));
    setTest1.addElement(Thor(21.534, 21.36, 34.1784));
    setTest1.addElement(Thor(9.172, 21.36, 336.14724));
    setTest1.addElement(Thor(8.23, 21.36, 34.1784));

    Set <Thor> AssigmentWithCopyTest(1);

    EXPECT_THROW(AssigmentWithCopyTest = setTest1, ErrorParam);
}

TEST(ThorSet, AssignmentWithMovementTest)
{
    Set <Thor> setTest1(5);
    setTest1.addElement(Thor(532.57, 26.36, 8477.14));
    setTest1.addElement(Thor(13.357, 21, 4.4));
    setTest1.addElement(Thor(124.37, 0.36, 3.8));
    setTest1.addElement(Thor(22.09, 14.3, 4.74));

    Set <Thor> setTest2(20);

    Set <Thor> AssignmentWithMovement(35);
    AssignmentWithMovement.addElement(Thor(12.37, 1.36, 4.784));
    AssignmentWithMovement.addElement(Thor(17.33, 2.6, 3.14));
    AssignmentWithMovement.addElement(Thor(1.7, 1.3, 12.8));

    setTest1 = AssignmentWithMovement;
    setTest2 = AssignmentWithMovement;

    EXPECT_EQ(setTest1.capacity(), 5);
    EXPECT_EQ(setTest1.size(), 3);

    EXPECT_DOUBLE_EQ(setTest1[0].getExternalRadius(), 12.369999999999999);
    EXPECT_DOUBLE_EQ(setTest1[0].getInternalRadius(), 1.3600000000000001);
    EXPECT_DOUBLE_EQ(setTest1[0].getThickness(), 4.7839999999999998);

    EXPECT_DOUBLE_EQ(setTest2[1].getExternalRadius(), 17.329999999999998);
    EXPECT_DOUBLE_EQ(setTest2[1].getInternalRadius(), 2.6000000000000001);
    EXPECT_DOUBLE_EQ(setTest2[1].getThickness(), 3.1400000000000001);

    EXPECT_DOUBLE_EQ(setTest2[2].getExternalRadius(), 1.7);
    EXPECT_DOUBLE_EQ(setTest2[2].getInternalRadius(), 1.3);
    EXPECT_DOUBLE_EQ(setTest2[2].getThickness(), 12.800000000000001);

    EXPECT_EQ(setTest2.capacity(), 20);
    EXPECT_EQ(setTest2.size(), 3);

    EXPECT_DOUBLE_EQ(setTest2[0].getExternalRadius(), 12.369999999999999);
    EXPECT_DOUBLE_EQ(setTest2[0].getInternalRadius(), 1.3600000000000001);
    EXPECT_DOUBLE_EQ(setTest2[0].getThickness(), 4.7839999999999998);

    EXPECT_DOUBLE_EQ(setTest2[1].getExternalRadius(), 17.329999999999998);
    EXPECT_DOUBLE_EQ(setTest2[1].getInternalRadius(), 2.6000000000000001);
    EXPECT_DOUBLE_EQ(setTest2[1].getThickness(), 3.1400000000000001);

    EXPECT_DOUBLE_EQ(setTest2[2].getExternalRadius(), 1.7);
    EXPECT_DOUBLE_EQ(setTest2[2].getInternalRadius(), 1.3);
    EXPECT_DOUBLE_EQ(setTest2[2].getThickness(), 12.800000000000001);
}

TEST(ThorSet, AssignmentWithMovementTestErrorParam)
{
    Set <Thor> setTest1(1);

    Set <Thor> AssignmentWithMovement(3);
    AssignmentWithMovement.addElement(Thor(17.33, 2.6, 3.14));
    AssignmentWithMovement.addElement(Thor(0.33, 206, 31.4));

    EXPECT_THROW(setTest1 = AssignmentWithMovement, ErrorParam);
}
