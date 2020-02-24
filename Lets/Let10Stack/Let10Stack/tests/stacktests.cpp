#include <gmock/gmock.h>
#include "../src/IntStack.h"

//Нужны ли такие отступы в написании тестов?
//Это "+" или "-" к оформлению кода?
TEST(IntStack, Make_push_top_)
{
	IntStack stacktest1(14), stacktest2(3);

	stacktest1.push(21);
	stacktest2.push(12);

	EXPECT_EQ(stacktest1.top(), 21);
	EXPECT_EQ(stacktest2.top(), 12);
}
TEST(IntStack, Push_stackOverflow)
{
	IntStack stacktest(2);

	stacktest.push(14);
	stacktest.push(34);
	
	EXPECT_THROW(stacktest.push(7), StackOverflow);
}
TEST(IntStack, Top_stackIsEmpty)
{
	IntStack stacktest1(0), stacktest2(2);

	stacktest2.push(-24);

	EXPECT_THROW(stacktest1.top(),StackIsEmpty);
	EXPECT_EQ(stacktest2.top(), -24);
}
TEST(IntStack, Pop_stackIsEmpty)
{
	IntStack stacktest1(8), stacktest2(0);

	stacktest1.push(7);
	stacktest1.push(35);
	stacktest1.push(28);
	
	EXPECT_EQ(stacktest1.top(), 28);
	stacktest1.pop();
	EXPECT_EQ(stacktest1.top(), 35);
	stacktest1.pop();
	EXPECT_EQ(stacktest1.top(), 7);
	EXPECT_THROW(stacktest2.top(),StackIsEmpty);
}
TEST(IntStack, Empty)
{
	IntStack stacktest1(3), stacktest2(34);

	EXPECT_TRUE(stacktest1.empty());
	EXPECT_TRUE(stacktest2.empty());

	stacktest1.push(12);
	stacktest1.push(43);
	stacktest1.push(4);
	stacktest2.push(7);
	stacktest2.push(45);
	
	EXPECT_FALSE(stacktest1.empty());
	EXPECT_FALSE(stacktest2.empty());

	stacktest1.pop();
	stacktest1.pop();
	stacktest1.pop();	
	stacktest2.pop();
	stacktest2.pop();
	
	EXPECT_TRUE(stacktest1.empty());
	EXPECT_TRUE(stacktest2.empty());
}
TEST(IntStack, Push_and_top)
{
	IntStack stacktest(44);

	stacktest.push(90);
	EXPECT_EQ(stacktest.top(), 90);
	stacktest.push(11);
	EXPECT_EQ(stacktest.top(), 11);
}
TEST(IntStack, Pop)
{
	IntStack stacktest(25);

	stacktest.push(90);
	stacktest.push(11);
	stacktest.push(134);
	stacktest.pop();
	EXPECT_EQ(stacktest.top(), 11);
	stacktest.pop();
	EXPECT_EQ(stacktest.top(), 90);
}
TEST(IntStack, Empty_push_pop)
{
	IntStack stacktest1(24), stacktest2(19);

	EXPECT_TRUE(stacktest1.empty());
	EXPECT_TRUE(stacktest2.empty());

	stacktest1.push(90);
	stacktest1.push(11);
	stacktest2.push(-152);

	EXPECT_FALSE(stacktest1.empty());
	EXPECT_FALSE(stacktest2.empty());

	stacktest1.pop();
	stacktest1.pop();
	stacktest2.pop();

	EXPECT_TRUE(stacktest1.empty());
	EXPECT_TRUE(stacktest1.empty());
}
TEST(IntStack, Size_push_pop)
{
	IntStack stacktest1(9), stacktest2(100), stacktest3(12);

	EXPECT_EQ(stacktest1.size(), 0);
	EXPECT_EQ(stacktest2.size(), 0);
	EXPECT_EQ(stacktest3.size(), 0);

	stacktest1.push(90);
	stacktest1.push(11);
	stacktest2.push(-152);
	stacktest2.push(1901);
	stacktest3.push(9999);

	EXPECT_EQ(stacktest1.size(), 2);
	EXPECT_EQ(stacktest2.size(), 2);
	EXPECT_EQ(stacktest3.size(), 1);

	stacktest1.pop();
	stacktest2.pop();
	stacktest2.pop();
	stacktest3.pop();

	EXPECT_EQ(stacktest1.size(), 1);
	EXPECT_EQ(stacktest2.size(), 0);
	EXPECT_EQ(stacktest3.size(), 0);
}
TEST(IntStack, Capacity_push_stackOverflow)
{
	IntStack stacktest1(3), stacktest2(2);

	EXPECT_EQ(stacktest1.capacity(), 3);
	EXPECT_EQ(stacktest2.capacity(), 2);

	stacktest1.push(90);
	stacktest1.push(11);
	stacktest1.push(134);
	stacktest2.push(-152);
	stacktest2.push(1901);

	EXPECT_EQ(stacktest2.capacity(),2);
	EXPECT_EQ(stacktest1.capacity(), 3);
	EXPECT_THROW(stacktest2.push(-234);, StackOverflow);
}
