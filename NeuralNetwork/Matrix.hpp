#ifndef _MATRIX_HPP_
#define _MATRIX_HPP_

#include<iostream>
#include<vector>
#include<random>
#include<iomanip>

using namespace std;

class Matrix{
	public:
		Matrix(int, int, bool);
		
		Matrix *transpose();
		Matrix *copy();
		
		static void multiplyMatrix(Matrix *a, Matrix *b, Matrix *c);
		
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

Matrix *Matrix::transpose(){
	Matrix *trans = new Matrix(numCols, numRows, false);
	for(int i = 0; i < numRows; i++){
		for(int j = 0; j < numCols; j++){	trans->setValue(j, i, getValue(i, j));}
	}
	return trans;
}

Matrix *Matrix::copy(){
	Matrix *same = new Matrix(numCols, numRows, false);
	for(int i = 0; i < numRows; i++){
		for(int j = 0; j < numCols; j++){	same->setValue(i, j, getValue(i, j));}
	}
	return same;
}

Matrix::Matrix(int numRows, int numCols, bool isRandom = false){
	this->numRows = numRows;
	this->numCols = numCols;
	
	for(int i = 0; i < numRows; i++){
		vector<double> colVals;
		for(int j = 0; j < numCols; j++){
			double r = 0.00;
			if(isRandom){	r = randomNumber();}
			colVals.push_back(r);
		}
		values.push_back(colVals);
	}
}

double Matrix::randomNumber(){
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<> dis(-.0001, .0001);
	return dis(gen);
}

void Matrix::printToConsole(){
	for(int i = 0; i < numRows; i++){
		for(int j = 0; j < numCols; j++){
			cout << values[i][j] << "	";
		}
		cout << endl;
	}
}

void Matrix::multiplyMatrix(Matrix *a, Matrix *b, Matrix *c){
	double product, newVal = 0.00;
	for(int i = 0; i < a->getRows(); i++){
		for(int j = 0; j < b->getCols(); j++){
			for(int k = 0; k < b->getRows(); k++){
				product = a->getValue(i, k) * b->getValue(k, j);
				newVal += product;
			}
			c->setValue(i, j, newVal);
		}
	}
}

#endif
