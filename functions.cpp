#include "functions.h"
#include <iostream>
#include <cstdlib> //for rand and srand
#include <ctime> //for time function
#include <algorithm> //for random_shuffle library

using namespace std;

//Constructor
//creates dimensions and grid
Maze::Maze(int w, int h) : width(w), height(h) {
	grid.resize(h, vector<Cell>(w));
	intializeMaze();
}
//Initalizer
//creates cells and walls
void Maze::intializeMaze() {
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			grid[i][j].visited = false; //all cells start in "not visited" state
			for (int k = 0; k < 4; k++) {
				grid[i][j].walls[k] = true; //all walls start as up around all cells
			}
		}
	}
}

//Maze Carver
//Recursively "carves" out the maze paths through the walls using depth-first search
void Maze::carveMaze(int x, int y) {
	grid[y][x].visited = true; //marks the cell as visited

	//Move within the maze
	Direction directions[] = { NORTH, SOUTH, EAST, WEST };
	random_shuffle(directions, directions + 4); //randomize the direction

	for (int i = 0; i < 4; i++) {
		int nx = x, ny = y; //new x, new y
		//Move in the specified direction
		switch (directions[i]) {
		case NORTH: ny -= 1;
			break;
		case SOUTH: ny += 1;
			break;
		case EAST: nx += 1;
			break;
		case WEST: nx -= 1;
			break;
		}
		//Check if next move is within the grid and the cell has not been visited
		if (nx >= 0 && nx < width && ny >= 0 && ny < height && !grid[ny][nx].visited) {
			//Remove the wall between x,y and nx,ny
			grid[y][x].walls[directions[i]] = false;

			//Now remove opposite wall of new cell to create a path
			if (directions[i] == NORTH) {
				grid[ny][nx].walls[SOUTH] = false;
			}
			else if (directions[i] == SOUTH) {
				grid[ny][nx].walls[NORTH] = false;
			}
			else if (directions[i] == EAST) {
				grid[ny][nx].walls[WEST] = false;
			}
			else if (directions[i] == WEST) {
				grid[ny][nx].walls[EAST] = false;
			}
			carveMaze(nx, ny);
		}
	}
}

	//Maze printer
	void Maze::printMaze() {
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				//prints top walls
				if (grid[i][j].walls[NORTH]) {
					cout << "+-";
				}
				else cout << "+ ";
			}
			cout << "+" << endl;

			for (int j = 0; j < width; j++) {
				//prints left walls
				if (grid[i][j].walls[WEST]) {
					cout << "| ";
				}
				else cout << " ";
		}
			cout << "|" << endl;
	}
		for (int j = 0; j < width; j++) {
			//prints bottom walls
			cout << "+-";
		}
}