#ifndef MAZE_MAZE_H
#define MAZE_MAZE_H


#include <algorithm>
#include <fstream>
#include <iostream>
#include <istream>
#include <string>
#include <vector>
#include <utility>


using namespace std;


struct Emplacement;

bool MazeWay(int** maze, int rowsCount, int columnsCount, Emplacement position);

string MazeWayWrite(string &fileName);


#endif //MAZE_MAZE_H
