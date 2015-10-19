#include "GameManager.h"
#include "Drawer.h"
#include <stdlib.h>
#include <time.h> 

GameManager::GameManager(void)
{
	pBoard = 0;
	pBoard = new Board();
	initializedStartGoal = false;
	foundGoal = false;
}

void GameManager::gameStart(void){
	totalScore = 0;
	gameStarted = true;
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
	pBoard->checkVertical();
	pBoard->checkHorizontal();
	pBoard->checkDiagonal();
}

void GameManager::FindPath(System::Windows::Forms::MouseEventArgs^  e){
	eventPosX = e->X / 40;
	eventPosY = e->Y / 40;

	if (selectedNode == true){
		if(pBoard->cellType(eventPosX, eventPosY) == 0){

			if(!initializedStartGoal){

			for(int i = 0; i < openList.size(); i++){
				delete openList[i];
			}
			openList.clear();

			for(int i= 0; i < visitedList.size(); i++){
				delete visitedList[i];
			}
			visitedList.clear();

			for(int i= 0; i < pathToGoal.size(); i++){
				delete pathToGoal[i];
			}
			pathToGoal.clear();

			Node start;
			start.posX = initialEX;
			start.posY = initialEY;

			Node goal;
			goal.posX = eventPosX;
			goal.posY = eventPosY;

			setStartAndGoal(start, goal);
			initializedStartGoal = true;
			}
		}
	}
	if(initializedStartGoal){
		continuePath();
	}
	}else{
		if(pBoard->cellType(eventPosX, eventPosY) != 0){
			initialEX = eventPosX;
			initialEY = eventPosY;

			selectedNode = true;
		}
	}
}

void GameManager::setStartAndGoal(Node start, Node goal){
	startCell = new Node(start.posX, start.posY, NULL);
	goalCell = new Node(goal.posX, goal.posY, &goal);

	startCell->G = 0;
	startCell->H = startCell->ManHattanDistance(goalCell);
	startCell->parent = 0;

	openList.push_back(startCell);
}

//finds cell with the best F value and returns the cell
Node* GameManager::GetNextCell()
{
  float bestF = 999999.0f;
  int cellIndex = -1;
  Node* nextCell = NULL;

  for(int i = 0; i < openList.size(); i++)
  {
    if(openList[i]->GetF() < bestF)
    {
      bestF = openList[i]->GetF();
      cellIndex = i;
    }
  }

  if(cellIndex >= 0)
  {
    nextCell = openList[cellIndex];
    visitedList.push_back(nextCell);
    openList.erase(openList.begin() + cellIndex);
  }

  return nextCell;
}

void GameManager::PathOpened(int x, int y, float newCost, Node *parent)
{
  //checks if there is a filled cell and if there is it will drop out of the method
  if(pBoard->cellType(x,y) != 0)
  {
    return;
  }

  //checks if the id is the same as the id in the visited list
  //that means it has been visited before and is considered as untraversable 
  /*int id = z * WORLD_SIZE + x;
  for(int i = 0; i < m_visitedList.size(); i++)
  {
    if(id == m_visitedList[i]->m_id)
    {
      return;
    }
  }*/

  //checks to see if any cell in the visitedList has the same X & Y value as the one found on the path
  //if they do then the method will be dropped
  for(int i = 0; i < visitedList.size(); i++)
  {
    if(x == visitedList[i]->posX && y == visitedList[i]->posY)
    {
      return;
    }
  }

  //create a child cell that will point to the parent cell
  Node* newChild = new SearchCell(x, y, parent);
  newChild->G = newCost;
  //H value of child is the parent's manhattan distance to the goal cell
  newChild->H = parent->ManHattanDistance(goalCell);

  for(int i = 0; i < openList.size(); i++)
  {
    //if(id == m_openList[i]->m_id)
	if(x == openList[i]->posX && y == openList[i]->posY)
    {
      float newF = newChild->G + newCost + openList[i]->H;

      //if newF is smaller than the one in the openList then replace it with the new one
      if(openList[i]->GetF() > newF)
      {
		//the node inside the openList will update its G value and will be set as the parent node
        openList[i]->G = newChild->G + newCost;
        opentList[i]->parent = newChild;
      }
      else //if F is not better then newChild node is deleted and method is dropped
      {
        delete newChild;
        return;
      }
    }
  }
  //newChild node is pushed into the openList
  openList.push_back(newChild);
}

void GameManager::continuePath()
{
  //if the openList has nothing inside, drop the method
  if(openList.empty())
  {
    return;
  }

  //when path continues, currentCell node is saved with the GetNextCell() method 
  //which pulls the cell with the best F value from the openList
  Node* currentCell = GetNextCell();
	
  //goalCell's parent will be saved with the currentCell's parent
  if((currentCell->posX && currentCell->posY) == (goalCell->posX && goalCell->posY))
  {
    goalCell->parent = currentCell->parent;

    Node* getPath;

    //Goes through goalCells, set getPath and will pushback the shortest path that is inside the goalCell
    for(getPath = goalCell; getPath != NULL; getPath = getPath->parent)
    {
      pathToGoal.push_back(new Vector3(getPath->posX, getPath->posY, 0));
    }

    foundGoal = true;
    return;
  }
  else
  {
    //rightCell
    PathOpened(currentCell->posX + 1, currentCell->posY, currentCell->G + 1 * CELL_SIZE, currentCell);

    //leftCell
    PathOpened(currentCell->posX - 1, currentCell->posY, currentCell->G - 1 * CELL_SIZE, currentCell);

    //topCell
    PathOpened(currentCell->posX, currentCell->posY + 1, currentCell->G + 1 * CELL_SIZE, currentCell);

    //bottomCell
    PathOpened(currentCell->posX - 1, currentCell->posY, currentCell->G + 1 * CELL_SIZE, currentCell);

    //left-up diagonal
    PathOpened(currentCell->posX - 1, currentCell->posY + 1, currentCell->G + 1.414f * CELL_SIZE, currentCell);

    //right-up diagonal
    PathOpened(currentCell->posX + 1, currentCell->posY, currentCell->G + 1.414f * CELL_SIZE, currentCell);

    //left-down diagonal
    PathOpened(currentCell->posX - 1, currentCell->posY- 1, currentCell->G + 1.414f * CELL_SIZE, currentCell);

    //right-down diagonal
    PathOpened(currentCell->posX + 1, currentCell->posY - 1, currentCell->G + 1.414f * CELL_SIZE, currentCell);

    for(int i = 0; i < openList.size(); i++)
    {
		if((currentCell->posX && currentCell->posY) == (opentList[i]->posX && openList[i]->posY))
      {
        m_openList.erase(m_openList.begin() + i);
      }
    }
  }
}