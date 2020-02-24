#include <gmock/gmock.h>


#include "../src/STLAlgo.h"



TEST(ConvertOctToHex, Test)
{
    string strTest = "123";
    EXPECT_EQ(ConvertOctToHex(strTest), "53");
}

TEST(ConvertOctToHex, emptyStrTest)
{
    string strTest = "";
    EXPECT_EQ(ConvertOctToHex(strTest), "");
}

TEST(ConvertOctToHex, noOctNumberTest)
{
    string strTest = "988";
    EXPECT_EQ(ConvertOctToHex(strTest), "");
}

TEST(ConvertOctToHex, floatNumberTest)
{
    string strTest = "427342.2";
    EXPECT_EQ(ConvertOctToHex(strTest), "");
}
TEST(ConvertOctToHex, negativeNumberTest)
{
    string strTest = "-256";
    EXPECT_EQ(ConvertOctToHex(strTest), "fffffaae");
}

TEST(ReverseWord, test)
{
    string strTest = "This memo provides information for the Internet community";

    EXPECT_EQ(ReverseWord(strTest), "community memo provides information for the Internet This");
}



TEST(FindThirdWord, Test)
{
    string strTest = "This memo provides, information for the Internet";

    EXPECT_EQ(FindThirdWord(strTest), "provides, the ");
}
TEST(FindThirdWord, threeWords)
{
    string strTest = "This memo provides";

    EXPECT_EQ(FindThirdWord(strTest), "provides ");
}

TEST(FindThirdWord, emptyStrTest)
{
    string strTest = "";

    EXPECT_EQ(FindThirdWord(strTest), "");
}


TEST(FindMostShort, Test)
{
    string strTest = "This memo for the Internet";

    EXPECT_EQ(FindMostShort(strTest), 2);
}
TEST(FindMostShort, emptyStrTest)
{
    string strTest = "";

    EXPECT_EQ(FindMostShort(strTest), -1);
}
TEST(FindMostShort, oneWordTest)
{
    string strTest = "erthydv";

    EXPECT_EQ(FindMostShort(strTest), 1);
}
TEST(FindMostShort, twoWordTest)
{
    string strTest = "ayj h";

    EXPECT_EQ(FindMostShort(strTest), 1);
}

TEST(ReverseWord, emptyStrTest)
{
    string strTest = "";

    EXPECT_EQ(ReverseWord(strTest), "");
}

TEST(ReverseWord, oneWordTest)
{
    string strTest = "world";

    EXPECT_EQ(ReverseWord(strTest), "world");
}

TEST(ReverseWord, twoWordsTest)
{
    string strTest = "Hello world";

    EXPECT_EQ(ReverseWord(strTest), "world Hello");
}


TEST(FindSentence, TenSentencesTest)
{
    string fileName = "Text.txt";
    EXPECT_EQ(FindSentenceInFile(fileName, 10), "Young and old people prepare for the holiday in advance. Someone waits for fashionable computer game or another expensive present. ");
}

TEST(FindSentence, ThirteenSentencesTest)
{
    string fileName = "Text.txt";
    EXPECT_EQ(FindSentenceInFile(fileName, 13), "Some people try to make a wish when it is time of chimes. ");
}