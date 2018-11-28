#ifndef _MATRIX_HPP_
#define _MATRIX_HPP_

#include<iostream>
#include<vector>
#include<random>
#include<iomanip>
#include<chrono>

using namespace std;

class Matrix{
	public:
		Matrix(int, int, bool);
		
		Matrix *transpose();
		Matrix *copy();
		
		void setValue(int r, int c, double v){values[r][c] = v;	}
		double getValue(int r, int c){return values[r][c];	}
		
		void printToConsole();
		
		int getRows(){return numRows;	}
		int getCols(){return numCols;	}
		
	private:
		double randomNumber();
		
		int numRows;
		int numCols;
		
		vector< vector<double> > values;
};

#endif
