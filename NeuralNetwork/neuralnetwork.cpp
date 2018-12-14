#include"neuralnetwork.hpp"

void NeuralNetwork::setCurrentInput(vector<double> input){
	this->input = input;
	for(int i = 0; i < input.size(); i++){
		layers[0]->setVal(i, input[i]);
	}
}

NeuralNetwork::NeuralNetwork(
	vector<int> topology,
	int hiddenActivationType,
	int outputActivationType,
	int costFunctionType,
	double bias,
	double learningRate,
	double momentum
){
	this->topology = topology;
	this->topologySize = topology.size();
	this->learningRate = learningRate;
	this->momentum = momentum;
	this->bias = bias;
	
	this->hiddenActivationType = hiddenActivationType;
	this->outputActivationType = outputActivationType;
	this->costFunctionType = costFunctionType;
	
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

void NeuralNetwork::setErrors(){
	if(this->target.size() == 0){
		cerr << "No traget" << endl;
		assert(false);
	}
	if(this->target.size() != layers[layers.size() - 1]->getNeurons().size()){
		cerr << "Target size is not same" << endl;
		assert(false);
	}
	
	switch(costFunctionType){
		case(COST_MSE):	setErrorMSE();	break;
		default: setErrorMSE();	break;
	}
	
}

void NeuralNetwork::setErrorMSE(){
	int outputLayer = this->layers.size() - 1;
	vector<Neuron *> outputNeurons = layers[outputLayer]->getNeurons();
	error = 0.00;
	for(int i = 0; i <target.size(); i++){
		double t = target[i];
		double y = outputNeurons[i]->getActivatedVal();
		
		errors[i] =  0.5 * pow(abs( (t - y)), 2);
		derivedErrors[i] = y - t;
		error += errors[i];
	}
	
}
