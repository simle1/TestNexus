#pragma once
#include "Board.h"
#include <vector>
#include "Board.h"

#ifndef _GAME
#define _GAME


class GameManager
{
	Board *pBoard;
	int totalScore;
	bool gameStarted;
	
public:
	GameManager(void);
	void gameStart(void);
	void drawAll();
	void addThreeNodes();
	void isValidMove(System::Windows::Forms::MouseEventArgs^  e);
	void checkLines();
	inline bool isGameStarted(){ return gameStarted; };

};

#endif
