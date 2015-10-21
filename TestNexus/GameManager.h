/*
	Leonard Sim
	Nexus 2000, C++ Programming
	
*/


#pragma once
#include "Board.h"
#include <vector>
#include "Board.h"

#ifndef _GAME
#define _GAME


class GameManager
{
	Board *pBoard;
	int currentScore;
	int highScore;
	bool gameStarted;
	
public:
	GameManager(void);
	void gameStart(void);
	void drawAll();
	void addThreeNodes();
	void checkLines();
	void move(System::Windows::Forms::MouseEventArgs^  e);
	void setGameStarted(bool state){ gameStarted = state; }

	inline bool isGameStarted(){ return gameStarted; }
	bool endState();
	int getCurrentScore(){ return currentScore; }
	int getHighScore(){ return pBoard->getHighScore(); }

};

#endif
