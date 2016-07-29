#ifndef CELL_H
#define CELL_H

class Cell {
	
	private: 
		bool w_up,w_left,w_right,w_down,marked,solution;
	public:
		Cell();
		bool up();
		bool left();
		bool right();
		bool down();
		void destroyUp();
		void destroyLeft();
		void destroyRight();
		void destroyDown();
		bool isMarked();
		void mark();
		void unmark();
		void setSolution();
		bool isSolution();
} ;

#endif
