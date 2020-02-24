#include <gmock/gmock.h>


#include "../src/Maze.h"


TEST(Maze, WayFoundTest)
{
    string fileName = "MazeTest1.txt";
    EXPECT_STREQ(MazeWayWrite(fileName).c_str(), "D-R-D-D-D-D-R-R-");
}

TEST(Maze, WayNotFoundTest)
{
    string fileName = "MazeTest2.txt";
    EXPECT_STREQ(MazeWayWrite(fileName).c_str(), "");
}