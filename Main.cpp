#include <cstdlib>
#include <iostream>
#include "Maze.h"
#include "SVGPrinter.h"


using namespace std;

int main(int argc,char* argv[]){
	if(argc!=2){
		cout<< "Must specify a valid dimension" << endl ;
		return 1;
	}
	int dim=atoi(argv[1]);
	if(dim<2){
		cout<< "Must specify a valid dimension" << endl ;
		return 1;
	}
	Maze m(dim,0,0);
	SVGPrinter p;
	p.print(m);
	cout << "Generated a " << dim << "x" << dim << " maze" << endl;
}
	
