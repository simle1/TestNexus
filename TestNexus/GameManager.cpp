/*
	Leonard Sim
	Nexus 2000, C++ Programming
	
	Links together the drawer and board
*/


#include "GameManager.h"
#include "Drawer.h"
#include <stdlib.h>
#include <time.h> 

GameManager::GameManager(void)
{
	pBoard = 0;
	pBoard = new Board();
}

//starts the game
void GameManager::gameStart(void){
	gameStarted = true;
	currentScore = 0;
	pBoard->initBoard();
	addThreeNodes();
}

//draws onto pictureBox
void GameManager::drawAll(){
	pBoard->draw();
}

//generate 3 nodes when game starts
void GameManager::addThreeNodes(){
	srand (time(NULL));

	for(int i = 0; i < 3; i++){
		pBoard->generateNode();
	}
}

//moves the node and checks if there are nodes of 5 in a line
void GameManager::move(System::Windows::Forms::MouseEventArgs^  e){
	pBoard->moveNode(e);
	checkLines();
	currentScore = pBoard->getCurrentScore();
}

//checks all direction to clear line
void GameManager::checkLines(){
	pBoard->checkVertical();
	pBoard->checkHorizontal();
	pBoard->checkRDiagonal();
	pBoard->checkLDiagonal();
}

bool GameManager::endState(){
	return pBoard->endState();
}

void GameManager::undo(){
	pBoard->lastState();
}