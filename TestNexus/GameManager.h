#pragma once
#include "Board.h"
#include <vector>
#include "Vector3.h"
#include "Board.h"

#ifndef _GAME
#define _GAME


class GameManager
{
	Board *pBoard;
	int totalScore;
	bool gameStarted;

	bool initializedStartGoal;
	bool foundGoal;
	Node *startCell;
	Node *goalCell;

	int eventPosX;
	int eventPosY;
	int initialEX;
	int initialEY;

	std::vector<Node*> openList;
	std::vector<Node*> visitedList;
	std::vector<Node*> pathToGoal;
	
public:
	GameManager(void);
	void gameStart(void);
	void drawAll();
	void addThreeNodes();
	void isValidMove(System::Windows::Forms::MouseEventArgs^  e);
	inline bool isGameStarted(){ return gameStarted; }

	void FindPath(Vector3 currentPos, Vector3 targetPos);
	void clearOpentList(){ openList.clear(); }
	void clearVisitedList(){ visitedList.clear(); }
	void clearPathToGoal(){ pathToGoal.clear(); }

	void setStartAndGoal(Node start, Node goal);
	void pathOpened(int x, int y, float newCost, Node *parent);
	Node *GetNextCell();
	void continuePath();

};

#endif
