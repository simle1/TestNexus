/*
	Leonard Sim
	Nexus 2000, C++ Programming
	
*/

#pragma once
#include <vector>
#include <math.h>

#ifndef _BOARD
#define _BOARD

#define BOARD_HEIGHT 9
#define BOARD_WIDTH 9
#define BOARD_CELLSIZE 40

//struct Node
struct Node{
	int posX;
	int posY;
	int count;
};

class Board
{
	//boardM set to 9x9 grid
	int boardM[BOARD_HEIGHT][BOARD_WIDTH];
	int previousState[BOARD_HEIGHT][BOARD_WIDTH];

	bool selectedNode;
	int currentScore;
	int previousScore;
	int highScore;
	int lastScore;
	
	//vector list of empty cells on grid
	std::vector<Node> emptyCell;
	//vector list of nodes to delete
	std::vector<Node> nodesToDelete;

	//current and initial event
	int eventPosX;
	int eventPosY;
	int initialEX;
	int initialEY;

public:
	Board(void);
	void initBoard();
	void draw();
	void deleteLine();
	void generateNode();
	
	void checkVertical();
	void checkHorizontal();
	void checkLDiagonal();
	void checkRDiagonal();
	
	//move the node when path is found
	void moveNode(System::Windows::Forms::MouseEventArgs^  e);

	//returns a vector list of the path 
	std::vector<Node> findPath(int startX, int startY, int goalX, int goalY);

	char cellType(int x, int y);
	int getCurrentScore() { return currentScore; }
	int getHighScore() { return highScore; }
	bool endState();
	void lastState();
};

#endif

