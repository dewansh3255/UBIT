#include"layer.hpp"

vector<double> Layer::getActivatedVals(){
	vector<double> ret;
	for(int i = 0; i <neurons.size(); i++){
		double v = neurons[i]->getActivatedVal();
		ret.push_back(v);
	}
	return ret;
}

void Layer::setVal(int i, double v){
	neurons[i]->setValue(v);
}

Layer::Layer(int size){
	this->size = size;
	for(int i = 0; i < size; i++){
		Neuron *n = new Neuron(0.00);
		neurons.push_back(n);
	}
}

Layer::Layer(int size, int activationType){
	this->size = size;
	
	for(int i = 0; i < size; i++){
		Neuron *n = new Neuron(0.00, activationType);
		neurons.push_back(n);
	}
}

Matrix *Layer::matrixifyVals(){
	Matrix *m = new Matrix(1, neurons.size(), false);
	for(int i = 0; i < neurons.size(); i++){
		m->setValue(0, i, neurons[i]->getValue());
	}
	return m;
}

Matrix *Layer::matrixifyActivatedVals(){
	Matrix *m = new Matrix(1, neurons.size(), false);
	for(int i = 0; i < neurons.size(); i++){
		m->setValue(0, i, neurons[i]->getActivatedVal());
	}
	return m;
}

Matrix *Layer::matrixifyDerivedVals(){
	Matrix *m = new Matrix(1, neurons.size(), false);
	for(int i = 0; i < neurons.size(); i++){
		m->setValue(0, i, neurons[i]->getDerivedVal());
	}
	return m;
}
