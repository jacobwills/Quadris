#include "zblock.h"
#include <iostream>

using namespace std;

ZBlock::ZBlock(Board *b, int lvl) {
	level = lvl;
	type = 'Z';
	positions = new Coordinate[4];
	config = 1;
	
	positions[0].setX(0);
	positions[0].setY(3);
	positions[1].setX(1);
	positions[1].setY(3);
	positions[2].setX(1);
	positions[2].setY(4);
	positions[3].setX(2);
	positions[3].setY(4);
	
	gameOver = false;
	for (int i = 0; i < 4; i++) {
		if (b->isOccupied(positions[i].getY(), positions[i].getX()))
			gameOver = true;
	}
	
	// Update the display
	for (int i = 0; i < 4; i++) {
		b->update(positions[i].getY(), positions[i].getX(), type);
	}
}

ZBlock::~ZBlock(){
	delete [] positions;
}

void ZBlock::clockwise(Board *b){ // r and c not needed here
	bool temp = true;
	// Update the display
	for (int i = 0; i < 4; i++) {
		b->update(positions[i].getY(), positions[i].getX(), ' ');
	}
	
	if(config == 1){
		configTwo(positions[0].getY() + 1, positions[0].getX());
		config = 2;
	}
	else if(config == 2){
		configOne(positions[1].getY(), positions[1].getX());
		config = 1;
	}
	
	for (int i = 0; i < 4; i++) {
		if (positions[i].getY() > 17 || positions[i].getX() > 9 || positions[i].getX() < 0 || b->isOccupied(positions[i].getY(), positions[i].getX()))
			temp = false;
	}
	
	
	if(!temp){
		if(config == 1){
			configTwo(positions[0].getY()+ 1, positions[0].getX());
			config = 2;
		}
		else if(config == 2){
			configOne(positions[1].getY(), positions[1].getX());
			config = 1;
		}
	}
	
	// Update the display
	for (int i = 0; i < 4; i++) {
		b->update(positions[i].getY(), positions[i].getX(), type);
	}
}

void ZBlock::counterclockwise(Board *b){ // r and c not needed here
	bool temp = true;
	// Update the display
	for (int i = 0; i < 4; i++) {
		b->update(positions[i].getY(), positions[i].getX(), ' ');
	}
	
	if(config == 1){
		configTwo(positions[0].getY()+ 1, positions[0].getX());
		config = 2;
	}
	else if(config == 2){
		configOne(positions[1].getY(), positions[1].getX());
		config = 1;
	}
	
	for (int i = 0; i < 4; i++) {
		if (positions[i].getY() > 17 || positions[i].getX() > 9 || positions[i].getX() < 0 || b->isOccupied(positions[i].getY(), positions[i].getX()))
			temp = false;
	}
	
	
	if(!temp){
		if(config == 1){
			configTwo(positions[0].getY() + 1, positions[0].getX());
			config = 2;
		}
		else if(config == 2){
			configOne(positions[1].getY(), positions[1].getX());
			config = 1;
		}
	}
	
	// Update the display
	for (int i = 0; i < 4; i++) {
		b->update(positions[i].getY(), positions[i].getX(), type);
	}
}

void ZBlock::configOne(int r, int c){
	positions[0].setY(r-1);
	positions[0].setX(c);
	positions[1].setY(r-1);
	positions[1].setX(c+1);
	positions[2].setY(r);
	positions[2].setX(c+1);
	positions[3].setY(r);
	positions[3].setX(c+2);
}

void ZBlock::configTwo(int r, int c){
	positions[0].setY(r-1);
	positions[0].setX(c);
	positions[1].setY(r);
	positions[1].setX(c);
	positions[2].setY(r-2);
	positions[2].setX(c+1);
	positions[3].setY(r-1);
	positions[3].setX(c+1);
}