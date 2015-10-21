#include "GameManager.h"
#include "Drawer.h"
#include <stdlib.h>
#include <time.h> 

GameManager::GameManager(void)
{
	pBoard = 0;
	pBoard = new Board();
}

void GameManager::gameStart(void){
	gameStarted = true;
	currentScore = 0;
	pBoard->initBoard();
	addThreeNodes();
}


void GameManager::drawAll(){
	pBoard->draw();
}

void GameManager::addThreeNodes(){
	srand (time(NULL));

	for(int i = 0; i < 3; i++){
		pBoard->generateNode();
	}
}

void GameManager::isValidMove(System::Windows::Forms::MouseEventArgs^  e){
	pBoard->moveNode(e);
	checkLines();
	currentScore = pBoard->getCurrentScore();
}

void GameManager::checkLines(){
	pBoard->checkVertical();
	pBoard->checkHorizontal();
	pBoard->checkDiagonal();
}

void GameManager::resetBoard(){
	pBoard->initBoard();
}
