#include "Board.h"
#include "Drawer.h"
#include <string>
#include <stdlib.h>
#include <time.h> 
#include <iostream>


Board::Board(void)
{
	initBoard();
}

void Board::initBoard(){
	emptyCell.clear();

	for (int i = 0; i < BOARD_HEIGHT; i++){
		for (int j = 0; j < BOARD_WIDTH; j++){
			boardM[i][j] = 0;
			Node n;
			n.posX = i;
			n.posY = j;
			emptyCell.push_back(n);
		}
	}
}

void Board::draw(){
	Drawer::draw(*this);
}

char Board::cellType(int x, int y){
	//if x and y coordinates are within the boundaries of the board, 
	//then value in board[x][y] will be returned
	if(y >= 0 && y < BOARD_WIDTH && x >= 0 && x < BOARD_HEIGHT){
		return boardM[x][y];
	}else{
		return -1;
	}
}

void Board::generateNode(){
	//random number between 0-80
	int prand =  rand() % emptyCell.size();	
	//.posX and .posY takes the value inside emptyCell[prand] and uses them as index for boardM
	//random number between 1-6 will be saved into boardM 
	boardM[ emptyCell[prand].posX ][ emptyCell[prand].posY ] = rand() % 6 + 1;

	//it will erase the 'n'th element in the array, n = prand
	emptyCell.erase(emptyCell.begin() + prand);
}

void Board::checkVertical(){
	Node n;
	int nextArea = 1;
	
	nodesToDelete.clear();

	for(int i = 0; i < BOARD_HEIGHT; i++){
		for (int j = 0; j < BOARD_WIDTH; j++){
			if(boardM[i][j] != 0){
				//initialize vector
				n.posX = i;
				n.posY = j;
				nodesToDelete.push_back(n);

				while((i + nextArea != BOARD_HEIGHT) && (boardM[i][j] == boardM[i + nextArea][j])){
					n.posX = i + nextArea;
					nodesToDelete.push_back(n);
					nextArea++;
				}

				if (nodesToDelete.size() >= 5){
					deleteLine();
				}
			}
			nodesToDelete.clear();
			nextArea = 1;
		}
	}
}

void Board::checkHorizontal(){
	Node n;
	int nextArea = 1;

	for(int i = 0; i < BOARD_HEIGHT; i++){
		for (int j = 0; j < BOARD_WIDTH; j++){
			if(boardM[i][j] != 0){
				//initialize vector
				n.posX = i;
				n.posY = j;
				nodesToDelete.push_back(n);

				//if the 
				while((j + nextArea != BOARD_WIDTH) && (boardM[i][j] == boardM[i][j + nextArea])){
					n.posY = j + nextArea;
					nodesToDelete.push_back(n);
					nextArea++;
				}

				if (nodesToDelete.size() >= 5){
					deleteLine();
				}
			}
			nodesToDelete.clear();
			nextArea = 1;
		}
	}
}

void Board::checkDiagonal(){
	Node n;
	int nextArea = 1;

	for(int i = 0; i < BOARD_HEIGHT; i++){
		for (int j = 0; j < BOARD_WIDTH; j++){
			if(boardM[i][j] != 0){
				//initialize vector
				n.posX = i;
				n.posY = j;
				nodesToDelete.push_back(n);

				//if the 
				while((i + nextArea != BOARD_HEIGHT) && (j + nextArea != BOARD_WIDTH) && (boardM[i][j] == boardM[i + nextArea][j + nextArea])){
					n.posX = i + nextArea;
					n.posY = j + nextArea;
					nodesToDelete.push_back(n);
					nextArea++;
				}

				if (nodesToDelete.size() >= 5){
					deleteLine();
				}
			}
			nodesToDelete.clear();
			nextArea = 1;
		}
	}
}

void Board::deleteLine(){
	for(int i = 0; i < nodesToDelete.size(); i++){
		boardM[nodesToDelete[i].posX][nodesToDelete[i].posY] = 0;
	}
}

/*void Board::moveNode(System::Windows::Forms::MouseEventArgs^  e){
	eventPosX = e->X / 40;
	eventPosY = e->Y / 40;

	if(selectedNode == true){
		if(boardM[eventPosY][eventPosX] == 0){
			boardM[eventPosY][eventPosX] = boardM[initialEY][initialEX];
			boardM[initialEY][initialEX] = 0;
			initialEX = 0;
			initialEY = 0;

			for(int i = 0; i < 3; i++){
				generateNode();
			}
			selectedNode = false;
		}
	}else{
		if (boardM[eventPosY][eventPosX] != 0){
			initialEX = eventPosX;
			initialEY = eventPosY;
			selectedNode = true;
		}
	}
}*/

