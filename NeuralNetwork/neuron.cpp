#include"neuron.hpp"

Neuron::Neuron(double val){
	setValue(val);
}

Neuron::Neuron(double val, int activationType){
	this->activationType = activationType;
	setValue(val);
}

void Neuron::setValue(double val){
	this->val = val;
	activate();
	derive();
}

void Neuron::activate(){
	if(activationType == TANH){
		activatedVal = tanh(val);
	}
	else if(activationType == RELU){
		if(val > 0){
			activatedVal = val;
		}
		else{
			activatedVal = 0;
		}
	}
	else{
		activatedVal = (1 / (1 + exp(-val)));
	}
}

void Neuron::derive(){
	if(activationType == TANH){
		derivedVal = (1.0 - (activatedVal * activatedVal));
	}
	else if(activationType == RELU){
		if(val > 0){
			derivedVal = 1;
		}
		else{
			derivedVal = 0;
		}
	}
	else{
		derivedVal = activatedVal * (1 - activatedVal);
	}
}
