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
		
		int activationType = 3;
};

#endif
