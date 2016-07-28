#include "Matrix.h"
#include "Cell.h"

using namespace std;

template <class T>
Matrix<T>::Matrix(int r,int c){
		this->rows=r;
		this->cols=c;
		this->elems = new T[rows*cols];
}

template <class T>
Matrix<T>::~Matrix(){
	delete[] this->elems;
}

template <class T>
T& Matrix<T>::get(int i,int j){
	if (i<0 || i>=this->rows || j<0 || j>=this->cols){
		throw 0;
	}
	return this->elems[i*rows + j];
}

template <class T>
void Matrix<T>::set(int i,int j,T const& val){
	if (i<0 || i>=this->rows || j<0 || j>=this->cols){
		throw 0;
	}
	this->elems[i*rows+j]=val;
}

template class Matrix<int>;
template class Matrix<Cell>;
