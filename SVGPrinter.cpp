#include "SVGPrinter.h"
#include "Maze.h"
#include <fstream>
#include <iostream>

using namespace std;


void SVGPrinter::print(Maze const& mz){
	Matrix<Cell>* m=mz.m;
	int dim=mz.dim;
	
	ofstream out;
	out.open("out.svg");
	
	out<< "<?xml version=\"1.0\" encoding=\"utf-8\"?>" << endl ;
	out<< "<svg width=\"" <<20*dim <<"px\" height=\""<<20*dim<<"px\"  xmlns=\"http://www.w3.org/2000/svg\">" << endl ;
	out<<  "<rect width=\"" <<  20*dim << "\" height=\"" <<  20*dim  <<"\" style=\"fill:rgb(0,0,0)\"/>" << endl ;
	for(int i=0;i<dim;i++){
		for(int j=0;j<dim;j++){
			Cell c = m->get(i,j);	
			int x00,x01,x10,x11;
			x00=x01=j*20;
			x10=x11=j*20+19;
			int y00,y01,y10,y11;
			y00=y10=i*20;
			y01=y11=i*20+19;
			if(c.up()){
				out<< "<line x1=\"" << x00 <<"\" y1=\"" << y00 << "\" x2=\"" <<x10<< "\" y2=\"" << y10 <<"\" style=\"stroke:rgb(255,0,0);stroke-width:2\" />" << endl ;
			}
			if(c.left()){
				out<< "<line x1=\"" << x00 <<"\" y1=\"" << y00 << "\" x2=\"" <<x01<< "\" y2=\"" << y01 <<"\" style=\"stroke:rgb(255,0,0);stroke-width:2\" />" << endl ;
			}
			if(c.right()){
				out<< "<line x1=\"" << x10 <<"\" y1=\"" << y10 << "\" x2=\"" <<x11<< "\" y2=\"" << y11 <<"\" style=\"stroke:rgb(255,0,0);stroke-width:2\" />" << endl ;
			}
			if(c.down()){
				out<< "<line x1=\"" << x01 <<"\" y1=\"" << y01 << "\" x2=\"" <<x11<< "\" y2=\"" << y11 <<"\" style=\"stroke:rgb(255,0,0);stroke-width:2\" />" << endl ;
			}
		}
	}
	
	out << "</svg>" << endl ;
	
	out.close();
}
