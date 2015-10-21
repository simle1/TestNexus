/*
	Leonard Sim
	Nexus 2000, C++ Programming

	Draws the board and nodes
*/


#include "Drawer.h"
#include "Board.h"
#include <iostream>

using namespace std;

//initialise the Drawer
void Drawer::init(System::Drawing::Graphics ^g){
	formGraphics = g;
	border = gcnew Pen(Color::Gray);
	//saves image into a bitmap
	texture = gcnew TextureBrush((Bitmap^)Image::FromFile("img/free.png"));
}

//draws on the Board depending what value is inside
void Drawer::draw(Board &b){
	for(char i = 0; i < BOARD_HEIGHT; i++){
		for(char j = 0; j < BOARD_WIDTH; j++){
			switch(b.cellType(i,j)){
				case 0:
					formGraphics->DrawImage((Bitmap^)Image::FromFile("img/free.png", true), Rectangle(j * BOARD_CELLSIZE, i * BOARD_CELLSIZE, BOARD_CELLSIZE, BOARD_CELLSIZE));
					break;
				case 1:
					formGraphics->DrawImage((Bitmap^)Image::FromFile("img/blue.png", true), Rectangle(j * BOARD_CELLSIZE, i * BOARD_CELLSIZE, BOARD_CELLSIZE, BOARD_CELLSIZE));
					break;
				case 2:
					formGraphics->DrawImage((Bitmap^)Image::FromFile("img/green.png", true), Rectangle(j * BOARD_CELLSIZE, i * BOARD_CELLSIZE, BOARD_CELLSIZE, BOARD_CELLSIZE));
					break;
				case 3:
					formGraphics->DrawImage((Bitmap^)Image::FromFile("img/yellow.png", true), Rectangle(j * BOARD_CELLSIZE, i * BOARD_CELLSIZE, BOARD_CELLSIZE, BOARD_CELLSIZE));
					break;
				case 4:
					formGraphics->DrawImage((Bitmap^)Image::FromFile("img/red.png", true), Rectangle(j * BOARD_CELLSIZE, i * BOARD_CELLSIZE, BOARD_CELLSIZE, BOARD_CELLSIZE));
					break;
				case 5:
					formGraphics->DrawImage((Bitmap^)Image::FromFile("img/bleau.png", true), Rectangle(j * BOARD_CELLSIZE, i * BOARD_CELLSIZE, BOARD_CELLSIZE, BOARD_CELLSIZE));
					break;
				case 6:
					formGraphics->DrawImage((Bitmap^)Image::FromFile("img/purple.png", true), Rectangle(j * BOARD_CELLSIZE, i * BOARD_CELLSIZE, BOARD_CELLSIZE, BOARD_CELLSIZE));
					break;
				case 7:
					formGraphics->DrawImage((Bitmap^)Image::FromFile("img/selected.png", true), Rectangle(j * BOARD_CELLSIZE, i * BOARD_CELLSIZE, BOARD_CELLSIZE, BOARD_CELLSIZE));
					break;
			}
		}
	}
}