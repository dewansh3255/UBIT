#ifndef _MATH_HPP_
#define _MATH_HPP_

#include<iostream>
#include<vector>
#include<cassert>
#include"matrix.hpp"

using namespace std;

class Math{
	public:
		static void multiplyMatrix(Matrix *a, Matrix *b, Matrix *c);
};

#endif
