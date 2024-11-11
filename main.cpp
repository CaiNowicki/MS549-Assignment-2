#include <iostream>
#include <cstdlib>
#include <ctime>
#include "functions.h"

using namespace std;

int main() {
	srand(time(0)); //randomizer seed

	//create a maze of specified size
	int width;
	int height;
	cout << "Please specify dimensions of your maze: \n";
	cout << "Width: ";
	cin >> width;
	cout << "Height: ";
	cin >> height;

	Maze maze(width, height);
	//carve maze starting from (0,0)
	maze.carveMaze(0, 0);

	//print the maze
	maze.printMaze();

	return 0;
}