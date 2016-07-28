#ifndef MAZE_H
#define MAZE_H

#include "Matrix.h"
#include "Cell.h"

class Maze{
	friend class SVGPrinter;
	private:
		Matrix<Cell>* m;
		int dim;
		void apply(int i,int j);
	public:
		Maze(int dim,int i,int j);
		~Maze();
} ;

#endif
