#include"neuralnetwork.cpp"
#include"feedForward.cpp"
#include"backPropogation.cpp"

void NeuralNetwork::train(
			vector<double> input,
			vector<double> target,
			double bias,
			double learningRate,
			double momentum
			){
				this->learningRate	= learningRate;
				this->momentum		= momentum;
				this->bias			= bias;
				
				setCurrentInput(input);
				setCurrentTarget(target);
				cout <<"set" << endl;
				feedForward();
				setErrors();
				cout <<"error" << endl;
				backPropagation();
}
