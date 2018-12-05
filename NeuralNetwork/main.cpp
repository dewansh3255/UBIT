#include"train.cpp"

using namespace std;

main(){
	
	vector< double > input;
	input.push_back(0.2);
	input.push_back(0.3);
	input.push_back(0.4);
	input.push_back(0.5);
	input.push_back(0.6);
	input.push_back(0.7);
	input.push_back(0.8);
	input.push_back(0.9);
	input.push_back(1.0);
	input.push_back(1.1);
	input.push_back(1.2);
	input.push_back(1.3);
	input.push_back(1.4);
	input.push_back(1.5);
	input.push_back(1.6);
	input.push_back(1.7);
	input.push_back(1.8);
	
	vector<double> target;
	target.push_back(1);
	target.push_back(0);
	
	double learningRate = 0.05;
	double momentum = 1;
	double bias = 1;
	
	vector<int> topology;
	topology.push_back(17);
	topology.push_back(6);
	topology.push_back(2);
	
	NeuralNetwork *n = new NeuralNetwork(topology, 2, 3, 1, 1, 0.05, 1);
	
	for(int i = 0; i < 10000; i++){
		
		n->train(input, target, bias, learningRate, momentum);
		cout << "Error: " <<n->error << endl;
	}
	
}
