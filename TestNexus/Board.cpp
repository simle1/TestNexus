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

std::vector<Node> Board::findPath(int startX, int startY, int goalX, int goalY){
	//viableNodes
	std::vector<Node> viableNodes;

	bool validPath;

	//first added into viableNodes
	Node n;
	n.posX = goalX;
	n.posY = goalY;
	n.count = 0;
	viableNodes.push_back(n);

	//goes through viableNodes and whatever that is adjacent to it gets saved into Node n 
	//which gets pushed backed into adjacentNodes
	for(int i = 0; i < viableNodes.size(); i++){
		std::vector<Node> adjacentNodes;
		
		//right side
		n.posX = viableNodes[i].posX + 1;
		n.posY = viableNodes[i].posY;
		n.count = viableNodes[i].count + 1;
		adjacentNodes.push_back(n);
		
		//left side
		n.posX = viableNodes[i].posX - 1;
		n.posY = viableNodes[i].posY;
		n.count = viableNodes[i].count + 1;
		adjacentNodes.push_back(n);

		//up side
		n.posX = viableNodes[i].posX;
		n.posY = viableNodes[i].posY + 1;
		n.count = viableNodes[i].count + 1;
		adjacentNodes.push_back(n);

		//down side
		n.posX = viableNodes[i].posX;
		n.posY = viableNodes[i].posY - 1;
		n.count = viableNodes[i].count + 1;
		adjacentNodes.push_back(n);
		
		
		for(int j = 0; j < adjacentNodes.size(); j++){
			//when the adjacentNodes equal to the starting point then a path is found
			if((adjacentNodes[j].posX == startX) && (adjacentNodes[j].posY == startY)){
				//gets set to true
				validPath = true;
				
				//adjacentNodes gets saved back into n which gets pushed into the adjacentNodes list
				n.posX = adjacentNodes[j].posX;
				n.posY = adjacentNodes[j].posY;
				n.count = adjacentNodes[j].count;
				
				//clear the vector and pushback n then breaks out of for loop
				adjacentNodes.clear();
				adjacentNodes.push_back(n);
				break;
			}
			
			//checks if the adjacent nodes lies beyond board
			else if ((adjacentNodes[j].posX >= BOARD_HEIGHT) || (adjacentNodes[j].posY >= BOARD_WIDTH) || (adjacentNodes[j].posX < 0) || (adjacentNodes[j].posY < 0)){
				//removes the node off the list when it is outside of board
				adjacentNodes.erase(adjacentNodes.begin() + j);
				j--;
			}
			
			//removes the adjacentNodes index off the list if the cell isn't free
			else if (boardM[adjacentNodes[j].posX][adjacentNodes[j].posY] != 0){
				adjacentNodes.erase(adjacentNodes.begin() + j);
				j--;
			}
			
			//removes the adjacentNodes index when adjacentNodes is equal to the viableNodes
			else{
				for (int k = 0; k < viableNodes.size(); k++){
					if ((viableNodes[k].posX == adjacentNodes[j].posX) && (viableNodes[k].posY == adjacentNodes[j].posY)){
						adjacentNodes.erase(adjacentNodes.begin() + j);
						j--;
						break;
					}
				}
			}
		}
		
		//adds the range of adjacentNodes into the viableNodes which increases the size of viableNodes
		viableNodes.insert(viableNodes.end(), adjacentNodes.begin(), adjacentNodes.end());

		if(validPath == true){
			break;
		}
	}
	
	//checks if a valid path has been made
	if ((viableNodes.back().posX != startX) && (viableNodes.back().posY != startY)){
		return std::vector<Node>();
	}

	//create pathToGoal vector
	std::vector<Node> pathToGoal;
	Node n2;
	n2.posX = viableNodes.back().posX;
	n2.posY = viableNodes.back().posY;
	n2.count = viableNodes.back().count;
	pathToGoal.push_back(n2);

	for (int i = (viableNodes.size() - 2); i >= 0; i--){
		if(viableNodes[i].count == pathToGoal.back().count - 1){
			if(((viableNodes[i].posX == pathToGoal.back().posX + 1) && (viableNodes[i].posY == pathToGoal.back().posY)) ||
				((viableNodes[i].posX == pathToGoal.back().posX - 1) && (viableNodes[i].posY == pathToGoal.back().posY)) ||
				((viableNodes[i].posX == pathToGoal.back().posX) && (viableNodes[i].posY == pathToGoal.back().posY + 1)) ||
				((viableNodes[i].posX == pathToGoal.back().posX ) && (viableNodes[i].posY == pathToGoal.back().posY - 1)))
			{
				//add an adjacent viable node to the pathToGoal vector
				n2.posX = viableNodes[i].posX;
				n2.posY = viableNodes[i].posY;
				n2.count = viableNodes[i].count;
				pathToGoal.push_back(n2);
			}
		}
	}

	return pathToGoal;
}


void Board::moveNode(System::Windows::Forms::MouseEventArgs^  e){
	eventPosX = e->Y / 40;
	eventPosY = e->X / 40;

	if(selectedNode == true){
		if(boardM[eventPosX][eventPosY] == 0){
			
			//fed into the findPath() method
			int startX = initialEX;
			int startY = initialEY;
			int goalX = eventPosX;
			int goalY = eventPosY;

			std::vector<Node>startGoalPath = findPath(startX, startY, goalX, goalY);
			//if findPath returns a node and gets saved into 
			if(startGoalPath.size() > 0){
				
				boardM[eventPosX][eventPosY] = boardM[initialEX][initialEY];
				boardM[initialEX][initialEY] = 0;

				//updates the starting node to be free
				Node temp;
				temp.posX = initialEX;
				temp.posY = initialEY;
				emptyCell.push_back(temp);

				//change the temp X and Y position to be the destination one
				temp.posX = eventPosX;
				temp.posY = eventPosY;

				for(int i = 0; i < emptyCell.size(); i++){
					//checks if any of the emptyCell posX/Y are equal to the eventPosX/Y
					//and will erase the off the emptyCell list
					if ((emptyCell[i].posX == eventPosX) && (emptyCell[i].posY == eventPosY)){
						emptyCell.erase(emptyCell.begin() + i);
					}
				}

				for(int i = 0; i < 3; i++){
					generateNode();
				}
				selectedNode = false;
			}
		}
		else{
			initialEX = eventPosX;
			initialEY = eventPosY;
			selectedNode = true;
		}
	}
	else{
		if (boardM[eventPosX][eventPosY] != 0){
			initialEX = eventPosX;
			initialEY = eventPosY;
			selectedNode = true;
		}
	}
}

