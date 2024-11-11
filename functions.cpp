#include "functions.h"
#include <iostream>
#include <cstdlib> //for rand and srand
#include <ctime> //for time function
#include <algorithm> //for random_shuffle library

using namespace std;

//Constructor
//creates dimensions and grid
Maze::Maze(int w, int h) : width(w), height(h) {
	grid.resize(height);
	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width; ++j) {
			grid[i].push_back(std::make_unique<Cell>());
		}
	}
	initializeMaze();
}

// Initialize each cell in the maze
void Maze::initializeMaze() {
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			grid[i][j]->visited = false;
			for (int k = 0; k < 4; k++) {
				grid[i][j]->walls[k] = true;
			}
		}
	}
}


//Maze Carver
//Recursively "carves" out the maze paths through the walls using depth-first search
void Maze::carveMaze(int x, int y) {
	grid[y][x]->visited = true;
	Direction directions[] = { NORTH, SOUTH, EAST, WEST };
	std::random_shuffle(directions, directions + 4);  // Shuffle directions

	for (Direction& dir : directions) {  // Passing as a reference here
		int nx = x, ny = y;
		switch (dir) {
		case NORTH: ny -= 1; 
			break;
		case SOUTH: ny += 1; 
			break;
		case EAST:  nx += 1; 
			break;
		case WEST:  nx -= 1; 
			break;
		}
		if (nx >= 0 && nx < width && ny >= 0 && ny < height && !grid[ny][nx]->visited) {
			grid[y][x]->walls[dir] = false;
			grid[ny][nx]->walls[(dir + 2) % 4] = false;  // Open opposite wall
			carveMaze(nx, ny);  // Recursive call
		}
	}
}

	//Maze printer
void Maze::printMaze() {
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			cout << (grid[i][j]->walls[NORTH] ? "+-" : "+ ");
		}
		cout << "+" << endl;
		for (int j = 0; j < width; j++) {
			cout << (grid[i][j]->walls[WEST] ? "| " : "  ");
		}
		cout << "|" << endl;
	}
	for (int j = 0; j < width; j++) {
		cout << "+-";
	}
	cout << "+" << endl;
}