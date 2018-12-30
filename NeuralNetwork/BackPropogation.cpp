#include"NeuralNetwork.hpp"

void NeuralNetwork::backPropagation(){
  vector<Matrix *> weightsUpdated;
  Matrix *deltaWeights, *tempNewWeights, *pWeightsTransposed, *gradients, *gradientsTransposed, *pGradients, *DVals, *zActivatedVals;

  //OUTPUT->LAST HIDDEN LAYER
  
  int indexOutput  = this->topology.size() - 1;

  gradients = new Matrix(1,	this->topology.at(indexOutput));

  DVals = this->layers.at(indexOutput)->matrixifyVals('d');

  for(int i = 0; i < this->topology.at(indexOutput); i++) {
    double e  = this->derivedErrors.at(i);
    double y  = DVals->getValue(0, i);
    double g  = e * y;
    gradients->setValue(0, i, g);
  }

  // GRADIENT * Zact
  gradientsTransposed = gradients->transpose();
  zActivatedVals      = this->layers.at(indexOutput - 1)->matrixifyVals('a');

  deltaWeights  = new Matrix(	gradientsTransposed->getRows(),	zActivatedVals->getCols());

  Matrix::multiplyMatrix(gradientsTransposed, zActivatedVals, deltaWeights);

  //SET NEW WEIGHTS BETWEEN HIDDEN LAYERS
  tempNewWeights  = new Matrix(this->topology.at(indexOutput - 1),	this->topology.at(indexOutput));

  for(int row		= 0; row < this->topology.at(indexOutput - 1);	row++) {
    for(int col		= 0; col < this->topology.at(indexOutput);		col++) {

      double originalVal  = this->weightMatrices.at(indexOutput - 1)->getValue(row, col);
      double deltaVal     = deltaWeights->getValue(col, row);
      originalVal *= this->momentum;
      deltaVal    *= this->learningRate;
      
      tempNewWeights->setValue(row, col, (originalVal - deltaVal));
    }
  }

  weightsUpdated.push_back(new Matrix(*tempNewWeights));

  delete gradientsTransposed;
  delete zActivatedVals;
  delete tempNewWeights;
  delete deltaWeights;
  delete DVals;

  // HIDDEN TO INPUT LAYER
  
    Matrix *DHidden;
	Matrix *hiddenTransposed;
  
  for(int i = (indexOutput - 1); i > 0; i--) {
    pGradients  = new Matrix(*gradients);
    delete gradients;

    pWeightsTransposed  = this->weightMatrices.at(i)->transpose();

    gradients   = new Matrix(pGradients->getRows(),	pWeightsTransposed->getCols());

    Matrix::multiplyMatrix(pGradients, pWeightsTransposed, gradients);

    DHidden       = this->layers.at(i)->matrixifyVals('d');

    for(int colCounter = 0; colCounter < DHidden->getRows(); colCounter++) {
      double  g = gradients->getValue(0, colCounter) * DHidden->getValue(0, colCounter);
      gradients->setValue(0, colCounter, g);
    }

    if(i == 1) {
      zActivatedVals  = this->layers.at(0)->matrixifyVals();
    } else {
      zActivatedVals  = this->layers.at(0)->matrixifyVals('a');
    }

    hiddenTransposed  = zActivatedVals->transpose();

    deltaWeights      = new Matrix(hiddenTransposed->getRows(),	gradients->getCols());

    Matrix::multiplyMatrix(hiddenTransposed, gradients, deltaWeights);

    //NEW WEIGHTS
    tempNewWeights  = new Matrix(this->weightMatrices.at(i - 1)->getRows(),	this->weightMatrices.at(i - 1)->getCols());

    for(int row		= 0; row < tempNewWeights->getRows(); row++) {
      for(int col	= 0; col < tempNewWeights->getCols(); col++) {
        double originalVal  = this->weightMatrices.at(i - 1)->getValue(row, col);
        double deltaVal     = deltaWeights->getValue(row, col);

        originalVal	*= this->momentum;
        deltaVal	*= this->learningRate;
        
        tempNewWeights->setValue(row, col, (originalVal - deltaVal));
      }
    }

    weightsUpdated.push_back(new Matrix(*tempNewWeights));

    delete pGradients;
    delete pWeightsTransposed;
    delete DHidden;
    delete zActivatedVals;
    delete hiddenTransposed;
    delete tempNewWeights;
    delete deltaWeights;
  }

  for(int i = 0; i < this->weightMatrices.size(); i++) {
    delete this->weightMatrices[i];
  }

  this->weightMatrices.clear();

  reverse(weightsUpdated.begin(), weightsUpdated.end());

  for(int i = 0; i < weightsUpdated.size(); i++) {
    this->weightMatrices.push_back(new Matrix(*weightsUpdated[i]));
    delete weightsUpdated[i];
  }
}
