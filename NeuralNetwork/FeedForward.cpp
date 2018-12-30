#include"NeuralNetwork.hpp"

void NeuralNetwork::feedForward(){
	Matrix *a;	//Neurons on left
	Matrix *b;	//Weights
	Matrix *c;	//Next Neurons
	
	for(int i = 0; i < topologySize - 1; i++){
		if(i){	a = getActivatedNeuronMatrix(i);}
		else{	a = getNeuronMatrix(i);}
		b = getWeightMatrix(i);
		c = new Matrix(a->getRows(), b->getCols());
		Matrix::multiplyMatrix(a, b, c);
		
		for(int indexC = 0; indexC < c->getCols(); indexC++){
			setNeuronValue(i + 1, indexC, c->getValue(0, indexC) + bias);
		}
		delete a, b, c;
	}
}
