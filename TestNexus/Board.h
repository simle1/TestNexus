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
	
	Node *parent;
	float G;
	float H;

	Node(){ parent = 0; }
	Node(int x, int y, Node *_parent = NULL){
		posX = x;
		posY = y;
		G = 0;
		H = 0;
	}
	
	float GetF() { return G + H; }
	float ManHattanDistance(Node *nodeEnd){
		float x = (float)(fabs((float)(this->posX - nodeEnd->posX)));
		float y = (float)(fabs((float)(this->posY - nodeEnd->posY)));

		return x + y;
	}
};

class Board
{
	int boardM[BOARD_HEIGHT][BOARD_WIDTH];
	std::vector<Node> emptyCell;
	std::vector<Node> nodesToDelete;
	bool selectedNode;
	/*
	int eventPosX;
	int eventPosY;
	int initialEX;
	int initialEY;
	*/

public:
	Board(void);
	void initBoard();
	void draw();
	
	void checkVertical();
	void checkHorizontal();
	void checkDiagonal();

	void moveNode(System::Windows::Forms::MouseEventArgs^  e);

	void deleteLine();
	void generateNode();
	char cellType(int x, int y);


};

#endif

