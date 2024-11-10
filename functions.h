#pragma once
#include <vector>

using namespace std;

//These are the directions for moving within the maze (N, S, E, W)

enum Direction { NORTH, SOUTH, EAST, WEST}; // enum == set of named integer constants

//This defines the wall state 
struct Cell {
	bool visited;
	bool walls[4]; // 4 directions = 4 walls
};

//Maze class
//Handles grid and operations

class Maze {
public:
	int width;
	int height;
	vector<vector<Cell>> grid; // creates 2d vector grid (is doubled because it is creating a vector of vectors)

	//Maze constructor
	Maze(int w, int h);

	//Maze initializer
	void intializeMaze();

	//Maze carver using depth-first search to recursively design the maze
	void carveMaze(int x, int y);

	//Maze printer 
	void printMaze();
};

