#ifndef _NEURAL_NETWORK_HPP_
#define _NEURAL_NETWORK_HPP_

#define COST_MSE 1

#include<iostream>
#include<vector>
#include<algorithm>
#include<cassert>
#include<cmath>
#include"Layer.hpp"

using namespace std;

class NeuralNetwork{
	public:
		NeuralNetwork(
			vector<int> topology,
			double bias = 1,
			double learningRate = 0.05,
			double momentum = 1
			);
		
		NeuralNetwork(
			vector<int> topology,
			int hiddenActivationType,
			int outputActivationType,
			int costFunctionType,
			double bias = 1,
			double learningRate = 0.05,
			double momentum = 1
			);
		
		void train(vector<double>, vector<double>, double, double, double);
		
		void setCurrentInput(vector<double> input);
		void setCurrentTarget(vector<double> target){this->target = target;	}
		
		void feedForward();
		void backPropagation();
		void setErrors();
		
		vector<double> getActivatedVals(int index){return layers[index]->getActivatedVals();	}
		Matrix *getNeuronMatrix(int index){return layers[index]->matrixifyVals();	}
		Matrix *getActivatedNeuronMatrix(int index){return layers[index]->matrixifyVals('a');	}
		Matrix *getDerivedNeuronMatrix(int index){return layers[index]->matrixifyVals('d');	}
		Matrix *getWeightMatrix(int index){return new Matrix(*weightMatrices[index]);	}
		
		void setNeuronValue(int indexLayer, int indexNeuron, double v){
			layers[indexLayer]->setVal(indexNeuron, v);
		}
		
		int topologySize;
		int hiddenActivationType = 2;
		int outputActivationType = 3;
		int costFunctionType = COST_MSE;
	
		vector<int> topology;
		vector<Layer *> layers;
		vector<Matrix *> weightMatrices;
		vector<Matrix *> gradientMatrices;
	
		vector<double> input;
		vector<double> target;
		vector<double> errors;
		vector<double> derivedErrors;
		
		double error	= 0.00;
		double bias		= 1.00;
		double momentum;
		double learningRate;
	
	private:
		void setErrorMSE();
	
};

NeuralNetwork::NeuralNetwork(
	vector<int> topology,
	int hiddenActivationType,
	int outputActivationType,
	int costFunctionType,
	double bias,
	double learningRate,
	double momentum
):		//Constructor delegation C++11 ka kamal
NeuralNetwork(topology, bias, learningRate, momentum){
	this->hiddenActivationType = hiddenActivationType;
	this->outputActivationType = outputActivationType;
	this->costFunctionType = costFunctionType;
	
	
}

NeuralNetwork::NeuralNetwork(
	vector<int> topology,
	double bias,
	double learningRate,
	double momentum
){
	this->topology = topology;
	this->topologySize = topology.size();
	this->learningRate = learningRate;
	this->momentum = momentum;
	this->bias = bias;
	
	for(int i = 0; i < topologySize; i++){
		Layer *l;
		if(i > 0 && i < topologySize - 1){
			l = new Layer(topology[i], this->hiddenActivationType);
		}
		else if(i == topologySize - 1){
			l = new Layer(topology[i], this->outputActivationType);
		}
		else{
			l = new Layer(topology[i]);
		}
		layers.push_back(l);
	}
	
	for(int i = 0; i < topologySize - 1; i++){
		Matrix *weightMatrix = new Matrix(topology[i], topology[i+1], true);
		weightMatrices.push_back(weightMatrix);
	}
	
	for(int i = 0; i <topology[topologySize - 1]; i++){
		errors.push_back(0.00);
		derivedErrors.push_back(0.00);
	}
	error = 0.00;
}

#endif
