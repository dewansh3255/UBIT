#ifndef _NEURAL_NETWORK_HPP_
#define _NEURAL_NETWORK_HPP_

#define COST_MSE 1

#include<iostream>
#include<vector>
#include<algorithm>
#include<cassert>
#include<cmath>
#include"layer.cpp"
#include"math.cpp"

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
		Matrix *getActivatedNeuronMatrix(int index){return layers[index]->matrixifyActivatedVals();	}
		Matrix *getDerivedNeuronMatrix(int index){return layers[index]->matrixifyDerivedVals();	}
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
		
		double error = 0.00;
		double bias = 1.00;
		double momentum;
		double learningRate;
	
	private:
		void setErrorMSE();
	
};

#endif
