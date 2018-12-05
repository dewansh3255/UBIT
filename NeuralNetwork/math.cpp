#include"math.hpp"

void Math::multiplyMatrix(Matrix *a, Matrix *b, Matrix *c){
	double p, newVal = 0.00;
	for(int i = 0; i < a->getRows(); i++){
		for(int j = 0; j < b->getCols(); j++){
			for(int k = 0; k < b->getRows(); k++){
				p = a->getValue(i, k) * b->getValue(k, j);
				newVal += p;
			}
			c->setValue(i, j, newVal);
		}
	}
}
