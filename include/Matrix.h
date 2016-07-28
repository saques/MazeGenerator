#ifndef MATRIX_H
#define MATRIX_H

template <class T>
class Matrix{
	private:
		T* elems;
		int rows,cols;
	public:
		Matrix(int r,int c);
		~Matrix();
		T& get(int i,int j);
		void set(int i,int j,T const& val);
} ;

#endif
