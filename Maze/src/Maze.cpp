#include "Maze.h"


struct Emplacement 
{
	int x;
	int y;
};


string currentWay;


bool MazeWay(int** maze, int rowsCount, int columnsCount, Emplacement position = Emplacement{0, 0})
{
	static bool tempSearchResult;
	if (position.x == columnsCount - 1 && position.y == rowsCount - 1)
	{
		
		return true;
	}

	maze[position.y][position.x] = 2;

	if (position.y - 1 >= 0 && maze[position.y - 1][position.x] == 0)
	{
		currentWay += "U-";
		tempSearchResult = MazeWay(maze, rowsCount, columnsCount, Emplacement{position.x, position.y - 1});
		if (tempSearchResult == true)
		{
			return tempSearchResult;
		}
		currentWay.replace(currentWay.size() - 2, 2, "");
	}

	if (position.y + 1 < rowsCount && maze[position.y + 1][position.x] == 0) 
	{
		currentWay += "D-";
		tempSearchResult = MazeWay(maze, rowsCount, columnsCount, Emplacement{ position.x, position.y + 1 });
		if (tempSearchResult == true)
		{
			return tempSearchResult;
		}
		currentWay.replace(currentWay.size() - 2, 2, "");
	}

	if (position.x + 1 < columnsCount && maze[position.y][position.x + 1] == 0) 
	{
		currentWay += "R-";
		tempSearchResult = MazeWay(maze, rowsCount, columnsCount, Emplacement{position.x + 1, position.y});
		if (tempSearchResult == true)
		{
			return tempSearchResult;
		}
		currentWay.replace(currentWay.size() - 2, 2, "");
	}

	if (position.x - 1 >= 0 && maze[position.y][position.x - 1] == 0) 
	{
		currentWay += "L-";
		tempSearchResult = MazeWay(maze, rowsCount, columnsCount, Emplacement{position.x - 1, position.y});
		if (tempSearchResult == true)
		{
			return tempSearchResult;
		}
		currentWay.replace(currentWay.size() - 2, 2, "");
	}
	maze[position.y][position.x] = 0;

	return false;
}

string MazeWayWrite(string &fileName)
{
	currentWay.clear();
	ifstream file(fileName);
	if (file.is_open() == 0)
	{
		return NULL;
	}
	vector<vector<int>> mapFromFile;
	int emptySet;
	for (size_t i = 0; !file.eof(); ++i)
	{
		mapFromFile.push_back(vector<int>());
		for (int j = 0; file.get() != '\n' && !file.eof(); ++j)
		{
			file.seekg(file.tellg(), ios_base::beg);
			file >> emptySet;
			mapFromFile[i].push_back(emptySet);
		}
	}
	int** map = new int* [mapFromFile.size()];
	for (size_t i = 0; i < mapFromFile.size(); ++i)
	{
		map[i] = new int[mapFromFile[i].size()];
		for (size_t j = 0; j < mapFromFile[i].size(); ++j)
		{
			map[i][j] = mapFromFile[i][j];
		}
	}
		
	MazeWay(map, mapFromFile.size(), mapFromFile[0].size());
	
	
	for (size_t i = 0; i < mapFromFile.size(); ++i)
	{
		delete[] map[i];
	}
	delete[] map;
		
	return currentWay;
}