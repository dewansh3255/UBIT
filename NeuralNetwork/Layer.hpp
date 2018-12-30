#ifndef _LAYER_HPP_
#define _LAYER_HPP_

#include<iostream>
#include"Neuron.hpp"
#include"Matrix.hpp"

class Layer{
	public:
		Layer(int);
		Layer(int , int);
		void setVal(int, double);
		
		Matrix *matrixifyVals(char);
		
		vector<double> getActivatedVals();
		
		vector<Neuron *> getNeurons(){return neurons;	}
		
		void setNeurons(vector<Neuron *> neurons){this->neurons = neurons;	}
		
	private:
		int size;
		vector<Neuron *> neurons;
};

vector<double> Layer::getActivatedVals(){
	vector<double> ret;
	for(int i = 0; i <neurons.size(); i++){
		double v = neurons[i]->getActivatedVal();
		ret.push_back(v);
	}
	return ret;
}

void Layer::setVal(int i, double v){	neurons[i]->setValue(v);}

Layer::Layer(int size){
	this->size = size;
	for(int i = 0; i < size; i++){
		Neuron *newRon = new Neuron(0.00);
		neurons.push_back(newRon);
	}
}

Layer::Layer(int size, int activationType){
	this->size = size;
	for(int i = 0; i < size; i++){
		Neuron *newRon = new Neuron(0.00, activationType);
				//^c dis?
		neurons.push_back(newRon);
	}
}

Matrix *Layer::matrixifyVals(char type = 'o'){
	Matrix *matrixified = new Matrix(1, neurons.size());
	if(type == 'a'){
		for(int i = 0; i < neurons.size(); i++){	matrixified->setValue(0, i, neurons[i]->getActivatedVal());}
	}
	else if(type == 'd'){
		for(int i = 0; i < neurons.size(); i++){	matrixified->setValue(0, i, neurons[i]->getDerivedVal());}
	}
	else{		// o = original values ligma
		for(int i = 0; i < neurons.size(); i++){	matrixified->setValue(0, i, neurons[i]->getValue());}
	}
	return matrixified;
}

#endif
