#pragma once
#include <vector>
#include <math.h>

#ifndef _BOARD
#define _BOARD

#define BOARD_HEIGHT 9
#define BOARD_WIDTH 9
#define BOARD_CELLSIZE 40

struct Node{
	int posX;
	int posY;
	int count;
	
};

class Board
{
	int boardM[BOARD_HEIGHT][BOARD_WIDTH];
	std::vector<Node> emptyCell;
	std::vector<Node> nodesToDelete;
	bool selectedNode;
	int currentScore;
	int highScore;

	int eventPosX;
	int eventPosY;
	int initialEX;
	int initialEY;

	

public:
	Board(void);
	void initBoard();
	void draw();
	
	void checkVertical();
	void checkHorizontal();
	void checkDiagonal();

	void moveNode(System::Windows::Forms::MouseEventArgs^  e);
	std::vector<Node> findPath(int startX, int startY, int goalX, int goalY);

	void deleteLine();
	void generateNode();
	char cellType(int x, int y);
	int getCurrentScore() { return currentScore; }
	int getHighScore() { return highScore; }
};

#endif

