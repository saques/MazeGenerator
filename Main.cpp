#include <cstdlib>
#include <iostream>
#include "Maze.h"
#include "SVGPrinter.h"


using namespace std;

int main(int argc,char* argv[]){
	if(argc!=3){
		cout<< "Insufficient arguments" << endl ;
		return 1;
	}
	int dim=atoi(argv[1]);
	if(dim<2){
		cout<< "Must specify a valid dimension" << endl ;
		return 1;
	}
	int show=atoi(argv[2]);
	if(show!=0 && show!=1){
		cout<< "Must specify desire to show the solution" << endl;
		return 1;
	}
	Maze m(dim,0,0);
	SVGPrinter p;
	p.print(m,(bool)show);
	cout << "Generated a " << dim << "x" << dim << " maze" << endl;
}
	
