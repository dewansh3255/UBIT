#include"NeuralNetwork.hpp"

void NeuralNetwork::setCurrentInput(vector<double> input){
	this->input = input;
	for(int i = 0; i < input.size(); i++){	layers[0]->setVal(i, input[i]);}
}

void NeuralNetwork::setErrors(){
	if(
		this->target.size()
		!= layers[layers.size() - 1]->getNeurons().size()
		){
		cerr << "Target Incorrect!" << endl;
		assert(false);
	}
	//If Target OK
	setErrorMSE();
}

void NeuralNetwork::setErrorMSE(){
	int outputLayer = this->layers.size() - 1;
	vector<Neuron *> outputNeurons = layers[outputLayer]->getNeurons();
	error = 0.00;
	for(int i = 0; i <target.size(); i++){
		double t = target[i];
		double y = outputNeurons[i]->getActivatedVal();
		
		errors[i]			=  0.5 * pow(abs( (t - y)), 2);
		derivedErrors[i]	= y - t;
		error				+= errors[i];
	}	
}
