#ifndef _LAYER_HPP_
#define _LAYER_HPP_

#include<iostream>
#include"neuron.cpp"
#include"matrix.cpp"

class Layer{
	public:
		Layer(int);
		Layer(int , int);
		void setVal(int, double);
		
		Matrix *matrixifyVals();
		Matrix *matrixifyActivatedVals();
		Matrix *matrixifyDerivedVals();
		
		vector<double> getActivatedVals();
		
		vector<Neuron *> getNeurons(){return neurons;	}
		
		void setNeurons(vector<Neuron *> neurons){this->neurons = neurons;	}
		
	private:
		int size;
		vector<Neuron *> neurons;
};

#endif
