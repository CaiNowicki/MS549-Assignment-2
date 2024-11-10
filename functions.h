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