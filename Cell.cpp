#include "Cell.h"

using namespace std;

Cell::Cell(){
	this->w_up=true;
	this->w_left=true;
	this->w_right=true;
	this->w_down=true;
	this->marked=false;
	this->solution=false;
}

bool Cell::up(){
	return this->w_up;
}

bool Cell::left(){
	return this->w_left;
}

bool Cell::right(){
	return this->w_right;
}

bool Cell::down(){
	return this->w_down;
}

void Cell::destroyUp(){
	this->w_up=false;
}

void Cell::destroyLeft(){
	this->w_left=false;
}

void Cell::destroyRight(){
	this->w_right=false;
}

void Cell::destroyDown(){
	this->w_down=false;
}

bool Cell::isMarked(){
	return this->marked;
}

void Cell::mark(){
	this->marked=true;
}

void Cell::unmark(){
	this->marked=false;
}

void Cell::setSolution(){
	this->solution=true;
}

bool Cell::isSolution(){
	return this->solution;
}


