#include "Maze.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

static const int MOV[4][2]={{-1,0},{0,-1},{0,1},{1,0}};


static bool isValid(int i,int j,int dim){
	return i>=0 && j>=0 && i<dim && j<dim;
}

static void shuffle(int arr[],int size){
	for (int i=0;i<size;i++){
		int pos=rand()%size;
		int tmp=arr[pos];
		arr[pos]=arr[i];
		arr[i]=tmp;
	}
}

Maze::Maze(int dim,int i,int j){
	if(!isValid(i,j,dim)){
		throw 0;
	}
	this->m= new Matrix<Cell>(dim,dim);
	this->dim=dim;
	srand(time(0));
	apply(i,j);
}

Maze::~Maze(){
	delete this->m;
}

void Maze::apply(int i,int j){
	Cell& current=this->m->get(i,j);
	current.mark();
	int dirs[]={0,1,2,3};
	shuffle(dirs,4);
	for(int k=0;k<4;k++){
		int n_i=i+MOV[dirs[k]][0],n_j=j+MOV[dirs[k]][1];
		if(!isValid(n_i,n_j,this->dim))
			continue;
		Cell& other=this->m->get(n_i,n_j);
		if(!other.isMarked()){
			switch(dirs[k]){
				case 0:
					current.destroyUp();
					other.destroyDown();
					break;
				case 1:
					current.destroyLeft();
					other.destroyRight();
					break;
				case 2:
					current.destroyRight();
					other.destroyLeft();
					break;
				case 3:
					current.destroyDown();
					other.destroyUp();
					break;
				default:
					break;
			}
			apply(n_i,n_j);
		}
	}
}


