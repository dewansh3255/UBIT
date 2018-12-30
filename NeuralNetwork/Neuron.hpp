#ifndef _NEURON_HPP_
#define _NEURON_HPP_

#define TANH 1
#define RELU 2
#define SIGM 3

#include<cmath>
#include<iostream>
using namespace std;

class Neuron{
	public:
		Neuron(double);
		Neuron(double, int);
		
		void setValue(double);
		void activate();
		void derive();
		
		double getValue() const {return val;}
		double getActivatedVal() const {return activatedVal;}
		double getDerivedVal() const {return derivedVal;}
		
	private:
		double val;
		double activatedVal;
		double derivedVal;
		
		int activationType = 3;		//default sigmoid for now
};

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
	if(activationType == TANH){	activatedVal = tanh(val);}
	else if(activationType == RELU){
		if(val > 0){	activatedVal = val;}
		else{	activatedVal = 0;}
	}
	else{	activatedVal = (1 / (1 + exp(-val)));}
}

void Neuron::derive(){
	if(activationType == TANH){
		derivedVal = (1.0 - (activatedVal * activatedVal));
	}
	else if(activationType == RELU){
		if(val > 0){	derivedVal = 1;}
		else{	derivedVal = 0;}
	}
	else{	derivedVal = activatedVal * (1 - activatedVal);}
}

#endif
