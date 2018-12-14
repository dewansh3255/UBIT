#include"matrix.hpp"

Matrix *Matrix::transpose(){
	Matrix *m = new Matrix(numCols, numRows, false);
	
	for(int i = 0; i < numRows; i++){
		for(int j = 0; j < numCols; j++){
			m->setValue(j, i, getValue(i, j));
		}
	}
	return m;
}

Matrix *Matrix::copy(){
	Matrix *m = new Matrix(numCols, numRows, false);
	
	for(int i = 0; i < numRows; i++){
		for(int j = 0; j < numCols; j++){
			m->setValue(i, j, getValue(i, j));
		}
	}
	return m;
}

Matrix::Matrix(int numRows, int numCols, bool isRandom){
	this->numRows = numRows;
	this->numCols = numCols;
	
	for(int i = 0; i < numRows; i++){
		vector<double> colVals;
		for(int j = 0; j < numCols; j++){
			double r = 0.00;
			if(isRandom){
				r = randomNumber();
			}
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
	/*
	static std::mt19937 gen(chrono::high_resolution_clock::now().time_since_epoch().count());
	std::uniform_real_distribution<> dis(-0.0001, 0.0001);
	return dis(gen);*/
}

void Matrix::printToConsole(){
	for(int i = 0; i < numRows; i++){
		for(int j = 0; j < numCols; j++){
			cout << values[i][j] << "	";
		}
		cout << endl;
	}
}
